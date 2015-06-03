<?php
/**
 * @file
 * cod_sponsors.features.og_features_role.inc
 */

/**
 * Implements hook_og_features_default_roles().
 */
function cod_sponsors_og_features_default_roles() {
  $roles = array();

  // Exported OG Role: 'node:event:sponsor organizer'.
  $roles['node:event:sponsor organizer'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'event',
    'name' => 'sponsor organizer',
  );

  return $roles;
}
