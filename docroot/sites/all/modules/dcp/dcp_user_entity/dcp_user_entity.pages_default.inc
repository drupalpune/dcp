<?php
/**
 * @file
 * dcp_user_entity.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function dcp_user_entity_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'user_view__user_profile';
  $handler->task = 'user_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -99;
  $handler->conf = array(
    'title' => 'User Profile',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'user_profile',
  );
  $display = new panels_display();
  $display->layout = 'twocol_stacked';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'left' => NULL,
      'right' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '172cc204-5874-4118-a8d5-73b6b2e22291';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-61e2b225-91e3-40a2-9177-128f547329ae';
    $pane->panel = 'left';
    $pane->type = 'user_picture';
    $pane->subtype = 'user_picture';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_entity_id:user_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '61e2b225-91e3-40a2-9177-128f547329ae';
    $display->content['new-61e2b225-91e3-40a2-9177-128f547329ae'] = $pane;
    $display->panels['left'][0] = 'new-61e2b225-91e3-40a2-9177-128f547329ae';
    $pane = new stdClass();
    $pane->pid = 'new-b47104fa-c663-4383-acd7-db23c14b18c6';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'user:field_drupal_org_profile';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'link_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:user_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'b47104fa-c663-4383-acd7-db23c14b18c6';
    $display->content['new-b47104fa-c663-4383-acd7-db23c14b18c6'] = $pane;
    $display->panels['left'][1] = 'new-b47104fa-c663-4383-acd7-db23c14b18c6';
    $pane = new stdClass();
    $pane->pid = 'new-340b0e59-14d2-4142-a721-17b77f6edb38';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'user:field_profile_job_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:user_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '340b0e59-14d2-4142-a721-17b77f6edb38';
    $display->content['new-340b0e59-14d2-4142-a721-17b77f6edb38'] = $pane;
    $display->panels['left'][2] = 'new-340b0e59-14d2-4142-a721-17b77f6edb38';
    $pane = new stdClass();
    $pane->pid = 'new-2b2356f7-c6d1-466a-b704-ec5f4c320123';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'user:field_profile_org';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:user_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '2b2356f7-c6d1-466a-b704-ec5f4c320123';
    $display->content['new-2b2356f7-c6d1-466a-b704-ec5f4c320123'] = $pane;
    $display->panels['left'][3] = 'new-2b2356f7-c6d1-466a-b704-ec5f4c320123';
    $pane = new stdClass();
    $pane->pid = 'new-5187cd5a-cd9a-45fa-a32a-23fe197daf18';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'user:field_profile_interests';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:user_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '5187cd5a-cd9a-45fa-a32a-23fe197daf18';
    $display->content['new-5187cd5a-cd9a-45fa-a32a-23fe197daf18'] = $pane;
    $display->panels['left'][4] = 'new-5187cd5a-cd9a-45fa-a32a-23fe197daf18';
    $pane = new stdClass();
    $pane->pid = 'new-506e9fc4-fd34-4c1e-89b6-93654c4d85d6';
    $pane->panel = 'right';
    $pane->type = 'entity_field';
    $pane->subtype = 'user:field_profile_bio';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:user_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '506e9fc4-fd34-4c1e-89b6-93654c4d85d6';
    $display->content['new-506e9fc4-fd34-4c1e-89b6-93654c4d85d6'] = $pane;
    $display->panels['right'][0] = 'new-506e9fc4-fd34-4c1e-89b6-93654c4d85d6';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-61e2b225-91e3-40a2-9177-128f547329ae';
  $handler->conf['display'] = $display;
  $export['user_view__user_profile'] = $handler;

  return $export;
}
