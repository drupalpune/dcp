<?php
/**
 * @file
 * cod_community.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function cod_community_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-event-field_ticket_attendee_listing'
  $field_instances['node-event-field_ticket_attendee_listing'] = array(
    'bundle' => 'event',
    'default_value' => array(
      0 => array(
        'value' => 1,
      ),
    ),
    'deleted' => 0,
    'description' => 'Indicate if tickets should have an attendee listing field added automatically. If unchecked, it will no longer add the field, however tickets already created with the field will need to have them manually removed.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'type' => 'hidden',
        'weight' => 12,
      ),
      'listing' => array(
        'label' => 'hidden',
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_ticket_attendee_listing',
    'label' => 'Include \'attendee listing\' field for tickets',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 7,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Include \'attendee listing\' field for tickets');
  t('Indicate if tickets should have an attendee listing field added automatically. If unchecked, it will no longer add the field, however tickets already created with the field will need to have them manually removed.');

  return $field_instances;
}
