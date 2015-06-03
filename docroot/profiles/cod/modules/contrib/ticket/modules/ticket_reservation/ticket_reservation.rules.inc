<?php

/**
 * implementation of hook_rules_condition_info()
 */
/**
* Implementation of hook_rules_event_info().
* @ingroup rules
*/
function ticket_reservation_rules_event_info() {
  return array(
    'ticket_reservation_cancel_ticket' => array(
      'label' => t('A ticket is cancelled'),
      'group' => t('Ticket Reservation'),
      'module' => 'ticket_reservation',
      'variables' => array(
        'acting_user' => array('type' => 'user', 'label' => t('The user who cancelled the ticket.')),
        'ticket' => array('type' => 'ticket_registration', 'label' => t('The cancelled ticket.')),
      ),
    ),
    'ticket_reservation_create_ticket' => array(
      'label' => t('A ticket code is created'),
      'module' => 'ticket_reservation',
      'group' => t('Ticket Reservation'),
      'variables' => array(
        'acting_user' => array('type' => 'user', 'label' => t('The user who created the ticket.')),
        'registrant_email' => array('type' => 'user', 'label' => t('The user who created the ticket.')),
        'ticket' => array('type' => 'ticket_registration', 'label' => t('The cancelled ticket.')),
      ),
    ),
    'ticket_reservation_redeem_ticket' => array(
      'label' => t('A ticket code is redeemed'),
      'module' => 'ticket_reservation',
      'group' => t('Ticket Reservation'),
      'variables' => array(
        'user_uid' => array('type' => 'user', 'label' => t('The user who created the ticket.')),
        'ticket' => array('type' => 'ticket_registration', 'label' => t('The completed ticket.')),
      ),
    ),
  );
}

/**
 * Implements hook_rules_condition_info().
 */
function ticket_reservation_rules_condition_info() {
  $conditions = array();

  $conditions['ticket_reservation_check_codes'] = array(
    'label' => t('Has ticket registration code'),
    'parameter' => array(
      'ticket_registration' => array(
        'type' => 'ticket_registration',
        'label' => t('Ticket registration'),
      ),
    ),
    'group' => t('Ticket'),
    'callbacks' => array(
      'execute' => 'ticket_reservation_check_codes',
    ),
  );

  $conditions['ticket_reservation_check_mail'] = array(
    'label' => t('Has reservation email'),
    'parameter' => array(
      'ticket_registration' => array(
        'type' => 'ticket_registration',
        'label' => t('Ticket registration'),
      ),
    ),
    'group' => t('Ticket'),
    'callbacks' => array(
      'execute' => 'ticket_reservation_check_mail',
    ),
  );

  return $conditions;
}

function ticket_reservation_check_codes($ticket_reservation) {
  if ($result = ticket_reservation_fetch_by_trid($ticket_reservation->trid)) {
    return TRUE;
  }
  return FALSE;
}

function ticket_reservation_check_mail($ticket_reservation) {
  if ($result = ticket_reservation_fetch_by_trid($ticket_reservation->trid)) {
    if (!empty($result['mail'])) {
      return TRUE;
    }
  }
  return FALSE;
}