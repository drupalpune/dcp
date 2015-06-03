<?php

/**
 * Entity handler for Views.
 */
class CodTimeSlot_SelectionHandler_Views extends EntityReference_SelectionHandler_Views {

  /**
   * Implements EntityReferenceHandler::getInstance().
   */
  public static function getInstance($field, $instance = NULL, $entity_type = NULL, $entity = NULL) {
    return new self($field, $instance, $entity_type, $entity);
  }

  protected function __construct($field, $instance, $entity_type, $entity) {
    $this->field = $field;
    $this->instance = $instance;
    $this->entity_type = $entity_type;
    $this->entity = $entity;
    $this->event_id = $this->getEventId($entity) ? $this->getEventId($entity) : 0;
  }

  /**
   * Implements EntityReferenceHandler::settingsForm().
   */
  public static function settingsForm($field, $instance) {
    $view_settings = empty($field['settings']['handler_settings']['view']) ? '' : $field['settings']['handler_settings']['view'];
    $displays = views_get_applicable_views('entityreference display');
    // Filter views that list the entity type we want, and group the separate
    // displays by view.
    $entity_info = entity_get_info($field['settings']['target_type']);
    $options = array();
    foreach ($displays as $data) {
      list($view, $display_id) = $data;
      if ($view->base_table == $entity_info['base table']) {
        $options[$view->name . ':' . $display_id] = $view->name . ' - ' . $view->display[$display_id]->display_title;
      }
    }

    // The value of the 'view_and_display' select below will need to be split
    // into 'view_name' and 'view_display' in the final submitted values, so
    // we massage the data at validate time on the wrapping element (not
    // ideal).
    $form['view']['#element_validate'] = array('entityreference_view_settings_validate');

    if ($options) {
      $default = !empty($view_settings['view_name']) ? $view_settings['view_name'] . ':' . $view_settings['display_name'] : NULL;
      $form['view']['view_and_display'] = array(
        '#type' => 'select',
        '#title' => t('View used to select the entities'),
        '#required' => TRUE,
        '#options' => $options,
        '#default_value' => $default,
        '#description' => '<p>' . t('Choose the view and display that select the entities that can be referenced.<br />Only views with a display of type "Entity Reference" are eligible.') . '</p>',
      );

      $default = !empty($view_settings['args']) ? implode(', ', $view_settings['args']) : '';
      $form['view']['args'] = array(
        '#type' => 'textfield',
        '#title' => t('View arguments'),
        '#default_value' => $default,
        '#required' => FALSE,
        '#description' => t('Provide a comma separated list of arguments to pass to the view.'),
      );
    }
    else {
      $form['view']['no_view_help'] = array(
        '#markup' => '<p>' . t('No eligible views were found. <a href="@create">Create a view</a> with an <em>Entity Reference</em> display, or add such a display to an <a href="@existing">existing view</a>.', array(
          '@create' => url('admin/structure/views/add'),
          '@existing' => url('admin/structure/views'),
        )) . '</p>',
      );
    }
    return $form;
  }

  /**
   * Attempt to get the Event ID. Input will be an entity with an og_group_ref
   * Or it will be a new entity w/o a node and we will need to use og_context.
   * @param null $entity
   *
   */
  protected function getEventId($entity = NULL) {
    if (isset($entity->og_group_ref)) {
      return $entity->og_group_ref[LANGUAGE_NONE][0]['target_id'];
    }
    else {
      $event_id = og_context();
      if (!empty($event_id)) {
        $event_id['gid'];
      }
    }
    return;
  }

  protected function initializeView($match = NULL, $match_operator = 'CONTAINS', $limit = 0, $ids = NULL) {
    if (!$this->event_id || !$this->entity) {
      return FALSE;
    }
    $view_name = $this->field['settings']['handler_settings']['view']['view_name'];
    $display_name = $this->field['settings']['handler_settings']['view']['display_name'];
    $args = array($this->event_id, $this->entity->type);
    $entity_type = $this->field['settings']['target_type'];

    // Check that the view is valid and the display still exists.
    $this->view = views_get_view($view_name);
    if (!$this->view || !isset($this->view->display[$display_name]) || !$this->view->access($display_name)) {
      watchdog('entityreference', 'The view %view_name is no longer eligible for the %field_name field.', array('%view_name' => $view_name, '%field_name' => $this->instance['label']), WATCHDOG_WARNING);
      return FALSE;
    }
    $this->view->set_display($display_name);

    // Make sure the query is not cached.
    $this->view->is_cacheable = FALSE;

    // Pass options to the display handler to make them available later.
    $entityreference_options = array(
      'match' => $match,
      'match_operator' => $match_operator,
      'limit' => $limit,
      'ids' => $ids,
    );
    $this->view->display_handler->set_option('entityreference_options', $entityreference_options);
    return TRUE;
  }

  /**
   * Implements EntityReferenceHandler::getReferencableEntities().
   */
  public function getReferencableEntities($match = NULL, $match_operator = 'CONTAINS', $limit = 0) {
    if (!$this->event_id || !$this->entity) {
      return array();
    }

    $event_nid = $this->event_id;
    $bundle = $this->entity->type;
    $display_name = $this->field['settings']['handler_settings']['view']['display_name'];
    $args = array($event_nid, $bundle);
    $result = array();
    if ($this->initializeView($match, $match_operator, $limit)) {
      // Get the results.
      $result = $this->view->execute_display($display_name, $args);
    }

    $return = array();
    if ($result) {
      $target_type = $this->field['settings']['target_type'];
      $entities = entity_load($target_type, array_keys($result));
      foreach($entities as $entity) {
        list($id,, $bundle) = entity_extract_ids($target_type, $entity);
        $return[$bundle][$id] = $result[$id];
      }
    }
    return $return;
  }

  /**
   * Implements EntityReferenceHandler::countReferencableEntities().
   */
  function countReferencableEntities($match = NULL, $match_operator = 'CONTAINS') {
    $this->getReferencableEntities($match, $match_operator);
    return $this->view->total_items;
  }

  function validateReferencableEntities(array $ids) {
    $display_name = $this->field['settings']['handler_settings']['view']['display_name'];
    $args = array($this->event_id, $this->entity->type);
    $result = array();
    if ($this->initializeView(NULL, 'CONTAINS', 0, $ids)) {
      // Get the results.
      $entities = $this->view->execute_display($display_name, $args);
      $result = array_keys($entities);
    }
    return $result;
  }

  /**
   * Implements EntityReferenceHandler::validateAutocompleteInput().
   */
  public function validateAutocompleteInput($input, &$element, &$form_state, $form) {
    return NULL;
  }

  /**
   * Implements EntityReferenceHandler::getLabel().
   */
  public function getLabel($entity) {
    return entity_label($this->field['settings']['target_type'], $entity);
  }

  /**
   * Implements EntityReferenceHandler::entityFieldQueryAlter().
   */
  public function entityFieldQueryAlter(SelectQueryInterface $query) {

  }

}
