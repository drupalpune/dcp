<?php
/**
 * @file
 * cod_session_ranking.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function cod_session_ranking_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_session_ranking'
  $field_bases['field_session_ranking'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_session_ranking',
    'field_permissions' => array(
      'type' => 2,
    ),
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'fivestar',
    'settings' => array(
      'axis' => 'vote',
    ),
    'translatable' => 0,
    'type' => 'fivestar',
  );

  return $field_bases;
}
