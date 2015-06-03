<?php
/**
 * @file
 * Views include file.
 */

/**
 * Implements hook_views_data_alter().
 */
function cod_sponsors_commerce_views_data_alter(&$data) {
  // Allow views to relate registrations to users.
  $data['node']['sponsor_order_link'] = array(
    'field' => array(
      'title' => t('Sponsor Order'),
      'help' => t('Provide a link to the order of the host event entity'),
      'handler' => 'cod_sponsors_commerce_views_handler_field_order_link',
    ),
  );

}

/**
 * Implements hook_views_default_views_alter().
 */
function cod_sponsors_commerce_views_default_views_alter(&$views) {
  if (isset($views['cod_sponsors_admin'])) {
    /* Field: Content: Sponsor Order */
    $field = array(
      'id' => 'sponsor_order_link',
      'table' => 'node',
      'field' => 'sponsor_order_link',
      'label' => '',
      'element_label_colon' => FALSE,
    );

    // Apply fields to the handlers.
    $views['cod_sponsors_admin']->display['default']->handler->display->display_options['fields']['sponsor_order_link'] = $field;
    $views['cod_sponsors_admin']->display['panel_pane_1']->handler->display->display_options['fields']['sponsor_order_link'] = $field;
    $views['cod_sponsors_admin']->display['panel_pane_2']->handler->display->display_options['fields']['sponsor_order_link'] = $field;
  }
}
