<?php
/**
 * @file
 * Views include file.
 */

/**
 * Implements hook_views_default_views_alter().
 */
function cod_paid_events_views_default_views_alter(&$views) {
  if (!empty($views['ticket_registration'])) {
    $views['ticket_registration']->display['default']->display_options['fields']['field_ticket_order']['id'] = 'field_ticket_order';
    $views['ticket_registration']->display['default']->display_options['fields']['field_ticket_order']['table'] = 'field_data_field_ticket_order';
    $views['ticket_registration']->display['default']->display_options['fields']['field_ticket_order']['field'] = 'field_ticket_order';
    $views['ticket_registration']->display['default']->display_options['fields']['field_ticket_order']['settings'] = array(
      'link' => 1,
    );
  }

  if (!empty($views['order_registrations'])) {
    $instance = cache_get('cod_paid_events_order_registrations_instance');

    // Check if there are field instances of the order number field.
    if (empty($instance)) {
      $instance = new stdClass();
      $instance->data = FALSE;
      foreach (field_info_instances('ticket_registration') as $field_instance) {
        if (!empty($field_instance['field_ticket_order'])) {
          $instance->data = TRUE;
          break;
        }
      }
      cache_set('cod_paid_events_order_registrations_instance', $instance->data);
    }

    // If instances exist, then add the contextual filter.
    if ($instance->data) {
      /* Contextual filter: Ticket registration: Order (field_ticket_order) */
      $views['order_registrations']->display['default']->display_options['arguments']['field_ticket_order_target_id']['id'] = 'field_ticket_order_target_id';
      $views['order_registrations']->display['default']->display_options['arguments']['field_ticket_order_target_id']['table'] = 'field_data_field_ticket_order';
      $views['order_registrations']->display['default']->display_options['arguments']['field_ticket_order_target_id']['field'] = 'field_ticket_order_target_id';
      $views['order_registrations']->display['default']->display_options['arguments']['field_ticket_order_target_id']['default_action'] = 'default';
      $views['order_registrations']->display['default']->display_options['arguments']['field_ticket_order_target_id']['default_argument_type'] = 'raw';
      $views['order_registrations']->display['default']->display_options['arguments']['field_ticket_order_target_id']['default_argument_options']['index'] = '3';
      $views['order_registrations']->display['default']->display_options['arguments']['field_ticket_order_target_id']['summary']['number_of_records'] = '0';
      $views['order_registrations']->display['default']->display_options['arguments']['field_ticket_order_target_id']['summary']['format'] = 'default_summary';
      $views['order_registrations']->display['default']->display_options['arguments']['field_ticket_order_target_id']['summary_options']['items_per_page'] = '25';
    }
  }
}
