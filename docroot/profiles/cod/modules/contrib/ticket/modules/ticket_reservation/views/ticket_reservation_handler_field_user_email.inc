<?php

/**
 * Field handler to translate an order status into its readable form.
 */
class ticket_reservation_handler_field_user_email extends views_handler_field_user {
  function construct() {
    parent::construct();
    $this->additional_fields['trid'] = 'trid';
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
  }

  function query() {
    $this->add_additional_fields();
  }

  function render($values) {
    $trid = $this->get_value($values, 'trid');
    $reservation = ticket_reservation_fetch_by_trid($trid);
    if (isset($reservation['mail']) && $account = user_load_by_mail($reservation['mail'])) {
      return $this->render_link($this->sanitize_value($account->name), $values);
    }
    elseif (isset($reservation['mail']))  {
      return $reservation['mail'];
    }
  }
}
