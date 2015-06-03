<?php
/**
 * @file
 * dcp_node_details.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function dcp_node_details_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__basic_page';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -99;
  $handler->conf = array(
    'title' => 'Basic Page',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'basic_page',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'page' => 'page',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
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
  $display->uuid = 'd64acd15-f3f2-4e26-a500-74814bbadfda';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-8bc2776b-545e-4875-b793-99c7d2dac6b7';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
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
    $pane->uuid = '8bc2776b-545e-4875-b793-99c7d2dac6b7';
    $display->content['new-8bc2776b-545e-4875-b793-99c7d2dac6b7'] = $pane;
    $display->panels['left'][0] = 'new-8bc2776b-545e-4875-b793-99c7d2dac6b7';
    $pane = new stdClass();
    $pane->pid = 'new-cda65d5a-79ff-4934-b699-08a527c8fbeb';
    $pane->panel = 'right';
    $pane->type = 'snippet';
    $pane->subtype = 'tweet';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
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
    $pane->uuid = 'cda65d5a-79ff-4934-b699-08a527c8fbeb';
    $display->content['new-cda65d5a-79ff-4934-b699-08a527c8fbeb'] = $pane;
    $display->panels['right'][0] = 'new-cda65d5a-79ff-4934-b699-08a527c8fbeb';
    $pane = new stdClass();
    $pane->pid = 'new-5327f06a-bd7e-4be1-bd4d-2962ab569a68';
    $pane->panel = 'right';
    $pane->type = 'snippet';
    $pane->subtype = 'facebook_like_box';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
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
    $pane->uuid = '5327f06a-bd7e-4be1-bd4d-2962ab569a68';
    $display->content['new-5327f06a-bd7e-4be1-bd4d-2962ab569a68'] = $pane;
    $display->panels['right'][1] = 'new-5327f06a-bd7e-4be1-bd4d-2962ab569a68';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__basic_page'] = $handler;

  return $export;
}
