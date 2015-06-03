<?php
/**
 * @file
 * cod_profile_optional.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function cod_profile_optional_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cod_profile_details|user|user|form';
  $field_group->group_name = 'group_cod_profile_details';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Conference Details',
    'weight' => '13',
    'children' => array(
      0 => 'field_dietary_needs',
      1 => 'field_t_shirt_size',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-cod-profile-details field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_cod_profile_details|user|user|form'] = $field_group;

  return $export;
}
