<?php
/**
 * @file
 * cod_schedule_pages.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function cod_schedule_pages_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'cod_schedule_admin_page';
  $page->task = 'page';
  $page->admin_title = 'Schedule Admin Page';
  $page->admin_description = 'Cod Scheduler';
  $page->path = 'admin/conference/%node/schedule';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'node_type',
        'settings' => array(
          'type' => array(
            'event' => 'event',
          ),
        ),
        'context' => 'argument_entity_id:node_1',
        'not' => FALSE,
      ),
      1 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'administer schedule',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array(
    'type' => 'tab',
    'title' => 'Scheduler',
    'name' => 'navigation',
    'weight' => '-2',
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
      'identifier' => 'Event',
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
  $handler->name = 'page_cod_schedule_admin_page_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'cod_schedule_admin_page';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => 'cod-schedule-wrapper',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'twocol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'left' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Schedule';
  $display->uuid = 'f606f0b5-c491-418c-97f0-cbdaac8b8561';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-e960910c-0102-4b1c-96de-e59a3496beb8';
    $pane->panel = 'left';
    $pane->type = 'cod_schedule_scheduler_pane';
    $pane->subtype = 'cod_schedule_scheduler_pane';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'e960910c-0102-4b1c-96de-e59a3496beb8';
    $display->content['new-e960910c-0102-4b1c-96de-e59a3496beb8'] = $pane;
    $display->panels['left'][0] = 'new-e960910c-0102-4b1c-96de-e59a3496beb8';
    $pane = new stdClass();
    $pane->pid = 'new-e1cc7db0-4390-432a-ab4b-1e9611d50f4e';
    $pane->panel = 'right';
    $pane->type = 'cod_schedule_sessions_pane';
    $pane->subtype = 'cod_schedule_sessions_pane';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'e1cc7db0-4390-432a-ab4b-1e9611d50f4e';
    $display->content['new-e1cc7db0-4390-432a-ab4b-1e9611d50f4e'] = $pane;
    $display->panels['right'][0] = 'new-e1cc7db0-4390-432a-ab4b-1e9611d50f4e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['cod_schedule_admin_page'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'cod_schedule_public';
  $page->task = 'page';
  $page->admin_title = 'Public Schedule page';
  $page->admin_description = '';
  $page->path = 'node/%node/schedule';
  $page->access = array();
  $page->menu = array();
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
  $handler->name = 'page_cod_schedule_public__panel_context_931cc9dd-ba60-4165-9530-0abad52c7c4b';
  $handler->task = 'page';
  $handler->subtask = 'cod_schedule_public';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Schedule Page',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'cygnus';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'preface' => NULL,
      'content' => NULL,
      'footer' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Schedule';
  $display->uuid = '77ac51b8-f86c-4684-8b15-b3f0ea5cdd0c';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-da4f4f1a-2b55-4e8e-95ce-e40a92a0dbfb';
    $pane->panel = 'content';
    $pane->type = 'views_panes';
    $pane->subtype = 'cod_schedule-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'gid' => '%node:nid',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'da4f4f1a-2b55-4e8e-95ce-e40a92a0dbfb';
    $display->content['new-da4f4f1a-2b55-4e8e-95ce-e40a92a0dbfb'] = $pane;
    $display->panels['content'][0] = 'new-da4f4f1a-2b55-4e8e-95ce-e40a92a0dbfb';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-da4f4f1a-2b55-4e8e-95ce-e40a92a0dbfb';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['cod_schedule_public'] = $page;

  return $pages;

}
