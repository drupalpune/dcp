<?php
/**
 * @file
 * cod_sponsors_commerce.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function cod_sponsors_commerce_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'commerce_product-sponsor-field_sponsor_sponsorship_level'
  $field_instances['commerce_product-sponsor-field_sponsor_sponsorship_level'] = array(
    'bundle' => 'sponsor',
    'commerce_cart_settings' => array(
      'attribute_field' => 0,
      'attribute_widget' => 'select',
      'attribute_widget_title' => 'Sponsorship Level',
    ),
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Related Sponsorship level (if relevant)',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 0,
      ),
      'line_item' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'commerce_product',
    'field_name' => 'field_sponsor_sponsorship_level',
    'label' => 'Sponsorship Level',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 37,
    ),
  );

  // Exported field_instance: 'commerce_product-sponsor-og_group_ref'
  $field_instances['commerce_product-sponsor-og_group_ref'] = array(
    'bundle' => 'sponsor',
    'commerce_cart_settings' => array(
      'attribute_field' => 0,
      'attribute_widget' => 'select',
      'attribute_widget_title' => 'Conference',
    ),
    'default_value' => NULL,
    'default_value_function' => 'entityreference_prepopulate_field_default_value',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 1,
      ),
      'line_item' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'commerce_product',
    'field_name' => 'og_group_ref',
    'label' => 'Conference',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'og_widget' => array(
          'access_override' => 0,
          'admin' => array(
            'widget_type' => 'entityreference_autocomplete',
          ),
          'default' => array(
            'widget_type' => 'options_select',
          ),
          'status' => TRUE,
        ),
        'prepopulate' => array(
          'action' => 'none',
          'action_on_edit' => 0,
          'fallback' => 'none',
          'providers' => array(
            'og_context' => 1,
            'url' => 1,
          ),
          'skip_perm' => 0,
          'status' => 1,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'og',
      'settings' => array(),
      'type' => 'og_complex',
      'weight' => 39,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Conference');
  t('Related Sponsorship level (if relevant)');
  t('Sponsorship Level');

  return $field_instances;
}
