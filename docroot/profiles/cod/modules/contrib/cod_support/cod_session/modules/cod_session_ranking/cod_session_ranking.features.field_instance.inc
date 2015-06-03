<?php
/**
 * @file
 * cod_session_ranking.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function cod_session_ranking_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-session-field_session_ranking'
  $field_instances['node-session-field_session_ranking'] = array(
    'bundle' => 'session',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'fivestar',
        'settings' => array(
          'expose' => TRUE,
          'style' => 'average',
          'text' => 'average',
          'widget' => array(
            'fivestar_widget' => NULL,
          ),
        ),
        'type' => 'fivestar_formatter_default',
        'weight' => 11,
      ),
      'listing' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_session_ranking',
    'label' => 'Session Rank',
    'required' => 0,
    'settings' => array(
      'allow_clear' => 1,
      'allow_ownvote' => 0,
      'allow_revote' => 1,
      'stars' => 5,
      'target' => 'none',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'fivestar',
      'settings' => array(),
      'type' => 'exposed',
      'weight' => 34,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Session Rank');

  return $field_instances;
}
