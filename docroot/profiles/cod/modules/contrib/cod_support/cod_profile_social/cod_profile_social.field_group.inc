<?php
/**
 * @file
 * cod_profile_social.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function cod_profile_social_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cod_profile_social|user|user|form';
  $field_group->group_name = 'group_cod_profile_social';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Social Media',
    'weight' => '12',
    'children' => array(
      0 => 'field_facebook_url',
      1 => 'field_linkedin_url',
      2 => 'field_twitter_url',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-cod-profile-social field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_cod_profile_social|user|user|form'] = $field_group;

  return $export;
}
