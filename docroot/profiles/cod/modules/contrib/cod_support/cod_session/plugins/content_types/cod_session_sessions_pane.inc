<?php

/**
 * This plugin array is more or less self documenting
 */
$plugin = array(
  // the title in the admin
  'title' => t('Sessions View Pane'),
  // no one knows if "single" defaults to FALSE...
  'single' => TRUE,
  // oh joy, I get my own section of panel panes
  'category' => array(t('Conference Organizing'), -9),
  //'edit form' => 'cod_events_pane_content_type_edit_form',
  'render callback' => 'cod_session_sessions_pane_render'
);

/**
* Run-time rendering of the body of the block (content type)
* See ctools_plugin_examples for more advanced info
*/
function cod_session_sessions_pane_render($subtype, $conf, $context = NULL) {
  // our output is generate by js. Any markup or theme functions
  // could go here.
  // that private js function is so bad that fixing it will be the
  // basis of the next tutorial
  $block = new stdClass();

  if($node = node_load(array_shift($context))) {
    $block->content = cod_session_sessions_quicktabs($node);
  } else {
    $block->content = t('Invalid Event Type');
  }
  return $block;
}

function cod_session_sessions_quicktabs($event) {
  // Use '+' so that we can display Proposed/Declined and Accepted/Featured.
  $allowed_values = array('unprocessed+declined+backup' => 'Proposed', 'accepted+featured' => 'Accepted', 'cancelled' => 'Cancelled');
  $content_tabs = array();
  $weight = 0;
  foreach ($allowed_values AS $key => $status) {
    $content_tabs[] = array(
      'title' => $status,
      'contents' => views_embed_view('cod_session_sessions', 'block_sessions', $event->nid, $key),
      'weight' => $weight,
    );
    $weight++;
  }
  $default_tab = 0;
  if (!empty($event->field_event_default_session_view)) {
    $event = entity_metadata_wrapper('node', $event);
    $default_tab = $event->field_event_default_session_view->value();
  }

  $overrides = array('ajax' => 0, 'style' => 'Zen', 'default_tab' => $default_tab); // Override some of the settings for the QT instance.
  $quicktabs = quicktabs_build_quicktabs('cod_session_sessions_builder', $overrides, $content_tabs);

  $content = drupal_render($quicktabs['content']);

  return $content;
}
