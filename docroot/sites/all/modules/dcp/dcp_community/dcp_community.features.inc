<?php
/**
 * @file
 * dcp_community.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dcp_community_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "snippet" && $api == "default_snippet") {
    return array("version" => "1");
  }
}
