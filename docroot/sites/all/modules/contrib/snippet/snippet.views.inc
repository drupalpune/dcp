<?php

/**
 * Implements hook_views_data().
 */
function snippet_views_data() {
  $data['views']['snippet'] = array(
    'title' => t('Snippet'),
    'group' => 'Snippet',
    'help' => t('Area handler to add snippet.'),
    'area' => array(
      'handler' => 'snippet_views_handler_area_snippet_handler',
    ),
  );

  return $data;
}

/**
 * Implements hook_views_pre_render().
 */
function snippet_views_pre_render(&$view) {
  $empty = (count($view->result) > 0) ? FALSE : TRUE;

  // Check header first.
  $snippet = snippet_views_get_title_override_snippet($view->header, $empty);
  // Check empty next if result set is empty.
  if (empty($snippet) && $empty) {
    $snippet = snippet_views_get_title_override_snippet($view->empty, $empty);
  }
  // Finally check footer.
  if (empty($snippet)) {
    $snippet = snippet_views_get_title_override_snippet($view->footer, $empty);
  }

  if ($snippet) {
    $snippet_data = snippet_load($snippet);
    $view->build_info['title'] = isset($snippet_data->title_revision) ? $snippet_data->title_revision : $snippet_data->title;
  }
}

/**
 * Helper function to get the title override snippet from an array of
 * area handlers.
 *
 * @param array $handlers
 *   An array of area handlers found inside the view object.
 * @param bool $empty
 *   Whether or not the view results are empty. Defaults to FALSE.
 *
 * @return string
 *   The machine name of the snippet set to override the view title.
 */
function snippet_views_get_title_override_snippet($handlers, $empty = FALSE) {
  if (empty($handlers) || !is_array($handlers) || !array_key_exists('snippet', $handlers)) {
    return '';
  }

  $snippet = '';

  // Loop through handlers and look for the first
  // snippet with override view title enabled.
  foreach($handlers as $key => $data) {
    if ($empty && !$data->options['empty']) {
      continue;
    }

    if (strpos($key, 'snippet') === 0) {
      if ($data->options['override_view_title']) {
        $snippet = $data->options['snippet'];
        break;
      }
    }
  }

  return $snippet;
}