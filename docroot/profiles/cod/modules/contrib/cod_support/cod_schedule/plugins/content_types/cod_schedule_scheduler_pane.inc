<?php
/**
* This plugin array is more or less self documenting
*/
$plugin = array(
  // the title in the admin
  'title' => t('Scheduler Pane'),
  // no one knows if "single" defaults to FALSE...
  'single' => TRUE,
  // oh joy, I get my own section of panel panes
  'category' => array(t('Conference Organizing'), -9),
  //'edit form' => 'cod_events_pane_content_type_edit_form',
  'render callback' => 'cod_schedule_pane_scheduler_render'
);


/**
* Run-time rendering of the body of the block (content type)
* See ctools_plugin_examples for more advanced info
*/
function cod_schedule_pane_scheduler_render($subtype, $conf, $context = NULL) {
  // our output is generate by js. Any markup or theme functions
  // could go here.
  // that private js function is so bad that fixing it will be the
  // basis of the next tutorial
  $block = new stdClass();
  $block->title = t('Room/Timeslot Scheduler');

  if($event = node_load(array_shift($context))) {
    $block->content = cod_schedule_schedule_admin_page($event);
  } else {
    $block->content = t('Invalid Event Type');
  }
  return $block;
}


function cod_schedule_schedule_admin_page($node) {
  module_load_include('inc', 'cod_schedule', 'includes/schedule.admin');

  // Grab the days.
  $days = cod_schedule_days($node);
  if (empty($days)) {
    return t('Your event must have a <a href="@edit">start and end date</a>. <a href="@edit">Edit</a> event.', array('@edit' => url('node/'.$node->nid.'/edit', array('fragment' => 'edit-field-dates', 'query' => array('destination' => 'admin/conference/' . $node->nid . '/schedule')))));
  }

  // Grab the Rooms attached to the event.
  $room_query = new EntityFieldQueryExtraFields();
  $rooms = $room_query->entityCondition('entity_type', 'cod_event_room')
    ->addExtraField('', 'name', 'name', 'cod_event_room')
    ->fieldCondition('og_group_ref', 'target_id', $node->nid)
    // TODO: Weight property isn't fully coded.
    // ->propertyOrderby('weight')
    ->execute();

  // Provide feedback to help administrators setup the site.
  if (empty($rooms)) {
    return t('You must add a room to view the schedule.');
  }

  $session_query = new EntityFieldQueryExtraFields();
  $sessions = $session_query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', array('session', 'bof_session', 'schedule_item'), 'IN')
    ->fieldCondition('og_group_ref', 'target_id', $node->nid)
    ->addExtraField('', 'title', 'title', 'node')
    ->execute();

  if (!empty($sessions)) {
    $sessions = $sessions['node'];
  }

  $fields = field_info_instances('node', 'session');
  $field_id = $fields['field_session_timeslot']['field_id'];
  field_attach_load('node', $sessions, FIELD_LOAD_CURRENT, array('field_id' => $field_id));

  $schedule_items = array();
  foreach($sessions as $session) {
    if(!empty($session->field_session_timeslot)) {
      // @TODO We understand that this does not support multiple timeslots for a session or multilingual. We will fix that
      // with the next patch and more discussion.
      $schedule_items[ $session->field_session_timeslot['und'][0]['target_id'] ][] = $session;
    }
  }

  // Create the table for each day.
  foreach ($days as $weight => $day) {
    $tz = new DateTimeZone($node->field_dates[LANGUAGE_NONE][0]['timezone']);
    $tz_db = new DateTimeZone($node->field_dates[LANGUAGE_NONE][0]['timezone_db']);

    $tz_time_db = new DateTime("now", $tz_db);
    $tz_time = new DateTime("now", $tz);

    // Get opposite of the offset.
    $offset = $tz->getOffset($tz_time_db) * -1;

    $day_start = strtotime($day . ' 00:00:00') + $offset;
    $day_end = strtotime('+1 day', $day_start);

    $time_query = new EntityFieldQueryExtraFields();
    $times = $time_query->entityCondition('entity_type', 'cod_event_time')
      ->addExtraField('', 'date_label', 'date_label', 'cod_event_time')
      ->fieldCondition('og_group_ref', 'target_id', $node->nid)
      ->fieldCondition('field_evttime_date', 'value', format_date($day_start, 'custom', 'Y-m-d H:i:s'), '>=')
      ->fieldCondition('field_evttime_date', 'value2', format_date($day_end, 'custom', 'Y-m-d H:i:s'), '<=')
      ->fieldOrderBy('field_evttime_date', 'value')
      ->execute();
    $header = array(t('Time'));
    $rows = array();

    if (isset($times['cod_event_time'])) {
      foreach ($times['cod_event_time'] as $evttid => $time) {
        $time_entity = entity_load('cod_event_time', array($evttid));
        $time_label = $time_entity[$evttid]->getTimeLabel();
        $time_edit_uri = 'admin/conference/config/times/manage/' . $evttid;
        $row = array(
          array(
            'data' => l($time_label, $time_edit_uri, array('query' => array('destination' => 'admin/conference/'.$node->nid.'/schedule'))),
            'class' => 'cod-schedule-time-column',
          )
        );

        foreach ($rooms['cod_event_room'] as $roomid => $room) {
          if (empty($rows)) {
            $room_label = $room->extraFields->name;
            $room_edit_uri = 'admin/conference/config/rooms/manage/' . $roomid;
            $header[] = l($room_label, $room_edit_uri, array('query' => array('destination' => 'admin/conference/'.$node->nid.'/schedule')));
          }

          // @TODO Cache reset var is manually set to TRUE until we invalidate the cache when a schedule item is updated
          $output = cod_schedule_schedule_grid_item($node, $evttid, $roomid, TRUE, $schedule_items);
          $row[] = array(
            'data' => drupal_render($output),
          );
        }
        $rows[] = $row;
      }
    }

    // Add help content to empty tabs.
    if (empty($rows)) {
      $contents =  t('Add a time to build a schedule for this day.');
    }
    else {
      $contents = theme('table', array('header' => $header, 'rows' => $rows));
    }

    $content_tabs[] = array(
      'title' => $day,
      'contents' => $contents,
      'weight' => $weight,
    );
  }

  ctools_include('modal');
  ctools_modal_add_js();
  drupal_add_library('system', 'ui.sortable');
  drupal_add_js(drupal_get_path('module', 'cod_schedule') .'/js/cod_schedule.js');
  $overrides = array('ajax' => 0, 'style' => 'Zen'); // Override some of the settings for the QT instance.
  $quicktabs = quicktabs_build_quicktabs('cod_schedule_schedule_builder', $overrides, $content_tabs);
  return drupal_render($quicktabs['content']);
}
