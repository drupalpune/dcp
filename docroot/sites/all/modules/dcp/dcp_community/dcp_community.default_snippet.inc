<?php
/**
 * @file
 * dcp_community.default_snippet.inc
 */

/**
 * Implements hook_default_snippet().
 */
function dcp_community_default_snippet() {
  $export = array();

  $snippet = new stdClass();
  $snippet->disabled = FALSE; /* Edit this to true to make a default snippet disabled initially */
  $snippet->api_version = 1;
  $snippet->admin_title = 'Direction';
  $snippet->name = 'direction';
  $snippet->title = 'Direction';
  $export['direction'] = $snippet;

  $snippet = new stdClass();
  $snippet->disabled = FALSE; /* Edit this to true to make a default snippet disabled initially */
  $snippet->api_version = 1;
  $snippet->admin_title = 'Venue Details';
  $snippet->name = 'venue_details';
  $snippet->title = 'Venue Details';
  $export['venue_details'] = $snippet;

  return $export;
}
