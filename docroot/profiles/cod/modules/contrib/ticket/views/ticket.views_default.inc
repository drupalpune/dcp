<?php
/**
 * @file
 * Default exported views.
 */

/**
 * Implements hook_views_default_views().
 */
function ticket_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'ticket_registration';
  $view->description = 'Display a list of all registration for a given ticket type';
  $view->tag = 'ticket';
  $view->base_table = 'ticket_registration';
  $view->human_name = 'Ticket: Registrations by type';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['display_comment'] = 'Add ticket registration displays to customize the output.';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
    'mail' => 'mail',
    'created' => 'created',
    'active' => 'active',
    'view_registration' => 'view_registration',
    'edit_registration' => 'view_registration',
    'cancel_registration' => 'view_registration',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'mail' => array(
      'sortable' => 0,
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
    'active' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
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
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'There are no ticket registrations.';
  $handler->display->display_options['empty']['area']['format'] = 'plain_text';
  /* Relationship: Ticket registration: Registrant */
  $handler->display->display_options['relationships']['author_uid']['id'] = 'author_uid';
  $handler->display->display_options['relationships']['author_uid']['table'] = 'ticket_registration';
  $handler->display->display_options['relationships']['author_uid']['field'] = 'author_uid';
  $handler->display->display_options['relationships']['author_uid']['required'] = TRUE;
  /* Field: Bulk operations: Ticket registration */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'ticket_registration';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_revision' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => '',
      ),
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::panelizer_set_status_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'author_uid';
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['relationship'] = 'author_uid';
  /* Field: Ticket registration: Order state */
  $handler->display->display_options['fields']['state']['id'] = 'state';
  $handler->display->display_options['fields']['state']['table'] = 'ticket_registration';
  $handler->display->display_options['fields']['state']['field'] = 'state';
  /* Field: Ticket registration: Date created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'ticket_registration';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'long';
  /* Field: Ticket registration: Link */
  $handler->display->display_options['fields']['view_registration']['id'] = 'view_registration';
  $handler->display->display_options['fields']['view_registration']['table'] = 'ticket_registration';
  $handler->display->display_options['fields']['view_registration']['field'] = 'view_registration';
  $handler->display->display_options['fields']['view_registration']['label'] = 'Operations';
  /* Field: Ticket registration: Edit link */
  $handler->display->display_options['fields']['edit_registration']['id'] = 'edit_registration';
  $handler->display->display_options['fields']['edit_registration']['table'] = 'ticket_registration';
  $handler->display->display_options['fields']['edit_registration']['field'] = 'edit_registration';
  $handler->display->display_options['fields']['edit_registration']['label'] = '';
  $handler->display->display_options['fields']['edit_registration']['element_label_colon'] = FALSE;
  /* Field: Ticket registration: Cancel link */
  $handler->display->display_options['fields']['cancel_registration']['id'] = 'cancel_registration';
  $handler->display->display_options['fields']['cancel_registration']['table'] = 'ticket_registration';
  $handler->display->display_options['fields']['cancel_registration']['field'] = 'cancel_registration';
  $handler->display->display_options['fields']['cancel_registration']['label'] = '';
  $handler->display->display_options['fields']['cancel_registration']['element_label_colon'] = FALSE;
  /* Field: Ticket registration: Order */
  $handler->display->display_options['fields']['field_ticket_order']['id'] = 'field_ticket_order';
  $handler->display->display_options['fields']['field_ticket_order']['table'] = 'field_data_field_ticket_order';
  $handler->display->display_options['fields']['field_ticket_order']['field'] = 'field_ticket_order';
  $handler->display->display_options['fields']['field_ticket_order']['settings'] = array(
    'link' => 1,
  );
  /* Contextual filter: Ticket registration: Ticket type ID (bundle) */
  $handler->display->display_options['arguments']['bundle']['id'] = 'bundle';
  $handler->display->display_options['arguments']['bundle']['table'] = 'ticket_registration';
  $handler->display->display_options['arguments']['bundle']['field'] = 'bundle';
  $handler->display->display_options['arguments']['bundle']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['bundle']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['bundle']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['bundle']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['bundle']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Ticket registration: Order state */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'ticket_registration';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['operator'] = 'not in';
  $handler->display->display_options['filters']['state']['value'] = array(
    'cancelled' => 'cancelled',
    'checkout' => 'checkout',
  );
  $handler->display->display_options['filters']['state']['exposed'] = TRUE;
  $handler->display->display_options['filters']['state']['expose']['operator_id'] = 'state_op';
  $handler->display->display_options['filters']['state']['expose']['label'] = 'Order state';
  $handler->display->display_options['filters']['state']['expose']['operator'] = 'state_op';
  $handler->display->display_options['filters']['state']['expose']['identifier'] = 'state';
  $handler->display->display_options['filters']['state']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    8 => 0,
    9 => 0,
    6 => 0,
    7 => 0,
    10 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');

  /* Display: Recent Registrations */
  $handler = $view->new_display('panel_pane', 'Recent Registrations', 'panel_pane_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Recent Registrations';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'Manage Attendees';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<a href="/group/node/!1/admin/people">+ Manage Attendees</a>';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['header']['area']['tokenize'] = TRUE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Ticket registration: Registrant */
  $handler->display->display_options['relationships']['author_uid']['id'] = 'author_uid';
  $handler->display->display_options['relationships']['author_uid']['table'] = 'ticket_registration';
  $handler->display->display_options['relationships']['author_uid']['field'] = 'author_uid';
  $handler->display->display_options['relationships']['author_uid']['required'] = TRUE;
  /* Relationship: Ticket registration: Ticket Type */
  $handler->display->display_options['relationships']['ticket_type_ttid']['id'] = 'ticket_type_ttid';
  $handler->display->display_options['relationships']['ticket_type_ttid']['table'] = 'ticket_registration';
  $handler->display->display_options['relationships']['ticket_type_ttid']['field'] = 'ticket_type_ttid';
  $handler->display->display_options['relationships']['ticket_type_ttid']['label'] = 'Ticket Type';
  $handler->display->display_options['relationships']['ticket_type_ttid']['required'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Ticket type: Entity ID */
  $handler->display->display_options['arguments']['entity_id']['id'] = 'entity_id';
  $handler->display->display_options['arguments']['entity_id']['table'] = 'ticket_type';
  $handler->display->display_options['arguments']['entity_id']['field'] = 'entity_id';
  $handler->display->display_options['arguments']['entity_id']['relationship'] = 'ticket_type_ttid';
  $handler->display->display_options['arguments']['entity_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['entity_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['entity_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['entity_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['entity_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['entity_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['entity_id']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['entity_id']['validate_options']['types'] = array(
    'event' => 'event',
  );
  $handler->display->display_options['arguments']['entity_id']['validate_options']['access'] = TRUE;

  $export['ticket_registration'] = $view;

  $view = new view();
  $view->name = 'ticket_user';
  $view->description = 'Display a list of all registration by a given user';
  $view->tag = 'default';
  $view->base_table = 'ticket_registration';
  $view->human_name = 'Ticket: Registrations by user';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Ticket: Registrations';
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'view all';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  // Because we want site modules to be able to edit the view, it doesn't really work
  // to have the ticket_reservation module make these edits. Thats why we don't have
  // an alter. How would Conference X alter a module with implements alter if the
  // Reservation module is already altering to go to the bottom of the stack.
  // Please d8, come soon!
  if (module_exists('ticket_reservation')) {
    /* Display: Master */
    $handler->display->display_options['style_options']['columns'] = array(
      'entity' => 'entity',
      'ticket_type_label' => 'ticket_type_label',
      'reservation_email' => 'name',
      'name' => 'name',
      'created' => 'created',
      'state' => 'state',
      'reservation_code' => 'reservation_code',
      'view_registration' => 'view_registration',
      'edit_registration' => 'view_registration',
      'cancel_registration' => 'view_registration',
      'redeem_link' => 'view_registration',
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
      'reservation_email' => array(
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
      'created' => array(
        'sortable' => 1,
        'default_sort_order' => 'desc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'state' => array(
        'sortable' => 0,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'reservation_code' => array(
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
      'redeem_link' => array(
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
    );
  }
  else {
    $handler->display->display_options['style_options']['columns'] = array(
      'entity' => 'entity',
      'ticket_type_label' => 'ticket_type_label',
      'name' => 'name',
      'created' => 'created',
      'state' => 'state',
      'view_registration' => 'view_registration',
      'edit_registration' => 'view_registration',
      'cancel_registration' => 'view_registration',
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
      'name' => array(
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
      'state' => array(
        'sortable' => 0,
        'default_sort_order' => 'asc',
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
    );
  }
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
  /* Field: Ticket registration: Ticket Registration ID */
  $handler->display->display_options['fields']['trid']['id'] = 'trid';
  $handler->display->display_options['fields']['trid']['table'] = 'ticket_registration';
  $handler->display->display_options['fields']['trid']['field'] = 'trid';
  $handler->display->display_options['fields']['trid']['label'] = 'ID';
  $handler->display->display_options['fields']['trid']['separator'] = '';
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
  if (module_exists('ticket_reservation')) {
    /* Field: Ticket registration: Reservation Email */
    $handler->display->display_options['fields']['reservation_email']['id'] = 'reservation_email';
    $handler->display->display_options['fields']['reservation_email']['table'] = 'ticket_registration';
    $handler->display->display_options['fields']['reservation_email']['field'] = 'reservation_email';
    $handler->display->display_options['fields']['reservation_email']['link_to_user'] = FALSE;
  }
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'user_uid';
  $handler->display->display_options['fields']['name']['label'] = 'Attendee';
  /* Field: Ticket registration: Date created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'ticket_registration';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'long';
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = FALSE;
  if (module_exists('ticket_state')) {
    /* Field: Ticket registration: Order state */
    $handler->display->display_options['fields']['state']['id'] = 'state';
    $handler->display->display_options['fields']['state']['table'] = 'ticket_registration';
    $handler->display->display_options['fields']['state']['field'] = 'state';
    $handler->display->display_options['fields']['state']['label'] = 'Status';
  }
  if (module_exists('ticket_reservation')) {
    /* Field: Ticket registration: Reservation Code */
    $handler->display->display_options['fields']['reservation_code']['id'] = 'reservation_code';
    $handler->display->display_options['fields']['reservation_code']['table'] = 'ticket_registration';
    $handler->display->display_options['fields']['reservation_code']['field'] = 'reservation_code';
  }
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
  if (module_exists('ticket_reservation')) {
    /* Field: Ticket registration: Redeem Link */
    $handler->display->display_options['fields']['redeem_link']['id'] = 'redeem_link';
    $handler->display->display_options['fields']['redeem_link']['table'] = 'ticket_registration';
    $handler->display->display_options['fields']['redeem_link']['field'] = 'redeem_link';
    $handler->display->display_options['fields']['redeem_link']['label'] = '';
    $handler->display->display_options['fields']['redeem_link']['element_label_colon'] = FALSE;
  }
  /* Contextual filter: Ticket registration: uid */
  $handler->display->display_options['arguments']['author_uid']['id'] = 'author_uid';
  $handler->display->display_options['arguments']['author_uid']['table'] = 'ticket_registration';
  $handler->display->display_options['arguments']['author_uid']['field'] = 'author_uid';
  $handler->display->display_options['arguments']['author_uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['author_uid']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['author_uid']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['author_uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['author_uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['author_uid']['summary_options']['items_per_page'] = '25';
  if (module_exists('ticket_state')) {
    /* Filter criterion: Ticket registration: State */
    $handler->display->display_options['filters']['state']['id'] = 'state';
    $handler->display->display_options['filters']['state']['table'] = 'ticket_registration';
    $handler->display->display_options['filters']['state']['field'] = 'state';
    $handler->display->display_options['filters']['state']['value'] = 'completed';
  }
  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['display_description'] = 'Recent tickets registered by a user.';

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
  $handler->display->display_options['path'] = 'user/%/tickets/registrant';

  $export['ticket_user'] = $view;

  return $export;
}
