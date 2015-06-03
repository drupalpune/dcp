<?php

/**
 * Field handler to translate an order status into its readable form.
 */
class ticket_state_handler_field_ticket_state extends views_handler_field {
  function render($values) {
    $name = $this->get_value($values);
    if ($state = ticket_state_get_states($name)) {
      return $this->sanitize_value($state->label);
    }
  }
}
