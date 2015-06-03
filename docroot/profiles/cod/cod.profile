<?php

/*
 * Define commons minimum execution time required to operate.
 */
define('DRUPAL_MINIMUM_MAX_EXECUTION_TIME', 120);

/*
 * Define commons minimum APC cache required to operate.
 */
define('COD_MINIMUM_APC_CACHE', 96);

/**
 * Implements hook_form_alter().
 * Set COD as the default profile.
 * (copied from Atrium: We use system_form_form_id_alter, otherwise we cannot alter forms.)
 */
function system_form_install_select_profile_form_alter(&$form, $form_state) {
  foreach ($form['profile'] as $key => $element) {
    $form['profile'][$key]['#value'] = 'cod';
  }
}

function _cod_get_optional_modules() {
  $modules = system_rebuild_module_data();
  $cod_modules = array();
  foreach($modules AS $module_name => $module) {
    if(strpos($module_name, 'cod_') === 0 && isset($module->info['install_option']) && $module->info['install_option'] == 'cod') {
      $cod_modules[$module_name] = $module->info['description'] ? $module->info['description'] : $module_name;
    }
  }
  return $cod_modules;
}