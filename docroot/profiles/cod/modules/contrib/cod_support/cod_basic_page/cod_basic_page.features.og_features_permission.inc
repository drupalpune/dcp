<?php
/**
 * @file
 * cod_basic_page.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function cod_basic_page_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:event:create page content'
  $permissions['node:event:create page content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:event:delete any page content'
  $permissions['node:event:delete any page content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:event:delete own page content'
  $permissions['node:event:delete own page content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:event:update any page content'
  $permissions['node:event:update any page content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:event:update own page content'
  $permissions['node:event:update own page content'] = array(
    'roles' => array(),
  );

  return $permissions;
}
