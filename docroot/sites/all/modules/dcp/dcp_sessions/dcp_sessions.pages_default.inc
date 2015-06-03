<?php
/**
 * @file
 * dcp_sessions.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function dcp_sessions_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'propose_a_session';
  $page->task = 'page';
  $page->admin_title = 'Propose a session';
  $page->admin_description = 'Propose a session';
  $page->path = 'session/propose';
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
  $handler->name = 'page_propose_a_session__panel_context_66799b03-a890-4529-bb9f-ddd89a2a8892';
  $handler->task = 'page';
  $handler->subtask = 'propose_a_session';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Propose a session',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(
      0 => array(
        'identifier' => 'Node add form',
        'keyword' => 'node_add',
        'name' => 'node_add_form',
        'type' => 'session',
        'id' => 1,
      ),
    ),
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
  $display->uuid = 'ea851b94-befd-40e7-bdd2-32115e5485d5';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-3dc3f040-4960-46b5-a269-5a6e4c887fee';
    $pane->panel = 'left';
    $pane->type = 'snippet';
    $pane->subtype = 'call_for_papers_description';
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
    $pane->uuid = '3dc3f040-4960-46b5-a269-5a6e4c887fee';
    $display->content['new-3dc3f040-4960-46b5-a269-5a6e4c887fee'] = $pane;
    $display->panels['left'][0] = 'new-3dc3f040-4960-46b5-a269-5a6e4c887fee';
    $pane = new stdClass();
    $pane->pid = 'new-617681a4-73bf-4120-bb97-63df66058bca';
    $pane->panel = 'left';
    $pane->type = 'form';
    $pane->subtype = 'form';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'context_exists',
          'settings' => array(
            'exists' => '1',
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'context' => 'context_node_add_form_1',
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
    $pane->uuid = '617681a4-73bf-4120-bb97-63df66058bca';
    $display->content['new-617681a4-73bf-4120-bb97-63df66058bca'] = $pane;
    $display->panels['left'][1] = 'new-617681a4-73bf-4120-bb97-63df66058bca';
    $pane = new stdClass();
    $pane->pid = 'new-c5c7d16e-b294-438c-94cd-35d888357ef1';
    $pane->panel = 'left';
    $pane->type = 'block';
    $pane->subtype = 'user-login';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 1,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
    );
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
    $pane->uuid = 'c5c7d16e-b294-438c-94cd-35d888357ef1';
    $display->content['new-c5c7d16e-b294-438c-94cd-35d888357ef1'] = $pane;
    $display->panels['left'][2] = 'new-c5c7d16e-b294-438c-94cd-35d888357ef1';
    $pane = new stdClass();
    $pane->pid = 'new-1d262388-d182-4574-bdc9-8c0b8dbe7a74';
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '1d262388-d182-4574-bdc9-8c0b8dbe7a74';
    $display->content['new-1d262388-d182-4574-bdc9-8c0b8dbe7a74'] = $pane;
    $display->panels['right'][0] = 'new-1d262388-d182-4574-bdc9-8c0b8dbe7a74';
    $pane = new stdClass();
    $pane->pid = 'new-b0e8df78-a2bf-40ab-9021-4dd3e1956f36';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'b0e8df78-a2bf-40ab-9021-4dd3e1956f36';
    $display->content['new-b0e8df78-a2bf-40ab-9021-4dd3e1956f36'] = $pane;
    $display->panels['right'][1] = 'new-b0e8df78-a2bf-40ab-9021-4dd3e1956f36';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-1d262388-d182-4574-bdc9-8c0b8dbe7a74';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['propose_a_session'] = $page;

  return $pages;

}
