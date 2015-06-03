<?php

/**
 * @file
 * Definition of cod_sponsors_commerce_views_handler_field_order_link.
 */

/**
 * Field handler to present a link to the order.
 *
 * @ingroup views_field_handlers
 */
class cod_sponsors_commerce_views_handler_field_order_link extends views_handler_field {
  function construct() {
    parent::construct();
  }

  function option_definition() {
    return parent::option_definition();
  }

  function access() {
    return TRUE;
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {
    // Generate as link.
    $this->options['alter']['make_link'] = TRUE;

    // Get the host (event) entity.
    $nid = $values->nid;
    $tid = $values->field_field_sponsor_sponsorship_level[0]['raw']['tid'];
    $equery = new EntityFieldQueryExtraFields();
    $result = $equery->entityCondition('entity_type', 'commerce_line_item')
      ->propertyCondition('type', 'sponsorship')
      ->addExtraField('', 'order_id', 'order_id', 'commerce_line_item')
      ->fieldCondition('field_sponsorship_node', 'target_id', $nid, '=')
      ->execute();
    if (!empty($result['commerce_line_item']) && $existing_order = current($result['commerce_line_item'])) {
      if (!empty($existing_order->extraFields->order_id)) {
        $this->options['alter']['path'] = 'admin/commerce/orders/' . $existing_order->extraFields->order_id . '/view';
        return 'Order ' . $existing_order->extraFields->order_id;
      }
    }
    $query = new EntityFieldQuery();
    $result = $query->entityCondition('entity_type', 'commerce_product')
      ->propertyCondition('type', 'sponsor')
      ->propertyCondition('status', 1)
      ->fieldCondition('field_sponsor_sponsorship_level', 'tid', $tid, '=')
      ->execute();
    if (!empty($result['commerce_product']) && $pid = current(array_keys($result['commerce_product']))) {
      $this->options['alter']['path'] = 'sponsorship/' . $pid . '/add/' . $nid;
      // Return entity label.
      return 'Order Link';
    }
    return 'No Order';
  }
}
