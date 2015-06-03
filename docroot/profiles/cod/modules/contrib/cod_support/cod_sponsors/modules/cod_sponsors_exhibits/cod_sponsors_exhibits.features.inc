<?php
/**
 * @file
 * cod_sponsors_exhibits.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cod_sponsors_exhibits_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}
