<?php
/**
 * @file
 * cod_community_pages.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function cod_community_pages_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'community';
  $page->task = 'page';
  $page->admin_title = 'Community';
  $page->admin_description = '';
  $page->path = 'node/%node/community';
  $page->access = array();
  $page->menu = array(
    'type' => 'none',
    'title' => 'Community',
    'name' => 'navigation',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array(
    'node' => array(
      'id' => 1,
      'identifier' => 'Conference',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_community_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'community';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Community';
  $display->uuid = 'e86c900c-05d7-4279-8a73-dcf311bda827';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-797bfb61-a42b-47a1-94da-7e49df24efbc';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'views-34b0d603b0e648e1a97b7976be45b9f6';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'inherit_path' => 1,
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
    $pane->uuid = '797bfb61-a42b-47a1-94da-7e49df24efbc';
    $display->content['new-797bfb61-a42b-47a1-94da-7e49df24efbc'] = $pane;
    $display->panels['center'][0] = 'new-797bfb61-a42b-47a1-94da-7e49df24efbc';
    $pane = new stdClass();
    $pane->pid = 'new-dafcfd0f-4f89-4ace-b9b7-bee77657b467';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'cod_community_attendees-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_entity_id:node_1',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'dafcfd0f-4f89-4ace-b9b7-bee77657b467';
    $display->content['new-dafcfd0f-4f89-4ace-b9b7-bee77657b467'] = $pane;
    $display->panels['center'][1] = 'new-dafcfd0f-4f89-4ace-b9b7-bee77657b467';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['community'] = $page;

  return $pages;

}
