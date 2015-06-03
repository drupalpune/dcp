<?php
/**
 * @file
 * cod_community.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function cod_community_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_event_tickets|node|event|form';
  $field_group->group_name = 'group_event_tickets';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tickets',
    'weight' => '1',
    'children' => array(
      0 => 'field_event_tickets',
      1 => 'field_ticket_attendee_listing',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Tickets',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_event_tickets|node|event|form'] = $field_group;

  return $export;
}
