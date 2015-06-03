<?php
/**
 * @file
 * dcp_home_page.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function dcp_home_page_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'home_page';
  $page->task = 'page';
  $page->admin_title = 'Home page';
  $page->admin_description = 'This will have the structure for home page.';
  $page->path = 'home';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_home_page__panel_context_21d9445b-2d96-4105-bc5d-827a9583c067';
  $handler->task = 'page';
  $handler->subtask = 'home_page';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Home Page',
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
  $display->uuid = '17b744c2-e90d-41fe-a2a4-635bb2a614e2';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-adccefff-1467-40fe-98e5-ddab0a08a20b';
    $pane->panel = 'left';
    $pane->type = 'snippet';
    $pane->subtype = 'keynote_speaker';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->uuid = 'adccefff-1467-40fe-98e5-ddab0a08a20b';
    $display->content['new-adccefff-1467-40fe-98e5-ddab0a08a20b'] = $pane;
    $display->panels['left'][0] = 'new-adccefff-1467-40fe-98e5-ddab0a08a20b';
    $pane = new stdClass();
    $pane->pid = 'new-6f40338e-1ae8-43c1-806c-a887dc70ebec';
    $pane->panel = 'left';
    $pane->type = 'snippet';
    $pane->subtype = 'announcements';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->uuid = '6f40338e-1ae8-43c1-806c-a887dc70ebec';
    $display->content['new-6f40338e-1ae8-43c1-806c-a887dc70ebec'] = $pane;
    $display->panels['left'][1] = 'new-6f40338e-1ae8-43c1-806c-a887dc70ebec';
    $pane = new stdClass();
    $pane->pid = 'new-b75408e1-9b42-4209-a4a0-1687e0c483fb';
    $pane->panel = 'right';
    $pane->type = 'snippet';
    $pane->subtype = 'become_a_sponsor';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->uuid = 'b75408e1-9b42-4209-a4a0-1687e0c483fb';
    $display->content['new-b75408e1-9b42-4209-a4a0-1687e0c483fb'] = $pane;
    $display->panels['right'][0] = 'new-b75408e1-9b42-4209-a4a0-1687e0c483fb';
    $pane = new stdClass();
    $pane->pid = 'new-c38ef0e4-99ec-49c4-be8d-d55ebaebc1c8';
    $pane->panel = 'right';
    $pane->type = 'snippet';
    $pane->subtype = 'tweet';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->uuid = 'c38ef0e4-99ec-49c4-be8d-d55ebaebc1c8';
    $display->content['new-c38ef0e4-99ec-49c4-be8d-d55ebaebc1c8'] = $pane;
    $display->panels['right'][1] = 'new-c38ef0e4-99ec-49c4-be8d-d55ebaebc1c8';
    $pane = new stdClass();
    $pane->pid = 'new-f4b43d4e-6d53-469c-9174-38ebfba95db2';
    $pane->panel = 'right';
    $pane->type = 'snippet';
    $pane->subtype = 'facebook_like_box';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->uuid = 'f4b43d4e-6d53-469c-9174-38ebfba95db2';
    $display->content['new-f4b43d4e-6d53-469c-9174-38ebfba95db2'] = $pane;
    $display->panels['right'][2] = 'new-f4b43d4e-6d53-469c-9174-38ebfba95db2';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['home_page'] = $page;

  return $pages;

}
