<?php
/**
 * @file
 * cod_session_ranking.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function cod_session_ranking_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create field_session_ranking'.
  $permissions['create field_session_ranking'] = array(
    'name' => 'create field_session_ranking',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
      'session organizer' => 'session organizer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_session_ranking'.
  $permissions['edit field_session_ranking'] = array(
    'name' => 'edit field_session_ranking',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
      'session organizer' => 'session organizer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_session_ranking'.
  $permissions['edit own field_session_ranking'] = array(
    'name' => 'edit own field_session_ranking',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
      'session organizer' => 'session organizer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'rate content'.
  $permissions['rate content'] = array(
    'name' => 'rate content',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
      'session organizer' => 'session organizer',
    ),
    'module' => 'fivestar',
  );

  // Exported permission: 'view field_session_ranking'.
  $permissions['view field_session_ranking'] = array(
    'name' => 'view field_session_ranking',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
      'session organizer' => 'session organizer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_session_ranking'.
  $permissions['view own field_session_ranking'] = array(
    'name' => 'view own field_session_ranking',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
      'session organizer' => 'session organizer',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
