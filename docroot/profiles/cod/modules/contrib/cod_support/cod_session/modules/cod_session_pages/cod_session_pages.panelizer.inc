<?php
/**
 * @file
 * cod_session_pages.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function cod_session_pages_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:schedule_item:default:default';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'schedule_item';
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
  $display->uuid = '3603b081-3d55-442f-b360-9ac081bb25ef';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-060e88d3-a530-456b-a153-72c849f61551';
    $pane->panel = 'footer';
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
    $pane->uuid = '060e88d3-a530-456b-a153-72c849f61551';
    $display->content['new-060e88d3-a530-456b-a153-72c849f61551'] = $pane;
    $display->panels['footer'][0] = 'new-060e88d3-a530-456b-a153-72c849f61551';
    $pane = new stdClass();
    $pane->pid = 'new-50d086d8-ad1f-41bd-bd3e-ae29daa3ba5d';
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '50d086d8-ad1f-41bd-bd3e-ae29daa3ba5d';
    $display->content['new-50d086d8-ad1f-41bd-bd3e-ae29daa3ba5d'] = $pane;
    $display->panels['left_content'][0] = 'new-50d086d8-ad1f-41bd-bd3e-ae29daa3ba5d';
    $pane = new stdClass();
    $pane->pid = 'new-7f6be7ab-2a46-4f82-b7b7-d666d640f819';
    $pane->panel = 'top_right_content';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_session_timeslot';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'entityreference_entity_view',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'links' => 0,
        'view_mode' => 'full',
      ),
      'context' => 'panelizer',
      'override_title' => 0,
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
    $pane->uuid = '7f6be7ab-2a46-4f82-b7b7-d666d640f819';
    $display->content['new-7f6be7ab-2a46-4f82-b7b7-d666d640f819'] = $pane;
    $display->panels['top_right_content'][0] = 'new-7f6be7ab-2a46-4f82-b7b7-d666d640f819';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-50d086d8-ad1f-41bd-bd3e-ae29daa3ba5d';
  $panelizer->display = $display;
  $export['node:schedule_item:default:default'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:session:default:default';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'session';
  $panelizer->no_blocks = FALSE;
  $panelizer->css_id = '';
  $panelizer->css = '';
  $panelizer->pipeline = 'standard';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $panelizer->access = array();
  $panelizer->view_mode = 'default';
  $panelizer->css_class = '';
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
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
  $display->uuid = 'a150eb79-129d-4b8e-a4fc-ab5df6eafef3';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-e429a1c7-fffd-4256-baa2-f22dc059ba6a';
    $pane->panel = 'bottom_right_content';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_accepted';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
      'formatter' => 'hidden',
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'e429a1c7-fffd-4256-baa2-f22dc059ba6a';
    $display->content['new-e429a1c7-fffd-4256-baa2-f22dc059ba6a'] = $pane;
    $display->panels['bottom_right_content'][0] = 'new-e429a1c7-fffd-4256-baa2-f22dc059ba6a';
    $pane = new stdClass();
    $pane->pid = 'new-f03503f0-1544-456e-a9d4-06c3bcedb69e';
    $pane->panel = 'bottom_right_content';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:og_group_ref';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'hidden',
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
    $pane->uuid = 'f03503f0-1544-456e-a9d4-06c3bcedb69e';
    $display->content['new-f03503f0-1544-456e-a9d4-06c3bcedb69e'] = $pane;
    $display->panels['bottom_right_content'][1] = 'new-f03503f0-1544-456e-a9d4-06c3bcedb69e';
    $pane = new stdClass();
    $pane->pid = 'new-3948181e-fb59-482b-a58b-985a5de8b4e4';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '3948181e-fb59-482b-a58b-985a5de8b4e4';
    $display->content['new-3948181e-fb59-482b-a58b-985a5de8b4e4'] = $pane;
    $display->panels['bottom_right_content'][2] = 'new-3948181e-fb59-482b-a58b-985a5de8b4e4';
    $pane = new stdClass();
    $pane->pid = 'new-b01a3d0c-16f1-43ec-8d15-a359a49d0ef0';
    $pane->panel = 'left_content';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_speakers';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
      'formatter' => 'entityreference_label',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'link' => 0,
      ),
      'context' => 'panelizer',
      'override_title' => 0,
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
    $pane->uuid = 'b01a3d0c-16f1-43ec-8d15-a359a49d0ef0';
    $display->content['new-b01a3d0c-16f1-43ec-8d15-a359a49d0ef0'] = $pane;
    $display->panels['left_content'][0] = 'new-b01a3d0c-16f1-43ec-8d15-a359a49d0ef0';
    $pane = new stdClass();
    $pane->pid = 'new-bf3ef643-3409-4b51-a951-2bfc9c548100';
    $pane->panel = 'left_content';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_slides';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'file_default',
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
    $pane->uuid = 'bf3ef643-3409-4b51-a951-2bfc9c548100';
    $display->content['new-bf3ef643-3409-4b51-a951-2bfc9c548100'] = $pane;
    $display->panels['left_content'][1] = 'new-bf3ef643-3409-4b51-a951-2bfc9c548100';
    $pane = new stdClass();
    $pane->pid = 'new-7414cec9-2fb3-489f-9af6-c9bc8ea7cc61';
    $pane->panel = 'left_content';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_news_image';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'hidden',
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '7414cec9-2fb3-489f-9af6-c9bc8ea7cc61';
    $display->content['new-7414cec9-2fb3-489f-9af6-c9bc8ea7cc61'] = $pane;
    $display->panels['left_content'][2] = 'new-7414cec9-2fb3-489f-9af6-c9bc8ea7cc61';
    $pane = new stdClass();
    $pane->pid = 'new-e1938ebe-87cf-478b-803b-54f51816a39b';
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'e1938ebe-87cf-478b-803b-54f51816a39b';
    $display->content['new-e1938ebe-87cf-478b-803b-54f51816a39b'] = $pane;
    $display->panels['left_content'][3] = 'new-e1938ebe-87cf-478b-803b-54f51816a39b';
    $pane = new stdClass();
    $pane->pid = 'new-0da34661-2455-4e0b-918b-5c11fd44fd6a';
    $pane->panel = 'top_right_content';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_session_timeslot';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'entityreference_entity_view',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'links' => 1,
        'view_mode' => 'default',
      ),
      'context' => 'panelizer',
      'override_title' => 0,
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
    $pane->uuid = '0da34661-2455-4e0b-918b-5c11fd44fd6a';
    $display->content['new-0da34661-2455-4e0b-918b-5c11fd44fd6a'] = $pane;
    $display->panels['top_right_content'][0] = 'new-0da34661-2455-4e0b-918b-5c11fd44fd6a';
    $pane = new stdClass();
    $pane->pid = 'new-b4b99930-c93b-4de8-97f8-08a81413b531';
    $pane->panel = 'top_right_content';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_experience';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'list_default',
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
    $pane->uuid = 'b4b99930-c93b-4de8-97f8-08a81413b531';
    $display->content['new-b4b99930-c93b-4de8-97f8-08a81413b531'] = $pane;
    $display->panels['top_right_content'][1] = 'new-b4b99930-c93b-4de8-97f8-08a81413b531';
    $pane = new stdClass();
    $pane->pid = 'new-d1c2e7df-53fe-4dc5-9c77-51c7e83580e2';
    $pane->panel = 'top_right_content';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:og_vocabulary';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'entityreference_entity_view',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'concatenate' => FALSE,
        'view_mode' => 'default',
        'links' => 0,
      ),
      'context' => 'panelizer',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'd1c2e7df-53fe-4dc5-9c77-51c7e83580e2';
    $display->content['new-d1c2e7df-53fe-4dc5-9c77-51c7e83580e2'] = $pane;
    $display->panels['top_right_content'][2] = 'new-d1c2e7df-53fe-4dc5-9c77-51c7e83580e2';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-e1938ebe-87cf-478b-803b-54f51816a39b';
  $panelizer->display = $display;
  $export['node:session:default:default'] = $panelizer;

  return $export;
}
