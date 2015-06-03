<?php
/**
 * @file
 * Provides a display toggle for citation covers.
 */

class snippet_views_handler_area_snippet_handler extends views_handler_area {
  public function option_definition() {
    $options = parent::option_definition();

    // Add defaults.
    $options['override_view_title'] = array('default' => 0);
    $options['snippet'] = array('default' => '');
    $options['classes'] = array('default' => '');

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    // Include the ctools helper 'export'.
    ctools_include('export');
    // Load all the snippets that are in the database.
    $options = ctools_export_crud_load_all('snippet');
    // Create options array for form field.
    $snippet_options = array();
    foreach ($options as $key => $value) {
      $title = ($value->title) ? $value->title : $value->admin_title;
      $snippet_options[$key] = $title;
    }

    if (!count($snippet_options)) {
      drupal_set_message(t('There are no snippets available.'), 'error');
    }

    $form['override_view_title'] = array(
      '#type' => 'checkbox',
      '#title' => t('Override view title'),
      '#description' => t('Check this box if you want the snippet title to take the place of the view title in display. Note if you enable this setting on more than one snippet displayed with this view, the first snippet\'s title will be used.'),
      '#default_value' => $this->options['override_view_title']
    );

    $form['snippet'] = array(
      '#type' => 'select',
      '#title' => t('Snippets'),
      '#default_value' => $this->options['snippet'],
      '#options' => $snippet_options,
      '#description' => t('Please select a snippet.')
    );

    $form['classes'] = array(
      '#type' => 'textfield',
      '#title' => t('Additional classes'),
      '#description' => t('Classes to add to the snippet wrapper. You may enter more than one, separated by spaces.'),
      '#default_value' => $this->options['classes']
    );

    return $form;
  }

  public function render($empty = FALSE) {
    $output = '';
    if (empty($this->options['snippet']) || ($empty && !$this->options['empty'])) {
      return $output;
    }

    // Load snippet and prepare output.
    $snippet = snippet_load($this->options['snippet']);
    $classes = !empty($this->options['classes']) ? check_plain($this->options['classes']) : '';
    $vars = array();
    $vars['title'] = '';
    $vars['name'] = $snippet->name;
    $vars['content'] = $snippet->content;

    // Add title to variables array for theming only if it isn't being
    // used to override the view title.
    if (!$this->options['override_view_title']) {
      $vars['title'] = isset($snippet->title_revision) ? $snippet->title_revision : $snippet->title;
    }

    $output .= theme('snippet', $vars);

    return $output;
  }
}

