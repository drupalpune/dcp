<?php
/**
 * @file
 * Views include file.
 */

/**
 * Implements hook_views_default_views_alter().
 */
function cod_sponsors_exhibits_views_default_views_alter(&$views) {
  if (isset($views['cod_sponsors_admin'])) {
    $style_info = array(
      'field_sponsor_booth_request' => array(
        'sortable' => 0,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'field_sponsor_booth_number' => array(
        'sortable' => 0,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '-',
        'empty_column' => 0,
      ),
    );
    $fields = array(
      /* Field: Content: Booth Requested */
      'field_sponsor_booth_request' => array(
        'id' => 'field_sponsor_booth_request',
        'table' => 'field_data_field_sponsor_booth_request',
        'field' => 'field_sponsor_booth_request',
        'label' => 'Booth',
        'element_label_colon' => FALSE,
        'empty' => 'N',
      ),
      /* Field: Content: Booth Number */
      'field_sponsor_booth_number' => array(
        'id' => 'field_sponsor_booth_number',
        'table' => 'field_data_field_sponsor_booth_number',
        'field' => 'field_sponsor_booth_number',
        'label' => 'Booth',
        'element_label_colon' => FALSE,
      ),
    );

    /* Default Handler */
    $handler = & $views['cod_sponsors_admin']->display['default']->handler;
    // Set the table style options
    $handler->display->display_options['style_options']['columns']['field_sponsor_booth_request'] = 'field_sponsor_booth_number';
    $handler->display->display_options['style_options']['columns']['field_sponsor_booth_number'] = 'field_sponsor_booth_number';
    $handler->display->display_options['style_options']['info'] = $style_info + $handler->display->display_options['style_options']['info'];

    // Set the fields
    $handler->display->display_options['fields'] = array_merge($fields, $handler->display->display_options['fields']);

    /* Panel Pane 1 Handler */
    $handler = & $views['cod_sponsors_admin']->display['panel_pane_1']->handler;
    // Set the table style options
    $handler->display->display_options['style_options']['columns']['field_sponsor_booth_request'] = 'field_sponsor_booth_number';

    // Set the field
    $handler->display->display_options['fields'] = array('field_sponsor_booth_request' => $fields['field_sponsor_booth_request']) + $handler->display->display_options['fields'];

    /* Panel Pane 2 Handler */
    $handler = & $views['cod_sponsors_admin']->display['panel_pane_2']->handler;
    // Set the table style options
    $handler->display->display_options['style_options']['columns']['field_sponsor_booth_request'] = 'field_sponsor_booth_number';
    $handler->display->display_options['style_options']['columns']['field_sponsor_booth_number'] = 'field_sponsor_booth_number';

    // Set the fields
    $handler->display->display_options['fields'] = array_merge($fields, $handler->display->display_options['fields']);
  }
}
