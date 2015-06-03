<?php

/**
 * @file
 * Admin page callbacks for the cod_schedule module.
 */

/**
 * Form constructor for the COD session room form.
 */
function cod_event_room_form($form, &$form_state, CodEventRoom $cod_event_room, $op = 'update', $node = NULL) {
  $form_state['cod_event_room'] = $cod_event_room;
  if (!isset($form_state['wrapper_callback'])) {
    $form_state['wrapper_callback'] = 'entity_ui_main_form_defaults';
  }
  $form_state['entity_type'] = 'cod_event_room';
  $form_state['op'] = $op;

  if ($op == 'clone') {
    $cod_event_room->name .= ' (cloned)';
  }

  $form['name'] = array(
    '#title' => t('Room Name'),
    '#type' => 'textfield',
    '#default_value' => $cod_event_room->name,
    '#description' => t('Name of the room.'),
    '#required' => TRUE,
    '#size' => 30,
  );
  $form['capacity'] = array(
    '#title' => t('Capacity'),
    '#type' => 'textfield',
    '#default_value' => $cod_event_room->capacity,
    '#description' => t('Total person capacity of a room.'),
    '#required' => FALSE,
    '#size' => 5,
  );

  field_attach_form('cod_event_room', $cod_event_room, $form, $form_state);
  $submit = array();
  if (!empty($form['#submit'])) {
    $submit += $form['#submit'];
  }

  if (isset($node) && is_object($node)) {
    $form['og_group_ref'][LANGUAGE_NONE][0]['default']['#default_value'] = $node->nid;
    $form['og_group_ref']['#access'] = FALSE;
  }

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save room'),
    '#submit' => $submit + array('cod_event_room_form_submit'),
    '#weight' => 40,
  );
  if (isset($node->nid)) {
    $form['actions']['submit']['#redirect'] = 'admin/conference/'.$node->nid.'/schedule';
  }
  $form['weight'] = array(
    '#type' => 'weight',
    '#title' => t('Weight'),
    '#default_value' => $cod_event_room->weight,
    '#description' => t('When showing rooms, those with lighter (smaller) weights get listed before rooms with heavier (larger) weights.'),
    '#weight' => 10,
  );
  if (!$cod_event_room->isLocked() && $op != 'add' && $op != 'clone') {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete room'),
      '#weight' => 45,
      '#limit_validation_errors' => array(),
      '#submit' => array('cod_event_room_form_submit_delete')
    );
  }

  return $form;
}

/**
 * Form API submit callback for the save button.
 */
function cod_event_room_form_submit(&$form, &$form_state) {
  $cod_event_room = entity_ui_form_submit_build_entity($form, $form_state);

  // Save and go back.
  $cod_event_room->save();
  if (isset($form_state['clicked_button']['#redirect'])) {
    $form_state['redirect'] = $form_state['clicked_button']['#redirect'];
  }
  else {
    $form_state['redirect'] = 'admin/conference/config/rooms';
  }

  drupal_set_message(t('The room %room was saved.', array('%room' => $cod_event_room->name)));
}

/**
* Form API submit callback for the delete button.
*/
function cod_event_room_form_submit_delete(&$form, &$form_state) {
  $evtrid = $form_state['cod_event_room']->evtrid;
  cod_event_room_delete($form_state['cod_event_room']);

  $form_state['redirect'] = "admin/conference/config/rooms/manage/$evtrid/delete";
}


/**
 * Form constructor for the COD session time form.
 */
