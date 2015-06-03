<?php

/**
 * Redirect page callback, to keep the url API compatible with prod.
 */
function ticket_reservation_redeem_redirect($code = '') {
  drupal_goto('ticket/nojs/redeem/code/' . $code);
}

/**
 * Page callback: Handles multistep precessing.
 *
 * @return string
 *   Multistep wizard output.
 *
 * @see ticket_reservation_menu()
 */
function ticket_reservation_redeem_form($js = NULL, $step = NULL, $code = NULL) {
  if (!empty($step) && ($step != 'code' && $step != 'registration')) {
    return drupal_not_found();
  }

  global $user;
  if ($js) {
    ctools_include('modal');
    ctools_include('ajax');
  }

  // Define array for ctools multistep wizard.
  $form_info = array(
    'id' => 'ticket_reservation_redeem',
    'path' => "ticket/" . ($js ? 'ajax' : 'nojs') . "/redeem/%step",
    'show trail' => TRUE,
    'show back' => TRUE,
    'show cancel' => TRUE,
    'show return' => FALSE,
    'next callback' =>  'ticket_reservation_wizard_next',
    'finish callback' => 'ticket_reservation_wizard_finish',
    'cancel callback' => 'ticket_reservation_wizard_cancel',

   // Define forms order.
    'order' => array(
      'code' => t('Enter your redemption code'),
      'registration' => t('Registration details'),
    ),

   // Define forms
    'forms' => array(
      'code' => array(
        'form id' => 'ticket_reservation_form_code'
      ),
      'registration' => array(
        'form id' => 'ticket_reservation_form_registration'
      ),
    ),
  );

  // We're not using any real storage here, so we're going to set our
  // object_id to 1. When using wizard forms, id management turns
  // out to be one of the hardest parts. Editing an object with an id
  // is easy, but new objects don't usually have ids until somewhere
  // in creation.
  //
  // We skip all this here by just using an id of 1.
  $object_id = 1;

  if (empty($step)) {

    // We reset the form when $step is NULL because that means they have
    // for whatever reason started over.
    ticket_reservation_cache_clear($object_id);
    $step = 'code';
  }

  // This automatically gets defaults if there wasn't anything saved.
  $object = ticket_reservation_cache_get($object_id);

  // live $form_state changes.
  $form_state = array(
    'ajax' => $js,

    // Put our object and ID into the form state cache so we can easily find it.
    'object_id' => $object_id,
    'object' => &$object,

    // Add our additional details for the ticket
    'user_uid' => $user,
    'redeem_code' => check_plain($code),
  );

  // Send this all off to our form. This is like drupal_get_form only wizardy.
  ctools_include('wizard');
  $form = ctools_wizard_multistep_form($form_info, $step, $form_state);
  $output = drupal_render($form);
  if ($js) {

    // If javascript is active, we have to use a render array.
    $commands = array();
    if ($output === FALSE || !empty($form_state['complete'])) {
      // Dismiss the modal.
      //$commands[] = ajax_command_html('#ctools-sample', render(ticket_reservation_get_result($object)));
      $commands[] = ctools_modal_command_dismiss();
    }
    elseif (!empty($form_state['cancel'])) {

      // If cancelling, return to the activity.
      $commands[] = ctools_modal_command_dismiss();
    }
    else {
      $commands = ctools_modal_form_render($form_state, $output);
    }
    print ajax_render($commands);
  }
  else {
    if ($output === FALSE || !empty($form_state['complete'])) {
      drupal_goto('user/'. $user->uid . '/tickets');
      //return render(ticket_reservation_get_result($object)) . "\n\r" . l(t('Back'), $user->uid . '/tickets');
    }
    elseif (!empty($form_state['cancel'])) {
      drupal_goto('user/'. $user->uid . '/tickets');
    }
    else {
      return $output;
    }
  }
}

/**
 * Clears the wizard cache.
 *
 * @param integer $id
 *   cache id.
 */
function ticket_reservation_cache_clear($id) {
  ctools_include('object-cache');
  ctools_object_cache_clear('ticket_reservation_redeem', $id);
}

/**
 * Stores our little cache so that we can retain data from form to form.
 *
 * @param integer $id
 *   cache id.
 * @param object $object
 *   object with form values.
 */
function ticket_reservation_cache_set($id, $object) {
  ctools_include('object-cache');
  ctools_object_cache_set('ticket_reservation_redeem', $id, $object);
}

/**
 * Gets the current object from the cache, or default.
 *
 * @param integer $id
 *   cache id.
 *
 * @return object
 *   cache with stored stuff.
 */
function ticket_reservation_cache_get($id) {
  ctools_include('object-cache');
  $object = ctools_object_cache_get('ticket_reservation_redeem', $id);
  if (!$object) {
    // Create a default object.
    $object = new stdClass;
  }

  return $object;
}

/**
 * Handles the 'next' click on the add/edit pane form wizard.
 *
 * All we need to do is store the updated pane in the cache.
 */
function ticket_reservation_wizard_next(&$form_state) {
  ticket_reservation_cache_set($form_state['object_id'], $form_state['object']);
}

/**
 * Handles the 'finish' click on teh add/edit pane form wizard.
 *
 * All we need to do is set a flag so the return can handle adding
 * the pane.
 */
function ticket_reservation_wizard_finish(&$form_state) {
  $form_state['complete'] = TRUE;
}

/**
 * Handles the 'cancel' click on the add/edit pane form wizard.
 */
function ticket_reservation_wizard_cancel(&$form_state) {
  $form_state['cancel'] = TRUE;
}

