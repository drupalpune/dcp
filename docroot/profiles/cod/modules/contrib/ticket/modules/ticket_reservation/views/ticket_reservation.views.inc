<?php
/**
 * @file
 * Views include file.
 */

/**
 * Implements hook_views_data_alter().
 */
function ticket_reservation_views_data_alter(&$data) {

  $data['ticket_registration']['cancel_registration'] = array(
    'field' => array(
      'title' => t('Cancel link'),
      'help' => t('Provide a simple link to release the ticket registration.'),
      'handler' => 'ticket_reservation_views_handler_field_registration_link_cancel',
    ),
  );
  $data['ticket_registration']['state']['field']['handler'] = 'ticket_reservation_handler_field_ticket_state';
  return $data;

}

/**
* Implements hook_views_data()
*/
function ticket_reservation_views_data() {

  $data['ticket_registration']['reservation_code'] = array(
      'field' => array(
        'title' => t('Reservation Code'),
        'help' => t('Registration Code for a registration.'),
        'handler' => 'ticket_reservation_views_handler_field_reservation_code',
      ),
  );
  $data['ticket_registration']['reservation_email'] = array(
      'field' => array(
        'title' => t('Reservation Email'),
        'help' => t('Registration Email for a registration.'),
        'handler' => 'ticket_reservation_handler_field_user_email',
      ),
  );

  $data['ticket_registration']['redeem_link'] = array(
      'field' => array(
        'title' => t('Redeem Link'),
        'help' => t('Registration Code Link.'),
        'handler' => 'ticket_reservation_views_handler_field_registration_link_redeem',
      ),
  );

  return $data;
}
