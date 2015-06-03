<?php
/**
 * @file
 * cod_session_management_pages.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function cod_session_management_pages_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'cod_session_management_pages';
  $page->task = 'page';
  $page->admin_title = 'Session Management';
  $page->admin_description = '';
  $page->path = 'admin/conference/%node/sessions/dashboard';
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
      2 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'edit field_session_timeslot',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'default tab',
    'title' => 'Dashboard',
    'name' => 'navigation',
    'weight' => -1,
    'parent' => array(
      'type' => 'tab',
      'title' => 'Sessions',
      'name' => 'navigation',
      'weight' => '-3',
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
    'admin_paths' => TRUE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_cod_session_management_pages_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'cod_session_management_pages';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Manage Sessions',
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
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
          1 => 1,
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => '66.99573298618644',
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
      ),
      1 => array(
        'type' => 'column',
        'width' => '33.00426701381355',
        'width_type' => '%',
        'parent' => 'canvas',
        'children' => array(
          0 => 2,
        ),
        'class' => '',
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'right_sidebar',
        ),
        'parent' => '1',
        'class' => '',
      ),
      'right_sidebar' => array(
        'type' => 'region',
        'title' => 'Right Sidebar',
        'width' => 100,
        'width_type' => '%',
        'parent' => '2',
        'class' => '',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'right_sidebar' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '4a09e5ba-3ba0-47e6-af35-01d386c35d9e';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-d468fd6a-8561-4582-8d95-b36ef014cbd9';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'cod_session_sessions_admin-panel_pane_unpublished';
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
    $pane->uuid = 'd468fd6a-8561-4582-8d95-b36ef014cbd9';
    $display->content['new-d468fd6a-8561-4582-8d95-b36ef014cbd9'] = $pane;
    $display->panels['center'][0] = 'new-d468fd6a-8561-4582-8d95-b36ef014cbd9';
    $pane = new stdClass();
    $pane->pid = 'new-bfaf7482-734f-41ae-9e91-457007275128';
    $pane->panel = 'center';
    $pane->type = 'cod_session_admin_pane';
    $pane->subtype = 'cod_session_admin_pane';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'bfaf7482-734f-41ae-9e91-457007275128';
    $display->content['new-bfaf7482-734f-41ae-9e91-457007275128'] = $pane;
    $display->panels['center'][1] = 'new-bfaf7482-734f-41ae-9e91-457007275128';
    $pane = new stdClass();
    $pane->pid = 'new-299bb228-0927-4f74-acf0-4f21b278101a';
    $pane->panel = 'right_sidebar';
    $pane->type = 'views_panes';
    $pane->subtype = 'cod_session_tracks-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'machine_name' => 'session_tracks_%node:nid',
      ),
      'override_title' => 1,
      'override_title_text' => 'Session Tracks',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '299bb228-0927-4f74-acf0-4f21b278101a';
    $display->content['new-299bb228-0927-4f74-acf0-4f21b278101a'] = $pane;
    $display->panels['right_sidebar'][0] = 'new-299bb228-0927-4f74-acf0-4f21b278101a';
    $pane = new stdClass();
    $pane->pid = 'new-8c13b0ac-c679-456c-8a56-60b06e974663';
    $pane->panel = 'right_sidebar';
    $pane->type = 'views_panes';
    $pane->subtype = 'cod_session_sessions_admin-panel_pane_schedule_items';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '8c13b0ac-c679-456c-8a56-60b06e974663';
    $display->content['new-8c13b0ac-c679-456c-8a56-60b06e974663'] = $pane;
    $display->panels['right_sidebar'][1] = 'new-8c13b0ac-c679-456c-8a56-60b06e974663';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['cod_session_management_pages'] = $page;

  return $pages;

}
