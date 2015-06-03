<?php
/**
 * @file
 * cod_bof_pages.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function cod_bof_pages_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'cod_bof_pages';
  $page->task = 'page';
  $page->admin_title = 'cod_bof_pages';
  $page->admin_description = '';
  $page->path = 'node/%node/bofs';
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
  $handler->name = 'page_cod_bof_pages__panel_context_d1b7e4a1-edf8-4c94-bc18-5b7362409cc6';
  $handler->task = 'page';
  $handler->subtask = 'cod_bof_pages';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Bof Schedule',
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
  $display->title = 'Birds of a Feather';
  $display->uuid = '83c104ac-f931-4d19-980e-937e84900cee';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-284d0511-afdd-40f5-863c-42e3cc6090cd';
    $pane->panel = 'content';
    $pane->type = 'views_panes';
    $pane->subtype = 'cod_bof_schedule-panel_pane_1';
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
    $pane->uuid = '284d0511-afdd-40f5-863c-42e3cc6090cd';
    $display->content['new-284d0511-afdd-40f5-863c-42e3cc6090cd'] = $pane;
    $display->panels['content'][0] = 'new-284d0511-afdd-40f5-863c-42e3cc6090cd';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-284d0511-afdd-40f5-863c-42e3cc6090cd';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['cod_bof_pages'] = $page;

  return $pages;

}
