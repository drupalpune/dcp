<?php

/**
 * Field handler to translate an order status into its readable form.
 */
class ticket_reservation_handler_field_ticket_state extends ticket_state_handler_field_ticket_state {
  function render($values) {
    // Only overwrite if there is a trid associated with the view row
    // We found a code! Overwrite
    if (!isset($values->trid) || $this->get_value($values) != 'completed') {
      return parent::render($values);
    }
    else if (isset($values->trid) && $registration = ticket_registration_load($values->trid)) {
      $code = ticket_reservation_fetch_by_trid($values->trid);
      if (!empty($code) && $registration->user_uid == 0) {
        return "Unclaimed";
      }
      else if (!empty($code)) {
        return "Incomplete";
      }
    }
    return parent::render($values);
  }
}
