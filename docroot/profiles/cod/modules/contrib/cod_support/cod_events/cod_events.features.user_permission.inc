<?php
/**
 * @file
 * cod_events.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function cod_events_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'view program'.
  $permissions['view program'] = array(
    'name' => 'view program',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'cod_events',
  );

  return $permissions;
}
