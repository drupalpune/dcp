<?php
/**
 * @file
 * cod_paid_events.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function cod_paid_events_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create field_checkout_complete_state'.
  $permissions['create field_checkout_complete_state'] = array(
    'name' => 'create field_checkout_complete_state',
    'roles' => array(
      'administrator' => 'administrator',
      'attendee manager' => 'attendee manager',
      'content editor' => 'content editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_checkout_complete_state'.
  $permissions['edit field_checkout_complete_state'] = array(
    'name' => 'edit field_checkout_complete_state',
    'roles' => array(
      'administrator' => 'administrator',
      'attendee manager' => 'attendee manager',
      'content editor' => 'content editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_checkout_complete_state'.
  $permissions['edit own field_checkout_complete_state'] = array(
    'name' => 'edit own field_checkout_complete_state',
    'roles' => array(
      'administrator' => 'administrator',
      'attendee manager' => 'attendee manager',
      'content editor' => 'content editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_checkout_complete_state'.
  $permissions['view field_checkout_complete_state'] = array(
    'name' => 'view field_checkout_complete_state',
    'roles' => array(
      'administrator' => 'administrator',
      'attendee manager' => 'attendee manager',
      'content editor' => 'content editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_checkout_complete_state'.
  $permissions['view own field_checkout_complete_state'] = array(
    'name' => 'view own field_checkout_complete_state',
    'roles' => array(
      'administrator' => 'administrator',
      'attendee manager' => 'attendee manager',
      'content editor' => 'content editor',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
