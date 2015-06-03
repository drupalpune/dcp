<?php
/**
 * @file
 * dcp_home_page.default_snippet.inc
 */

/**
 * Implements hook_default_snippet().
 */
function dcp_home_page_default_snippet() {
  $export = array();

  $snippet = new stdClass();
  $snippet->disabled = FALSE; /* Edit this to true to make a default snippet disabled initially */
  $snippet->api_version = 1;
  $snippet->admin_title = 'Announcements';
  $snippet->name = 'announcements';
  $snippet->title = 'Announcements';
  $export['announcements'] = $snippet;

  $snippet = new stdClass();
  $snippet->disabled = FALSE; /* Edit this to true to make a default snippet disabled initially */
  $snippet->api_version = 1;
  $snippet->admin_title = 'Become a Sponsor';
  $snippet->name = 'become_a_sponsor';
  $snippet->title = '';
  $export['become_a_sponsor'] = $snippet;

  $snippet = new stdClass();
  $snippet->disabled = FALSE; /* Edit this to true to make a default snippet disabled initially */
  $snippet->api_version = 1;
  $snippet->admin_title = 'Facebook Like Box';
  $snippet->name = 'facebook_like_box';
  $snippet->title = 'Facebook Like Box';
  $export['facebook_like_box'] = $snippet;

  $snippet = new stdClass();
  $snippet->disabled = FALSE; /* Edit this to true to make a default snippet disabled initially */
  $snippet->api_version = 1;
  $snippet->admin_title = 'Home page baner';
  $snippet->name = 'home_page_baner';
  $snippet->title = '';
  $export['home_page_baner'] = $snippet;

  $snippet = new stdClass();
  $snippet->disabled = FALSE; /* Edit this to true to make a default snippet disabled initially */
  $snippet->api_version = 1;
  $snippet->admin_title = 'Keynote speaker';
  $snippet->name = 'keynote_speaker';
  $snippet->title = 'Keynote speaker';
  $export['keynote_speaker'] = $snippet;

  $snippet = new stdClass();
  $snippet->disabled = FALSE; /* Edit this to true to make a default snippet disabled initially */
  $snippet->api_version = 1;
  $snippet->admin_title = 'Tweet';
  $snippet->name = 'tweet';
  $snippet->title = '';
  $export['tweet'] = $snippet;

  return $export;
}
