<?php

/**
 * @file
 * OG Commons groups selection handler.
 */

class OgEventsSelectionHandler extends OgSelectionHandler {

  public static function getInstance($field, $instance = NULL, $entity_type = NULL, $entity = NULL) {
    return new self($field, $instance, $entity_type, $entity);
  }

  /**
   * Overrides OgSelectionHandler::buildEntityFieldQuery().
   */
  public function buildEntityFieldQuery($match = NULL, $match_operator = 'CONTAINS') {
    $group_type = $this->field['settings']['target_type'];

    // See if the Entity allows for non-member postings
    $user_access = FALSE;
    $event = NULL;
    if ($this->entity && isset($this->entity->og_group_ref[LANGUAGE_NONE][0]['target_id'])) {
      $event = $this->entity->og_group_ref[LANGUAGE_NONE][0]['target_id'];
    }
    // We need to grab the session directly because it hasn't been saved statically yet.
    elseif (module_exists('og_context') && isset($_SESSION)) {
      $event = isset($_SESSION['og_context']) ? $_SESSION['og_context'] : og_context('node');
      $event = isset($event['gid']) ? $event['gid'] : NULL;
    }
    if ($event) {
      $user_access = og_user_access('node', $event, "create " . $this->instance['bundle'] . " content") || og_user_access('node', $event, "update own " . $this->instance['bundle'] . " content") || og_user_access('node', $event, "edit any " . $this->instance['bundle'] . " content");
    }

    if (empty($this->instance['field_mode'])
      || $group_type != 'node'
      || user_is_anonymous()
      || !$user_access) {
      return parent::buildEntityFieldQuery($match, $match_operator);
    }

    $handler = EntityReference_SelectionHandler_Generic::getInstance($this->field, $this->instance, $this->entity_type, $this->entity);
    $query = $handler->buildEntityFieldQuery($match, $match_operator);

    // Show only the entities that are active groups.
    $query->fieldCondition(OG_GROUP_FIELD, 'value', 1);

    // Add this property to make sure we will have the {node} table later on in
    // OgCommonsSelectionHandler::entityFieldQueryAlter().
    $query->propertyCondition('nid', 0, '>');

    $query->addMetaData('entityreference_selection_handler', $this);

    // FIXME: http://drupal.org/node/1325628
    unset($query->tags['node_access']);

    $query->addTag('entity_field_access');
    $query->addTag('og');

    return $query;
  }

  /**
   * Overrides OgSelectionHandler::entityFieldQueryAlter().
   *
   * Add the user's groups along with the rest of the "public" groups.
   */
  public function entityFieldQueryAlter(SelectQueryInterface $query) {
    $gids = og_get_entity_groups();
    if (empty($gids['node'])) {
      return;
    }

    $conditions = &$query->conditions();
    // Find the condition for the "field_data_field_privacy_settings" query, and
    // the one for the "node.nid", so we can later db_or() them.
    $public_condition = array();
    foreach ($conditions as $key => $condition) {
      if ($key !== '#conjunction' && is_string($condition['field'])) {
        if (strpos($condition['field'], 'field_data_field_og_subscribe_settings') === 0) {
          $public_condition = $condition;
          unset($conditions[$key]);
        }

        if ($condition['field'] === 'node.nid') {
          unset($conditions[$key]);
        }
      }
    }

    if (!$public_condition) {
      return;
    }

    $or = db_or();
    $or->condition($public_condition['field'], $public_condition['value'], $public_condition['operator']);
    $or->condition('node.nid', $gids['node'], 'IN');
    $query->condition($or);
  }
}