/**
 * Generates first form.
 *
 * @ingroup forms
 */
function ticket_reservation_form_code($form, &$form_state) {
  $account = $form_state['user_uid'];
  $code = isset($form_state['redeem_code']) ? $form_state['redeem_code'] : '';

  // Start with some default values for the redemption page.
  $form['user_uid'] = array(
    '#type' => 'value',
    '#value' => 0,
  );

  $form['code'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter your Reservation Code'),
    '#default_value' => $code,
    '#size' => 32,
    '#maxlength' => 12,
    '#required' => TRUE,
  );

  // Set the mail form field defaults.
  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter an account or email address that will use this ticket'),
    '#default_value' => $form_state['user_uid']->name,
    '#size' => 64,
    '#required' => TRUE,
  );
  if ($reservation = ticket_reservation_fetch_code($code)) {
    $ticket_registration = ticket_registration_load($reservation['trid']);

    // Establish which account should be assigned this ticket
    // If the registration already has a user_uid, default to that.
    // Note, ticket redeem access should deny this if the user doesn't match the
    // user that already exists on the ticket.
    if ($ticket_registration->user_uid != 0 && $account->uid != $ticket_registration->author_uid) {
      $form['registration_name'] = array(
        '#markup' => t('Registering as %user', array('%user' => $account->name)),
        '#weight' => -101,
      );
      $form['name']['#type'] = 'value';
    }
    // If the registration id is null and no mail was sent out, it was a placeholder
    // ticket. Allow the owner to edit tickets they own that aren't assigned.
    else if ($account->uid == $ticket_registration->author_uid && $ticket_registration->user_uid != 0) {
      $user_account = user_load($ticket_registration->user_uid);
      $form['name']['#default_value'] = $user_account->name;
    }
    else if (isset($reservation['mail'])) {
      $form['name']['#default_value'] = $reservation['mail'];
    }
  }

  return $form;
}

function ticket_reservation_form_code_validate($form, &$form_state) {
    //fetch the username or email address. I don't like this but its what logintoboggin uses.
  $name = '';
  if (isset($form_state['values']['name']) && $form_state['values']['name'] && $form_state['values']['user_uid'] == 0) {
    if ($name = db_query("SELECT name FROM {users} WHERE LOWER(mail) = LOWER(:name)", array(
      ':name' => $form_state['values']['name'],
    ))->fetchField()) {
      form_set_value($form['name'], $name, $form_state);
    }
    else {
      $name = $form_state['values']['name'];
    }
    $account = user_load_by_name($name);
    if (!isset($account->uid)) {
      form_set_error('ticket_reservation_redeem', "Account email or username does not exist.");
      return;
    }
    else {
      form_set_value($form['user_uid'], $account->uid, $form_state);
    }
  }

  if ($result = ticket_reservation_fetch_code($form_state['values']['code'])) {
    $form_state['#ticket_registration'] = ticket_registration_load($result['trid']);
    $registration = $form_state['#ticket_registration'];
    if ($result['created'] != 0 && $result['created'] < $registration->changed) {
      form_set_error('ticket_reservation_redeem', "This code is not valid");
    }
    if ($registration->user_uid != 0 && ($registration->author_uid != $form_state['values']['user_uid'] && $registration->user_uid != $form_state['values']['user_uid'])) {
      form_set_error('ticket_reservation_redeem', "This code belongs to a specific user and can only be redeemed by that user");
    }
  }
  else {
    form_set_error('ticket_reservation_redeem', "Code not found. Please check the code and try again.");
  }
}
/**
 * Handles submit of first form.
 */
function ticket_reservation_form_code_submit($form, &$form_state) {

  if ($result = ticket_reservation_fetch_code($form_state['values']['code'])) {
    $registration = ticket_registration_load($result['trid']);
    if ($registration->author_uid == 0) {
      $registration->author_uid = $form_state['user_uid']->uid;
    }
    if ($form_state['values']['user_uid'] != 0) {
      $registration->user_uid = $form_state['values']['user_uid'];
    }
    else {
      $registration->user_uid = $form_state['user_uid']->uid;
    }

    // Save values to the form storage, add the next step function callback
    $form_state['object']->registration = $registration;
    $form_state['object']->reservation = $result;

    drupal_set_message("Please fill out the following registration details.");
  }
}

/**
 * Generates second form.
 *
 * @ingroup forms
 */
function ticket_reservation_form_registration($form, &$form_state) {

  // Attach the fields for this ticket registration.
  $form_state['entity_type'] = 'ticket_registration';
  $form_state['ticket_registration'] = $form_state['object']->registration;
  field_attach_form('ticket_registration', $form_state['object']->registration, $form, $form_state);

  if (!user_access('administer ticket states')) {
    $form['state']['#access'] = FALSE;
  }

  return $form;
}

/**
 * Handles submit for second form.
 */
function ticket_reservation_form_registration_submit($form, &$form_state) {
  module_load_include('inc', 'ticket', 'includes/ticket_registration.admin');
  ticket_registration_form_submit($form, $form_state);
  $registration = $form_state['ticket_registration'];

  if ($registration->state == 'completed') {
    ticket_reservation_delete($form_state['object']->reservation['trid']);
    rules_invoke_event('ticket_reservation_redeem_ticket', user_load($registration->user_uid), $registration);
  }
}

/**
 * Returns form results.
 * For use later with a confirmation landing page...
 *
 * @param object $object
 *   object with form values.
 *
 * @return array
 *   returns renderable array for multistep form result output.
 */
function ticket_reservation_get_result($object) {
  //$output = t("You've been successfully registered!");
  //return $output;
}
