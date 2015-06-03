<?php

/*
 * @file - Ticket state rules definitions
 */


/**
* Implementation of hook_rules_event_info().
* @ingroup rules
*/
function cod_paid_events_rules_event_info() {
  return array(
    'cod_paid_events_add_ticket_to_order' => array(
      'label' => t('Ticket is first added to an order'),
      'group' => t('Ticket Reservation'),
      'module' => 'cod_paid_events',
      'variables' => array(
        'order' => array('type' => 'commerce_order', 'label' => t('Order')),
        'ticket' => array('type' => 'ticket_registration', 'label' => t('Ticket')),
      ),
    ),
  );
}

function cod_paid_events_rules_condition_info() {
  return array(
    'cod_paid_events_check_ticket_state_by_order' => array(
      'label' => t('Ticket is of specific state'),
      'group' => t('Ticket'),
      'parameter' => array(
        'order_id' => array(
          'type' => 'commerce_order',
          'label' => t('The order id')
        ),
        'ticket_state' => array(
          'type' => 'text',
          'label' => t('The registration state')
        ),
      ),
    ),
  );
}

/**
 * Implements hook_rules_action_info() on behalf of the user module.
 */
function cod_paid_events_rules_action_info() {
  return array(
    'cod_paid_events_modify_ticket_state_by_order' => array(
      'label' => t('Change ticket state for items in an order'),
      'group' => t('Ticket'),
      'parameter' => array(
        'order_id' => array(
          'type' => 'commerce_order',
          'label' => t('The order id')
        ),
        'ticket_state' => array(
          'type' => 'text',
          'label' => t('The desired registration state')
        ),
      ),
    ),
  );
}

/**
 * Condition packages_condition_packagetype
 */
function cod_paid_events_check_ticket_state_by_order($order, $ticket_state) {
  // Get the relevant orders from the ticket
  $regQuery = new EntityFieldQuery();
  $registrations = $regQuery->entityCondition('entity_type', 'ticket_registration')
    ->propertyCondition('state', $ticket_state)
    ->fieldCondition('field_ticket_order', 'target_id', $order->order_id)
    ->execute();
  if (isset($registrations['ticket_registration'])) {
    return TRUE;
  }
  return FALSE;
}

function cod_paid_events_modify_ticket_state_by_order($order, $ticket_state) {
  // Get the relevant orders from the ticket
  $regQuery = new EntityFieldQuery();
  $registrations = $regQuery->entityCondition('entity_type', 'ticket_registration')
    ->fieldCondition('field_ticket_order', 'target_id', $order->order_id)
    ->execute();
  if (isset($registrations['ticket_registration'])) {
    $trids = array_keys($registrations['ticket_registration']);
    foreach ($trids as $trid) {
      $registration = ticket_registration_load($trid);
      $registration->state = $ticket_state;
      $registration->save();
    }
  }
}