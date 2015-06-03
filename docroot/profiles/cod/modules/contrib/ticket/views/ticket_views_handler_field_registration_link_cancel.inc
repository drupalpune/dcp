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
class ticket_views_handler_field_registration_link_cancel extends ticket_views_handler_field_registration_link {

  function render_link($data, $values) {
    // Ensure user has access to delete this node.
    if (!entity_access('delete', 'ticket_registration', $data)) {
      return;
    }

    $this->options['alter']['make_link'] = TRUE;
    $this->options['alter']['path'] = 'ticket_registration/' . $data . '/delete';
    $this->options['alter']['query'] = drupal_get_destination();

    $text = !empty($this->options['text']) ? $this->options['text'] : t('Cancel');

    return $text;
  }
}
