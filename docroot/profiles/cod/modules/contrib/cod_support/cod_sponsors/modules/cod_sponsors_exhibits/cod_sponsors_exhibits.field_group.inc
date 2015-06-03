<?php
/**
 * @file
 * cod_sponsors_exhibits.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function cod_sponsors_exhibits_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sponsor_exhibit|node|sponsor|form';
  $field_group->group_name = 'group_sponsor_exhibit';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'sponsor';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Exhibit Hall',
    'weight' => '5',
    'children' => array(
      0 => 'field_sponsor_booth_number',
      1 => 'field_sponsor_booth_request',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Exhibit Hall',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-sponsor-exhibit field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_sponsor_exhibit|node|sponsor|form'] = $field_group;

  return $export;
}
