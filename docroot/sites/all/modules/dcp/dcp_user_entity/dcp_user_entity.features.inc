<?php
/**
 * @file
 * dcp_user_entity.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dcp_user_entity_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}
