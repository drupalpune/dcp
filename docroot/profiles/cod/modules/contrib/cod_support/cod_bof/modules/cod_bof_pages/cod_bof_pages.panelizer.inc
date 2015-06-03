<?php
/**
 * @file
 * cod_bof_pages.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function cod_bof_pages_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:bof_session:default:default';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'bof_session';
  $panelizer->no_blocks = FALSE;
  $panelizer->css_id = '';
  $panelizer->css = '';
  $panelizer->pipeline = 'ipe';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $panelizer->access = array();
  $panelizer->view_mode = 'default';
  $panelizer->css_class = '';
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = FALSE;
  $panelizer->extra = array();
  $display = new panels_display();
  $display->layout = 'hydra';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'preface' => NULL,
      'left_content' => NULL,
      'top_right_content' => NULL,
      'bottom_right_content' => NULL,
      'footer' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '4db2afed-0bd2-48d9-a17e-622b97d4e6b3';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-54485a3c-b9ca-44e4-b48b-cd70194af3d2';
    $pane->panel = 'bottom_right_content';
    $pane->type = 'node_links';
    $pane->subtype = 'node_links';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => FALSE,
      'override_title_text' => '',
      'build_mode' => 'default',
      'identifier' => '',
      'link' => TRUE,
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_class' => 'link-wrapper',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '54485a3c-b9ca-44e4-b48b-cd70194af3d2';
    $display->content['new-54485a3c-b9ca-44e4-b48b-cd70194af3d2'] = $pane;
    $display->panels['bottom_right_content'][0] = 'new-54485a3c-b9ca-44e4-b48b-cd70194af3d2';
    $pane = new stdClass();
    $pane->pid = 'new-2e268302-c7a8-4055-a79d-f0e23fecb50b';
    $pane->panel = 'left_content';
    $pane->type = 'node_author';
    $pane->subtype = 'node_author';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'link' => 1,
      'context' => 'panelizer',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '2e268302-c7a8-4055-a79d-f0e23fecb50b';
    $display->content['new-2e268302-c7a8-4055-a79d-f0e23fecb50b'] = $pane;
    $display->panels['left_content'][0] = 'new-2e268302-c7a8-4055-a79d-f0e23fecb50b';
    $pane = new stdClass();
    $pane->pid = 'new-8642cd19-4aa4-493c-bc8b-6e27d3bf8908';
    $pane->panel = 'left_content';
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
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '8642cd19-4aa4-493c-bc8b-6e27d3bf8908';
    $display->content['new-8642cd19-4aa4-493c-bc8b-6e27d3bf8908'] = $pane;
    $display->panels['left_content'][1] = 'new-8642cd19-4aa4-493c-bc8b-6e27d3bf8908';
    $pane = new stdClass();
    $pane->pid = 'new-e975fc00-3daf-43bf-bdb3-edbb829493b6';
    $pane->panel = 'top_right_content';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_session_timeslot';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'entityreference_entity_view',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'view_mode' => 'default',
        'links' => TRUE,
      ),
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'e975fc00-3daf-43bf-bdb3-edbb829493b6';
    $display->content['new-e975fc00-3daf-43bf-bdb3-edbb829493b6'] = $pane;
    $display->panels['top_right_content'][0] = 'new-e975fc00-3daf-43bf-bdb3-edbb829493b6';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-8642cd19-4aa4-493c-bc8b-6e27d3bf8908';
  $panelizer->display = $display;
  $export['node:bof_session:default:default'] = $panelizer;

  return $export;
}
