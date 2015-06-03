<?php
/**
 * @file
 * dcp_node_details.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dcp_node_details_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}