function cod_event_time_form($form, &$form_state, CodEventTime $cod_event_time, $op = 'update', $node = NULL) {

  if (isset($node) && is_object($node) && !cod_schedule_days($node)) {
    drupal_set_message(l(t("You must first set a date for the event."), 'admin/conference/'.$node->nid.'/edit',array('fragment' => 'edit-field-dates')), 'warning');
    drupal_goto('admin/conference/'.$node->nid.'/schedule');
  }

  $form_state['cod_event_time'] = $cod_event_time;

  if (!isset($form_state['wrapper_callback'])) {
    $form_state['wrapper_callback'] = 'entity_ui_main_form_defaults';
  }
  $form_state['entity_type'] = 'cod_event_time';
  $form_state['op'] = $op;

  if ($op == 'clone') {
    $cod_event_time->date_label .= ' (cloned)';
  }

  $form['date_label'] = array(
    '#type' => 'value',
    '#value' => $cod_event_time->date_label,
  );

  field_attach_form('cod_event_time', $cod_event_time, $form, $form_state);
  if (isset($node->field_dates[LANGUAGE_NONE][0])) {
    //Set the default time to be closer to the event date.
    $form['field_evttime_date'][LANGUAGE_NONE][0]['#default_value']['value'] = $node->field_dates[LANGUAGE_NONE][0]['value'];
    $form['field_evttime_date'][LANGUAGE_NONE][0]['#default_value']['value2'] = $node->field_dates[LANGUAGE_NONE][0]['value']+3600;
    $form['field_evttime_date'][LANGUAGE_NONE][0]['timezone']['#type'] = 'value';
    $form['field_evttime_date'][LANGUAGE_NONE][0]['timezone']['#value'] = $node->field_dates[LANGUAGE_NONE][0]['timezone'];
  }

  if (isset($node) && is_object($node)) {
    $form['og_group_ref'][LANGUAGE_NONE][0]['default']['#default_value'] = $node->nid;
    $form['og_group_ref']['#access'] = FALSE;
  }

  $submit = array();
  if (!empty($form['#submit'])) {
    $submit += $form['#submit'];
  }

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save time'),
    '#submit' => $submit + array('cod_event_time_form_submit'),
    '#weight' => 40,
  );
  if (isset($node->nid)) {
    $form['actions']['submit']['#redirect'] = 'admin/conference/'.$node->nid.'/schedule';
  }

  if (!$cod_event_time->isLocked() && $op != 'add' && $op != 'clone') {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete time'),
      '#weight' => 45,
      '#limit_validation_errors' => array(),
      '#submit' => array('cod_event_time_form_submit_delete')
    );
  }

  return $form;
}


/**
 * Form API submit callback for the save button.
 */
function cod_event_time_form_submit(&$form, &$form_state) {
  $cod_event_time = entity_ui_form_submit_build_entity($form, $form_state);

  // Save and go back.
  $cod_event_time->save();
  if (isset($form_state['clicked_button']['#redirect'])) {
    $form_state['redirect'] = $form_state['clicked_button']['#redirect'];
  }
  else {
    $form_state['redirect'] = 'admin/conference/config/times';
  }
}

/**
* Form API submit callback for the delete button.
*/
function cod_event_time_form_submit_delete(&$form, &$form_state) {
  $evttid = $form_state['cod_event_time']->evttid;
  cod_event_time_delete($form_state['cod_event_time']);

  $form_state['redirect'] = "admin/conference/config/times/manage/$evttid/delete";
}

// --------------------------------------------------------------------------
// Various subforms for editing the pieces of a view.
// /admin/conference/NODEID/schedule/nojs/OPERATION/TIMEID/ROOMID
function cod_schedule_schedule_forms($key = NULL) {
  $forms = array(
    'edit' => array(
      'form_id' => 'cod_schedule_schedule_timeslot_form',
      'args' => array('fcid'),
    ),
    'add' => array(
      'form_id' => 'cod_schedule_add_form',
      'args' => array('nid', 'timeid', 'roomid'),
    ),
    'assign' => array(
      'form_id' => 'cod_schedule_timeslot_form',
      'args' => array('nid', 'fcid'),
    ),
  );

  if ($key) {
    return !empty($forms[$key]) ? $forms[$key] : NULL;
  }

  return $forms;
}

/**
 * COD Events modal form popup.
 */
