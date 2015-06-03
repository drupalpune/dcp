<?php
/* file */

class ticket_reservation_views_handler_field_reservation_code extends views_handler_field {

  function construct() {
    parent::construct();
    $this->additional_fields['trid'] = 'trid';
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {
    $trid = $this->get_value($values, 'trid');
    $reservation = ticket_reservation_fetch_by_trid($trid);
    return isset($reservation['ticket_code']) ? $reservation['ticket_code'] : NULL;
  }
}