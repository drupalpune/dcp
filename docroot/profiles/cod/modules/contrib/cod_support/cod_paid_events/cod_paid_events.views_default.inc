<?php
/**
 * @file
 * cod_paid_events.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function cod_paid_events_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'order_registrations';
  $view->description = 'Display a list of all registration by a given user';
  $view->tag = 'default';
  $view->base_table = 'ticket_registration';
  $view->human_name = 'Order Registrations';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Order Registrations';
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'view all';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view any commerce_order entity';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'entity' => 'entity',
    'ticket_type_label' => 'ticket_type_label',
    'created' => 'created',
    'view_registration' => 'view_registration',
    'edit_registration' => 'view_registration',
    'cancel_registration' => 'view_registration',
    'name' => 'name',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
    'entity' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'ticket_type_label' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'view_registration' => array(
      'align' => '',
      'separator' => '&nbsp; | &nbsp;',
      'empty_column' => 0,
    ),
    'edit_registration' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'cancel_registration' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'There are no ticket registrations.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Ticket registration: Ticket Type */
  $handler->display->display_options['relationships']['ticket_type_ttid']['id'] = 'ticket_type_ttid';
  $handler->display->display_options['relationships']['ticket_type_ttid']['table'] = 'ticket_registration';
  $handler->display->display_options['relationships']['ticket_type_ttid']['field'] = 'ticket_type_ttid';
  $handler->display->display_options['relationships']['ticket_type_ttid']['required'] = TRUE;
  /* Relationship: Ticket registration: Attendee */
  $handler->display->display_options['relationships']['user_uid']['id'] = 'user_uid';
  $handler->display->display_options['relationships']['user_uid']['table'] = 'ticket_registration';
  $handler->display->display_options['relationships']['user_uid']['field'] = 'user_uid';
  /* Field: Ticket type: Host entity */
  $handler->display->display_options['fields']['entity']['id'] = 'entity';
  $handler->display->display_options['fields']['entity']['table'] = 'ticket_type';
  $handler->display->display_options['fields']['entity']['field'] = 'entity';
  $handler->display->display_options['fields']['entity']['relationship'] = 'ticket_type_ttid';
  $handler->display->display_options['fields']['entity']['label'] = 'Event';
  /* Field: Ticket type: Ticket type */
  $handler->display->display_options['fields']['ticket_type_label']['id'] = 'ticket_type_label';
  $handler->display->display_options['fields']['ticket_type_label']['table'] = 'field_data_ticket_type_label';
  $handler->display->display_options['fields']['ticket_type_label']['field'] = 'ticket_type_label';
  $handler->display->display_options['fields']['ticket_type_label']['relationship'] = 'ticket_type_ttid';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'user_uid';
  $handler->display->display_options['fields']['name']['label'] = 'Attendee';
  /* Field: Ticket registration: Link */
  $handler->display->display_options['fields']['view_registration']['id'] = 'view_registration';
  $handler->display->display_options['fields']['view_registration']['table'] = 'ticket_registration';
  $handler->display->display_options['fields']['view_registration']['field'] = 'view_registration';
  $handler->display->display_options['fields']['view_registration']['label'] = 'Operations';
  /* Field: Ticket registration: Edit link */
  $handler->display->display_options['fields']['edit_registration']['id'] = 'edit_registration';
  $handler->display->display_options['fields']['edit_registration']['table'] = 'ticket_registration';
  $handler->display->display_options['fields']['edit_registration']['field'] = 'edit_registration';
  /* Field: Ticket registration: Cancel link */
  $handler->display->display_options['fields']['cancel_registration']['id'] = 'cancel_registration';
  $handler->display->display_options['fields']['cancel_registration']['table'] = 'ticket_registration';
  $handler->display->display_options['fields']['cancel_registration']['field'] = 'cancel_registration';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['display_description'] = 'All tickets registered by a user.';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'view all';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['path'] = 'admin/commerce/orders/%/registrations';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Registrations';
  $handler->display->display_options['menu']['description'] = 'Displays a list of registrations associated to an order.';
  $handler->display->display_options['menu']['weight'] = '10';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['order_registrations'] = $view;

  return $export;
}
