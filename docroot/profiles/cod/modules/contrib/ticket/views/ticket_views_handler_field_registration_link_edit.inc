<?php

/**
 * @file
 * Definition of ticket_views_handler_field_register_link_edit.
 */

/**
 * Field handler to present a link to registration edit.
 *
 * @ingroup views_field_handlers
 */
class ticket_views_handler_field_registration_link_edit extends ticket_views_handler_field_registration_link {
  function render_link($data, $values) {
    if (!entity_access('update', 'ticket_registration', $data)) {
      return;
    }

    $text = !empty($this->options['text']) ? $this->options['text'] : t('Edit');

    $this->options['alter']['make_link'] = TRUE;
    $this->options['alter']['path'] = 'ticket_registration/' . $data . '/edit';

    return $text;
  }
}
