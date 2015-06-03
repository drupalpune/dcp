<?php
/**
 * @file
 * cod_schedule.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function cod_schedule_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create field_session_timeslot'.
  $permissions['create field_session_timeslot'] = array(
    'name' => 'create field_session_timeslot',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
      'session organizer' => 'session organizer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_session_timeslot'.
  $permissions['edit field_session_timeslot'] = array(
    'name' => 'edit field_session_timeslot',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
      'session organizer' => 'session organizer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_session_timeslot'.
  $permissions['edit own field_session_timeslot'] = array(
    'name' => 'edit own field_session_timeslot',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
      'session organizer' => 'session organizer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_session_timeslot'.
  $permissions['view field_session_timeslot'] = array(
    'name' => 'view field_session_timeslot',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_session_timeslot'.
  $permissions['view own field_session_timeslot'] = array(
    'name' => 'view own field_session_timeslot',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view schedule'.
  $permissions['view schedule'] = array(
    'name' => 'view schedule',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'cod_schedule',
  );

  return $permissions;
}
