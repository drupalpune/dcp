<?php
/**
 * @file
 * Snippets
 *
 * Content type enable us to place the snippet as pane
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t('Snippet'),
  'description' => t('Snippet.'),

  // 'single' => TRUE means has no subtypes.
  'single' => FALSE,
  // Constructor.
  'content_types' => array('Snippet'),
  // Name of a function which will render the block.
  'render callback' => 'snippet_content_type_render',
  // The default context.
  'defaults' => array(),
  // This explicitly declares the config form. Without this line, the func
  // would be ctools_plugin_example_no_context_content_type_edit_form.
  'edit form' => 'snippet_content_type_edit_form',

  // Icon goes in the directory with the content type.
  'icon' => 'snippet_icon.png',
  'category' => array(t('Snippet'), -9),
  'content types' => 'snippet_content_type_content_types',
  // For admin UI display.
  'admin title' => 'snippet_content_type_render_admin_title',
  'admin info' => 'snippet_content_type_render_admin_info',
);

/**
 * Return all Snippets available as subtypes.
 */
function snippet_content_type_content_types($plugin) {
  $types = &drupal_static('snippet_subtypes', array());
  if (empty($types)) {
    // Include the ctools helper 'export'.
    ctools_include('export');
    $snippets = ctools_export_crud_load_all('snippet');
    foreach ($snippets as $key => $snippet) {
      $types[$key] = array(
        'title' => t('Snippet: @snippet_title (@machine_name)', array(
              '@snippet_title' => t($snippet->admin_title),
              '@machine_name' => $snippet->name,
            )),
        'icon' => 'snippet_icon.png',
        'description' => ($snippet->title) ? $snippet->title : NULL,
        'category' => t('Snippet'),
        'name' => $snippet->name,
      );
    }
  }

  // @todo A more persistent cache? Not even sure if drupal_static is useful.
  return $types;
}


/**
 * Edit form callback for the content type.
 */
function snippet_content_type_edit_form($form, &$form_state) {
  // Get the form state i.e. configuration values to load the default values!
  $conf = $form_state['conf'];

  // Include the ctools helper 'export'.
  ctools_include('export');
  if (!isset($form_state['subtype']) || $form_state['subtype_name'] == 'snippet') {
    // Loads all the 'snippet' those are there in database.
    $options = ctools_export_crud_load_all('snippet');

    // Create an option array.
    $snippet_options = array();
    foreach ($options as $key => $value) {
      $title = ($value->title) ? $value->title : $value->admin_title;
      $snippet_options[$key] = $title;
    }

    if (!count($snippet_options)) {
      drupal_set_message(t('There are no "Snippets" available.'), 'error');
    }

    // Form element : Select snippet.
    $form['snippet'] = array(
      '#type' => 'select',
      '#title' => t('Snippets'),
      '#default_value' => $conf['snippet'],
      '#options' => $snippet_options,
      '#description' => t('Please select a snippet.'),
    );
  }
  return $form;
}

/**
 * The submit form handler stores the data in $conf.
 */
function snippet_content_type_edit_form_submit(&$form, &$form_state) {
  // Remove internal Form API values.
  form_state_values_clean($form_state);
  $form_state['conf'] = $form_state['values'];
}

/**
 * Render the snippet content type.
 *
 * @param string $subtype
 *   Used to indicate the specific snippet that should be used.
 * @param array $conf
 *   Ctools configuration array for this content type.
 * @param array $panel_args
 *   Arguments for the panel where this is being rendered.
 * @param array $context
 *   Argumnets for the context under which this is being rendered.
 */
function snippet_content_type_render($subtype, $conf, $panel_args, &$context) {
  if (empty($conf['snippet']) && $subtype != 'snippet') {
    // Subtype passed in actually specifies the Snippet we should be using.
    $conf['snippet'] = $subtype;
  }
  // Get the snippet.
  $snippet = ctools_export_crud_load('snippet', $conf['snippet']);

  // If the snippet is not found then return nothing.
  if (empty($snippet)) {
    return '';
  }
  // If the snippet is disabled then return nothing.
  elseif (isset($snippet->disabled) && $snippet->disabled) {
    return '';
  }

  // Get the revised data!
  $snippet_revision = snippet_load($conf['snippet']);

  // Prepare array for theme!
  $variable['rid'] = $snippet_revision->rid;
  $variable['name'] = $snippet->name;

  $variable['content'] = check_markup($snippet_revision->content, $snippet_revision->content_format);

  $block = new stdClass();

  if (isset($conf['hide_title']) && $conf['hide_title'] == 1) {
    $block->title = '';
  }
  else {
    $block->title = check_plain(($snippet_revision->rid) ? $snippet_revision->title_revision : $snippet->title);
  }

  $block->content = theme('snippet', $variable);

  return $block;
}

/**
 * Admin title callback for panel panes.
 */
function snippet_content_type_render_admin_title($subtype, $conf, $contexts) {
  $title = 'Snippet';
  if (!empty($conf)) {
    if (empty($conf['snippet']) && $subtype != 'snippet') {
      // Subtype passed in actually specifies the Snippet we should be using.
      $conf['snippet'] = $subtype;
    }
    // Get the snippet.
    $snippet = ctools_export_crud_load('snippet', $conf['snippet']);

    if ($snippet) {
      $title = t('Snippet: @snippet_title (@machine_name)', array(
                '@snippet_title' => t($snippet->admin_title),
                '@machine_name' => $snippet->name,
              ));
    }
    else {
      $title = t('Deleted/missing snippet @name', array('@name' => $subtype));
    }
  }
  return $title;
}

/**
 * Admin info callback for panel panes.
 */
function snippet_content_type_render_admin_info($subtype, $conf, $contexts) {
  if (!empty($conf)) {

    if (empty($conf['snippet']) && $subtype != 'snippet') {
      // Subtype passed in actually specifies the Snippet we should be using.
      $conf['snippet'] = $subtype;
    }
    // Get the snippet.
    $snippet = ctools_export_crud_load('snippet', $conf['snippet']);
    if ($snippet) {
      $title = ($conf['override_title'] ? $conf['override_title_text'] : $snippet->title);
      if (empty($block->title)) {
        $block->title = 'No title';
      }
      $snippet_content = snippet_load($snippet->name);
      $content = check_markup($snippet_content->content, $snippet_content->content_format);
    }
    else {
      $title = t('Deleted/missing snippet @name', array('@name' => $subtype));
      $content = '';
    }
    $block = new stdClass();
    $block->title = $title;
    $block->content = $content;
    return $block;
  }

  return FALSE;
}
