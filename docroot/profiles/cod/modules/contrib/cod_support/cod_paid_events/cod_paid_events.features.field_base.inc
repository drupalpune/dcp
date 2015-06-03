<?php
/**
 * @file
 * cod_paid_events.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function cod_paid_events_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'commerce_price'
  $field_bases['commerce_price'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(
      0 => 'commerce_product',
    ),
    'field_name' => 'commerce_price',
    'foreign keys' => array(),
    'indexes' => array(
      'currency_price' => array(
        0 => 'amount',
        1 => 'currency_code',
      ),
    ),
    'locked' => 1,
    'module' => 'commerce_price',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'commerce_price',
  );

  // Exported field_base: 'field_checkout_complete_state'
  $field_bases['field_checkout_complete_state'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_checkout_complete_state',
    'field_permissions' => array(
      'type' => 2,
    ),
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'ticket_state',
    'settings' => array(
      'allowed_values' => array(
        'pending' => 'Pending',
        'completed' => 'Completed',
        'cancelled' => 'Cancelled',
        'checked_in' => 'Checked-In',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_ticket_state',
  );

  // Exported field_base: 'field_ticket_order'
  $field_bases['field_ticket_order'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_ticket_order',
    'field_permissions' => array(
      'type' => 1,
    ),
    'foreign keys' => array(
      'commerce_order' => array(
        'columns' => array(
          'target_id' => 'order_id',
        ),
        'table' => 'commerce_order',
      ),
    ),
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'handler' => 'base',
      'handler_settings' => array(
        'behaviors' => array(
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'sort' => array(
          'direction' => 'ASC',
          'property' => 'order_number',
          'type' => 'property',
        ),
        'target_bundles' => array(
          'commerce_order' => 'commerce_order',
        ),
      ),
      'target_type' => 'commerce_order',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_base: 'field_ticket_related_product'
  $field_bases['field_ticket_related_product'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_ticket_related_product',
    'field_permissions' => array(
      'type' => 0,
    ),
    'foreign keys' => array(
      'product_id' => array(
        'columns' => array(
          'product_id' => 'product_id',
        ),
        'table' => 'commerce_product',
      ),
    ),
    'indexes' => array(
      'product_id' => array(
        0 => 'product_id',
      ),
    ),
    'locked' => 0,
    'module' => 'commerce_product_reference',
    'settings' => array(
      'options_list_limit' => '',
    ),
    'translatable' => 0,
    'type' => 'commerce_product_reference',
  );

  return $field_bases;
}
