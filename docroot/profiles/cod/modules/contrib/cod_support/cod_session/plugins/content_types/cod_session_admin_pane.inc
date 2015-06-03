<?php

/**
 * This plugin array is more or less self documenting
 */
$plugin = array(
  // the title in the admin
  'title' => t('Session Management Pane'),
  // no one knows if "single" defaults to FALSE...
  'single' => TRUE,
  // oh joy, I get my own section of panel panes
  'category' => array(t('Conference Organizing'), -9),
  //'edit form' => 'cod_events_pane_content_type_edit_form',
  'render callback' => 'cod_session_pane_content_type_render'
);

/**
* Run-time rendering of the body of the block (content type)
* See ctools_plugin_examples for more advanced info
*/
function cod_session_pane_content_type_render($subtype, $conf, $context = NULL) {
  module_load_include('admin.inc', 'cod_session', 'includes/cod_session');
  // our output is generate by js. Any markup or theme functions
  // could go here.
  // that private js function is so bad that fixing it will be the
  // basis of the next tutorial
  $block = new stdClass();
  $block->title = t('Manage Published Sessions');

  if($node = node_load(array_shift($context))) {
    $block->content = cod_session_admin_sessions($node);
  } else {
    $block->content = t('Invalid Event Type');
  }
  return $block;
}

function cod_session_admin_sessions($event) {

  /* TODO: It'd be good to show the default session view options here
   * But rendering them like below doesn't work really well.

  $form = drupal_get_form('cod_session_details_form', $event);
  $content = drupal_render($form);
   *
   */
  $field = field_info_field('field_accepted');
  $allowed_values = list_allowed_values($field);

  $content_tabs = array();
  // Stick to the order of the allowed values.
  $key = 0;
  foreach ($allowed_values AS $status_name => $status) {
    $content_tabs[] = array(
      'title' => $status,
      'contents' => views_embed_view('cod_session_sessions_admin', 'panel_pane_published', $event->nid, $status_name),
      'weight' => $key,
    );
    $key++;
  }
  // Add the Scheduled tab
  $content_tabs[] = array(
    'title' => t('Scheduled'),
    'contents' => views_embed_view('cod_session_sessions_admin', 'panel_pane_scheduled', $event->nid),
    'weight' => 10,
  );

  $overrides = array('ajax' => 1, 'style' => 'Zen'); // Override some of the settings for the QT instance.
  $quicktabs = quicktabs_build_quicktabs('cod_session_admin_builder', $overrides, $content_tabs);

  $content = drupal_render($quicktabs['content']);

  return $content;
}
