<?php
/**
 * @file
 * cod_community.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function cod_community_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'cod_community_attendees';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'ticket_registration';
  $view->human_name = 'Community';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Attendees';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No confirmed attendees yet.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Ticket registration: Attendee */
  $handler->display->display_options['relationships']['user_uid']['id'] = 'user_uid';
  $handler->display->display_options['relationships']['user_uid']['table'] = 'ticket_registration';
  $handler->display->display_options['relationships']['user_uid']['field'] = 'user_uid';
  $handler->display->display_options['relationships']['user_uid']['required'] = TRUE;
  /* Relationship: Ticket registration: Ticket Type */
  $handler->display->display_options['relationships']['ticket_type_ttid']['id'] = 'ticket_type_ttid';
  $handler->display->display_options['relationships']['ticket_type_ttid']['table'] = 'ticket_registration';
  $handler->display->display_options['relationships']['ticket_type_ttid']['field'] = 'ticket_type_ttid';
  $handler->display->display_options['relationships']['ticket_type_ttid']['required'] = TRUE;
  /* Field: Ticket registration: Ticket Registration ID */
  $handler->display->display_options['fields']['trid']['id'] = 'trid';
  $handler->display->display_options['fields']['trid']['table'] = 'ticket_registration';
  $handler->display->display_options['fields']['trid']['field'] = 'trid';
  $handler->display->display_options['fields']['trid']['label'] = '';
  $handler->display->display_options['fields']['trid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['trid']['element_label_colon'] = FALSE;
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['relationship'] = 'user_uid';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['image_style'] = 'thumbnail';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'user_uid';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Field: First name */
  $handler->display->display_options['fields']['field_profile_first']['id'] = 'field_profile_first';
  $handler->display->display_options['fields']['field_profile_first']['table'] = 'field_data_field_profile_first';
  $handler->display->display_options['fields']['field_profile_first']['field'] = 'field_profile_first';
  $handler->display->display_options['fields']['field_profile_first']['label'] = '';
  $handler->display->display_options['fields']['field_profile_first']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_first']['type'] = 'text_plain';
  /* Field: Field: Last name */
  $handler->display->display_options['fields']['field_profile_last']['id'] = 'field_profile_last';
  $handler->display->display_options['fields']['field_profile_last']['table'] = 'field_data_field_profile_last';
  $handler->display->display_options['fields']['field_profile_last']['field'] = 'field_profile_last';
  $handler->display->display_options['fields']['field_profile_last']['label'] = '';
  $handler->display->display_options['fields']['field_profile_last']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_last']['type'] = 'text_plain';
  /* Field: Field: Job title */
  $handler->display->display_options['fields']['field_profile_job_title']['id'] = 'field_profile_job_title';
  $handler->display->display_options['fields']['field_profile_job_title']['table'] = 'field_data_field_profile_job_title';
  $handler->display->display_options['fields']['field_profile_job_title']['field'] = 'field_profile_job_title';
  $handler->display->display_options['fields']['field_profile_job_title']['label'] = '';
  $handler->display->display_options['fields']['field_profile_job_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_job_title']['type'] = 'text_plain';
  /* Field: Field: Organization */
  $handler->display->display_options['fields']['field_profile_org']['id'] = 'field_profile_org';
  $handler->display->display_options['fields']['field_profile_org']['table'] = 'field_data_field_profile_org';
  $handler->display->display_options['fields']['field_profile_org']['field'] = 'field_profile_org';
  $handler->display->display_options['fields']['field_profile_org']['label'] = '';
  $handler->display->display_options['fields']['field_profile_org']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_org']['type'] = 'text_plain';
  /* Contextual filter: Ticket type: Entity ID */
  $handler->display->display_options['arguments']['entity_id']['id'] = 'entity_id';
  $handler->display->display_options['arguments']['entity_id']['table'] = 'ticket_type';
  $handler->display->display_options['arguments']['entity_id']['field'] = 'entity_id';
  $handler->display->display_options['arguments']['entity_id']['relationship'] = 'ticket_type_ttid';
  $handler->display->display_options['arguments']['entity_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['entity_id']['default_argument_type'] = 'og_context';
  $handler->display->display_options['arguments']['entity_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['entity_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['entity_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['entity_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['entity_id']['validate']['type'] = 'og';
  $handler->display->display_options['arguments']['entity_id']['validate']['fail'] = 'empty';
  /* Filter criterion: Field: Show on attendee listing page (field_ticket_attendee_listing) */
  $handler->display->display_options['filters']['field_ticket_attendee_listing_value']['id'] = 'field_ticket_attendee_listing_value';
  $handler->display->display_options['filters']['field_ticket_attendee_listing_value']['table'] = 'field_data_field_ticket_attendee_listing';
  $handler->display->display_options['filters']['field_ticket_attendee_listing_value']['field'] = 'field_ticket_attendee_listing_value';
  $handler->display->display_options['filters']['field_ticket_attendee_listing_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_ticket_attendee_listing_value']['group'] = 1;
  /* Filter criterion: Field: First name (field_profile_first) */
  $handler->display->display_options['filters']['field_profile_first_value']['id'] = 'field_profile_first_value';
  $handler->display->display_options['filters']['field_profile_first_value']['table'] = 'field_data_field_profile_first';
  $handler->display->display_options['filters']['field_profile_first_value']['field'] = 'field_profile_first_value';
  $handler->display->display_options['filters']['field_profile_first_value']['group'] = 1;
  $handler->display->display_options['filters']['field_profile_first_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_profile_first_value']['expose']['operator_id'] = 'field_profile_first_value_op';
  $handler->display->display_options['filters']['field_profile_first_value']['expose']['label'] = 'First name';
  $handler->display->display_options['filters']['field_profile_first_value']['expose']['operator'] = 'field_profile_first_value_op';
  $handler->display->display_options['filters']['field_profile_first_value']['expose']['identifier'] = 'field_profile_first_value';
  $handler->display->display_options['filters']['field_profile_first_value']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Field: Last name (field_profile_last) */
  $handler->display->display_options['filters']['field_profile_last_value']['id'] = 'field_profile_last_value';
  $handler->display->display_options['filters']['field_profile_last_value']['table'] = 'field_data_field_profile_last';
  $handler->display->display_options['filters']['field_profile_last_value']['field'] = 'field_profile_last_value';
  $handler->display->display_options['filters']['field_profile_last_value']['group'] = 1;
  $handler->display->display_options['filters']['field_profile_last_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_profile_last_value']['expose']['operator_id'] = 'field_profile_last_value_op';
  $handler->display->display_options['filters']['field_profile_last_value']['expose']['label'] = 'Last name';
  $handler->display->display_options['filters']['field_profile_last_value']['expose']['operator'] = 'field_profile_last_value_op';
  $handler->display->display_options['filters']['field_profile_last_value']['expose']['identifier'] = 'field_profile_last_value';
  $handler->display->display_options['filters']['field_profile_last_value']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Field: Organization (field_profile_org) */
  $handler->display->display_options['filters']['field_profile_org_value']['id'] = 'field_profile_org_value';
  $handler->display->display_options['filters']['field_profile_org_value']['table'] = 'field_data_field_profile_org';
  $handler->display->display_options['filters']['field_profile_org_value']['field'] = 'field_profile_org_value';
  $handler->display->display_options['filters']['field_profile_org_value']['group'] = 1;
  $handler->display->display_options['filters']['field_profile_org_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_profile_org_value']['expose']['operator_id'] = 'field_profile_org_value_op';
  $handler->display->display_options['filters']['field_profile_org_value']['expose']['label'] = 'Organization';
  $handler->display->display_options['filters']['field_profile_org_value']['expose']['operator'] = 'field_profile_org_value_op';
  $handler->display->display_options['filters']['field_profile_org_value']['expose']['identifier'] = 'field_profile_org_value';
  $handler->display->display_options['filters']['field_profile_org_value']['expose']['remember_roles'] = array(
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
  /* Filter criterion: User: Name */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'users';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['relationship'] = 'user_uid';
  $handler->display->display_options['filters']['uid']['value'] = '';
  $handler->display->display_options['filters']['uid']['group'] = 1;
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'Username';
  $handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';
  $handler->display->display_options['filters']['uid']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Ticket registration: Order state */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'ticket_registration';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['value'] = array(
    'checked_in' => 'checked_in',
    'completed' => 'completed',
  );

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['argument_input'] = array(
    'entity_id' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Ticket type: Entity ID',
    ),
  );
  $export['cod_community_attendees'] = $view;

  return $export;
}
