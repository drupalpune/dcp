<?php
/**
* This plugin array is more or less self documenting
*/
$plugin = array(
  // the title in the admin
  'title' => t('Unscheduled Sessions Pane'),
  // no one knows if "single" defaults to FALSE...
  'single' => TRUE,
  // oh joy, I get my own section of panel panes
  'category' => array(t('Conference Organizing'), -9),
  //'edit form' => 'cod_events_pane_content_type_edit_form',
  'render callback' => 'cod_schedule_pane_sessions_render'
);


/**
* Run-time rendering of the body of the block (content type)
* See ctools_plugin_examples for more advanced info
*/
function cod_schedule_pane_sessions_render($subtype, $conf, $context = NULL) {
  // our output is generate by js. Any markup or theme functions
  // could go here.
  // that private js function is so bad that fixing it will be the
  // basis of the next tutorial
  $block = new stdClass();
  $block->title = t('Accepted, Unscheduled Sessions');

  if($event = node_load(array_shift($context))) {
    $block->content = cod_schedule_sessions_admin_page($event);
  } else {
    $block->content = t('Invalid Event Type');
  }
  return $block;
}

/**
 * Build the pane's content of the unprocessed sessions for an event.
 *
 * @param $node
 * @return string
 */
function cod_schedule_sessions_admin_page($node) {

  // Get the unprocessed sessions.
  $sessions = cod_schedule_get_unscheduled_sessions($node->nid);
  $session_items = array();

  // Build the UL element of sessions.
  if($sessions) {
    foreach($sessions as $nid => $session) {
      $session_items[] = array(
        'data' => l($session->extraFields->title, 'node/' . $session->nid),
        'data-nid' => $session->nid,
      );
    }
  }

  if(empty($session_items)) {
    $session_items[] = '';
  }

  // Build the render array.
  $content = array(
    '#theme' => 'item_list',
    '#items' => $session_items,
    '#attributes' => array(
      'class' => array(
        'sortable-sessions'
      ),
    ),
    '#attached' => array(
      'css' => array(
        drupal_get_path('module', 'cod_schedule') . '/css/cod_schedule.css'
      )
    ),
  );

  return $content;
}

/**
 * Returns all sessions without a time slot.
 * The results are not fully instantiated entities, just the required fields for performance.
 *
 * @param int $event_id
 * @return array Returns an array of entities keyed on the entity Id.
 */
function cod_schedule_get_unscheduled_sessions($event_id) {
  $query = new EntityFieldQueryExtraFields();
  $query->entityCondition('entity_type', 'node');
  $query->entityCondition('bundle', 'session');
  // Get just the Title.
  $query->addExtraField('', 'title', 'title', 'node');
  // Where is published.
  $query->propertyCondition('status', '1');
  // Where sessions are accepted.
  $query->fieldCondition('field_accepted', 'value', 'accepted', '=');
  $query->addTag('session_no_time_slot');
  // Where event id is $event_id.
  $query->fieldCondition('og_group_ref', 'target_id', $event_id);
  // Order by the title ASC.
  $query->propertyOrderBy('title');
  // Get the results of the query.
  $results = $query->execute();

  return (!isset($results['node'])
    ? null
    : $results['node']);
}

function cod_schedule_query_session_no_time_slot_alter(QueryAlterableInterface $query) {
  $test = '';
  $query->leftJoin('field_data_field_session_timeslot', 't', 'node.nid = t.entity_id');
  $query->isNull('t.field_session_timeslot_target_id');
}
