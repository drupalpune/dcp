<?php
/**
 * @file
 * cod_profile_social.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cod_profile_social_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}
