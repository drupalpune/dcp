<?php
/**
 * @file
 * Views include file.
 */

/**
* Implements hook_views_data()
*/
function ticket_state_views_data_alter(&$data) {
  // Expose the order status.
  $data['ticket_registration']['state'] = array(
    'title' => t('Order state'),
    'help' => t('The workflow state of the ticket.'),
    'field' => array(
      'handler' => 'ticket_state_handler_field_ticket_state',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'ticket_state_handler_filter_ticket_state',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  return $data;
}
