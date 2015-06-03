<?php
/**
 * @file
 * dcp_sessions.default_snippet.inc
 */

/**
 * Implements hook_default_snippet().
 */
function dcp_sessions_default_snippet() {
  $export = array();

  $snippet = new stdClass();
  $snippet->disabled = FALSE; /* Edit this to true to make a default snippet disabled initially */
  $snippet->api_version = 1;
  $snippet->admin_title = 'Call For Papers Description';
  $snippet->name = 'call_for_papers_description';
  $snippet->title = 'Call For Papers Description';
  $export['call_for_papers_description'] = $snippet;

  return $export;
}
