<?php

/**
 * Filter by order status.
 */
class ticket_state_handler_filter_ticket_state extends views_handler_filter_in_operator {
  function get_value_options() {
    if (!isset($this->value_options)) {
      $this->value_title = t('State');
      $states = array();
      foreach (ticket_state_get_states() AS $machine_name => $state) {
        $states[$machine_name] = $state->label;
      }
      $this->value_options = $states;
    }
  }
}
