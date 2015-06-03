<?php

/**
 * @file
 * Definition of ticket_views_handler_field_registration_link_cancel.
 */

/**
 * Field handler to present a link to registration cancel.
 *
 * @ingroup views_field_handlers
 */
class ticket_reservation_views_handler_field_registration_link_redeem extends ticket_views_handler_field_registration_link {

  function render_link($data, $values) {
    if (!user_access('redeem ticket')) {
      return;
    }
    $trid = $this->get_value($values, 'trid');
    if ($reservation = ticket_reservation_fetch_by_trid($trid)) {
      $text = !empty($this->options['text']) ? $this->options['text'] : t('Redeem');

      $this->options['alter']['make_link'] = TRUE;
      $this->options['alter']['path'] = 'ticket/redeem/' . $reservation['ticket_code'];

      return $text;
    }
  }
}