function cod_schedule_schedule_timeslot_callback($js, $event, $key, $time, $room) {
  $field_name = 'field_event_timeslots';

  // Load the timeslot or stub a new one.
  if (!$timeslot = cod_schedule_timeslot_load_by_info($time, $room)) {
    $timeslot = cod_schedule_field_collection_item_add(str_replace('-', '_', $field_name), 'node', $event->nid, $time, $room);
    if (!is_object($timeslot) && ($timeslot == MENU_NOT_FOUND || $timeslot == MENU_ACCESS_DENIED)) {
      drupal_exit();
    }
  }

  // Check if js is enabled, this parameter will be loaded by ctools.
  if ($js) {
    module_load_include('inc', 'field_collection', 'field_collection.pages');

    // Include ctools ajax and modal, dont forget to set ajax TRUE.
    ctools_include('ajax');
    ctools_include('modal');
    $form_state = array(
      'ajax' => TRUE,
      'title' => t('Scheduleable items'),
      'build_info' => array(
        'args' => array($timeslot),
      ),
    );

    // Arguments need to be loaded directly onto the build_info args array
    // because ctools_modal_form_wrapper will call drupal_build_form()
    // directly see from API for more.
    // The modal form wrapper is needed to make sure the form will allow
    // validating, you cannot use drupal_get_form directly it wont work.
    if ($key == 'add' || $key == 'edit') {
      $output = ctools_modal_form_wrapper('field_collection_item_form', $form_state);
    }
    elseif ($key == 'delete') {
      $output = ctools_modal_form_wrapper('field_collection_item_delete_confirm', $form_state);
    }
    else {
      drupal_exit();
    }

    // If the form is executed will need to dismiss the form and reload the page.
    if ($form_state['executed']) {
      $commands = array();

      // Set the updated schedule item and close the ctools modal.
      $commands[] = ajax_command_replace('#cod-events-schedule-timeslot-' . $time . '-' . $room, cod_schedule_schedule_grid_item($event, $time, $room, TRUE));
      $commands[] = ctools_modal_command_dismiss();

      $output = $commands;
    }

    // Render the output.
    print ajax_render($output);
    drupal_exit();
  }
  else {
    // No js found lets go to the default page.
    return drupal_get_form('field_collection_item_form', $timeslot);
  }
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function cod_schedule_form_field_collection_item_form_alter(&$form, &$form_state) {
  if (isset($form_state['field_collection_item']->field_timeslot_time)) {
    $form['field_timeslot_time'][LANGUAGE_NONE][0]['#default_value'] = $form_state['field_collection_item']->field_timeslot_time;
    $form['field_timeslot_time']['#access'] = FALSE;
  }
  if (isset($form_state['field_collection_item']->field_timeslot_room)) {
    $form['field_timeslot_room'][LANGUAGE_NONE][0]['#default_value'] = $form_state['field_collection_item']->field_timeslot_room;
    $form['field_timeslot_room']['#access'] = FALSE;
  }
}

/**
 * Add a new field-collection item.
 *
 * We copied this function from the field collection module but instead of returning a form we return the object
 */
function cod_schedule_field_collection_item_add($field_name, $entity_type, $entity_id, $time, $room, $allowed_types = NULL, $langcode = NULL) {
  $info = entity_get_info();
  if (!isset($info[$entity_type])) {
    return MENU_NOT_FOUND;
  }
  $result = entity_load($entity_type, array($entity_id));

  $entity = reset($result);

  if (!$entity) {
    return MENU_NOT_FOUND;
  }
  // Ensure the given entity is of a bundle that has an instance of the field.
  list($id, $rev_id, $bundle) = entity_extract_ids($entity_type, $entity);
  $instance = field_info_instance($entity_type, $field_name, $bundle);

  if (!$instance) {
    return MENU_NOT_FOUND;
  }

  // Check field cardinality.
  $field = field_info_field($field_name);
  $langcode = LANGUAGE_NONE;
  if (!($field['cardinality'] == FIELD_CARDINALITY_UNLIMITED || !isset($entity->{$field_name}[$langcode]) || count($entity->{$field_name}[$langcode]) < $field['cardinality'])) {
    drupal_set_message(t('Too many items.'), 'error');
    return '';
  }

  $title = ($field['cardinality'] == 1) ? $instance['label'] : t('Add new !instance_label', array('!instance_label' => drupal_strtolower($instance['label'])));

  drupal_set_title($title);

  $stub = array(
    'field_name' => $field_name,
    'field_timeslot_time' => array($langcode => array(array('target_id' => $time))),
    'field_timeslot_room' => array($langcode => array(array('target_id' => $room))),
    'field_timeslot_allowed_types' => array($langcode => array(array('value' => $allowed_types))),
  );

  $field_collection_item = entity_create('field_collection_item', $stub);
  // Do not link the field-collection item with the host entity at this point,
  // as during the form-workflow we have multiple field-collection item entity
  // instances, which we don't want link all with the host.
  // That way the link is going to be created when the item is saved.
  $field_collection_item->setHostEntity($entity_type, $entity, $langcode, FALSE);
  // Make sure the current user has access to create a field collection item.
  if (!field_collection_item_access('create', $field_collection_item)) {
    return MENU_ACCESS_DENIED;
  }

  return $field_collection_item;
}


/**
 * Helper function to generate a sceduler grid item.
 */
function cod_schedule_schedule_grid_item($event, $time, $room, $reset = FALSE, $schedule_items) {
  // @TODO We need to pass the cid on with ajax so we can invalidate the cache
  $cid = 'cod_schedule:schedule_grid_item:' . $time . ':' . $room;
  $grid = cache_get($cid);

  if (!isset($grid->data) || $reset) {
    $items = array();
    $sessions = array();

    if ($timeslot = cod_schedule_timeslot_load_by_info($time, $room)) {

      if(isset($schedule_items[$timeslot->item_id])) {
        foreach($schedule_items[$timeslot->item_id] as $session) {
          $sessions[] = array(
            'data' => l( t($session->extraFields->title), 'node/' . $session->nid),
            'data-nid' => $session->nid,
          );
        }
      }


      $op = 'edit';
      /*
       * @TODO (Connerton) I don't think we need this if we turn the "edit timeslot" link into a gear contextual link
      if (isset($timeslot->field_timeslot_allowed_types[LANGUAGE_NONE])) {
        foreach ($timeslot->field_timeslot_allowed_types[LANGUAGE_NONE] as $type) {
          $items[]['data'] = node_type_get_name($type['value']);
        }
      }
      */
    }
    else {
      $op = 'add';
    }

    // (Connerton) If there are no session in a timeslot, then the ul element won't even render. This makes sure that happens
    // However it produces an empty <li class="first last"></li> which doesn't seem to hurt anything. Not sure how I
    // feel about that....
    if(empty($sessions)) {
      $sessions[] = array('data' => '');
    }

    // Generate the appropriate link for this timeslot.
    $items[] = array(
      'title' => t('@op timeslot', array('@op' => ucwords($op))),
      'href' => 'admin/conference/' . $event->nid . '/schedule/nojs/' . $op . '/' . $time .'/' . $room,
      'attributes' => array('class' => 'ctools-use-modal'),
    );

    $output = array(
      'dropdown' => array(
        '#links' => $items,
        '#theme' => 'ctools_dropdown',
      ),
      'sessions' => array(
        '#items' => $sessions,
        '#theme' => 'item_list',
        '#attributes' => array(
          'id' => 'cod-events-schedule-sessions-' . $time . '-' . $room,
          'class' => 'sortable-sessions',
          'data-timeslot' =>  isset($timeslot->item_id) ? $timeslot->item_id : 'NEW',
        ),
      ),
    );
    /*   Link to the Ctools modal.
     *             '#items' => $items,
                 '#theme' => 'item_list',
                 '#attributes' => array(
                   'id' => 'cod-events-schedule-timeslot-' . $time . '-' . $room,
                 ),
     */

    cache_set($cid, $output);
    return $output;
  }

  return $grid->output;
}
