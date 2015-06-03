<?php
/**
 * @file
 * cod_community_pages.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cod_community_pages_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}
