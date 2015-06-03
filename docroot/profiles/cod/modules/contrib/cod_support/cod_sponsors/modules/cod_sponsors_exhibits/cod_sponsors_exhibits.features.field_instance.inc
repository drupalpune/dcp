<?php
/**
 * @file
 * cod_sponsors_exhibits.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function cod_sponsors_exhibits_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-sponsor-field_sponsor_booth_number'
  $field_instances['node-sponsor-field_sponsor_booth_number'] = array(
    'bundle' => 'sponsor',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 7,
      ),
      'listing' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_sponsor_booth_number',
    'label' => 'Booth Number',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 32,
      ),
      'type' => 'text_textfield',
      'weight' => 11,
    ),
  );

  // Exported field_instance: 'node-sponsor-field_sponsor_booth_request'
  $field_instances['node-sponsor-field_sponsor_booth_request'] = array(
    'bundle' => 'sponsor',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => 'Some sponsorships come with an exhibit hall booth. Please indicate whether you intend to use the allocated booth. This option must be checked to receive a booth space.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 8,
      ),
      'listing' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_sponsor_booth_request',
    'label' => 'Booth Requested',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 10,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Booth Number');
  t('Booth Requested');
  t('Some sponsorships come with an exhibit hall booth. Please indicate whether you intend to use the allocated booth. This option must be checked to receive a booth space.');

  return $field_instances;
}
