<?php
/**
 * @file
 * cod_sponsors_pages.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function cod_sponsors_pages_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'cod_sponsors_management_pages';
  $page->task = 'page';
  $page->admin_title = 'Sponsors Management';
  $page->admin_description = '';
  $page->path = 'admin/conference/%node/sponsors';
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
          'perm' => 'edit any sponsor content',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array(
    'type' => 'tab',
    'title' => 'Sponsors',
    'name' => 'navigation',
    'weight' => '1',
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
    'admin_paths' => TRUE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_cod_sponsors_management_pages_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'cod_sponsors_management_pages';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Sponsorship Dashboard',
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
        'width' => '66.62754303599374',
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
        'width' => '33.372456964006254',
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
  $display->title = 'Sponsorship Dashboard';
  $display->uuid = '9d2b49a1-71cf-4e4e-9bc6-7a3e74167cfb';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-652f17b9-0a2b-4bae-b05d-7005b1c81694';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'cod_sponsors_admin-panel_pane_1';
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
    $pane->uuid = '652f17b9-0a2b-4bae-b05d-7005b1c81694';
    $display->content['new-652f17b9-0a2b-4bae-b05d-7005b1c81694'] = $pane;
    $display->panels['center'][0] = 'new-652f17b9-0a2b-4bae-b05d-7005b1c81694';
    $pane = new stdClass();
    $pane->pid = 'new-9b4fa14d-5210-43f5-bf65-5aec6ebb1781';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'cod_sponsors_admin-panel_pane_2';
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
    $pane->uuid = '9b4fa14d-5210-43f5-bf65-5aec6ebb1781';
    $display->content['new-9b4fa14d-5210-43f5-bf65-5aec6ebb1781'] = $pane;
    $display->panels['center'][1] = 'new-9b4fa14d-5210-43f5-bf65-5aec6ebb1781';
    $pane = new stdClass();
    $pane->pid = 'new-5136ef86-669e-45ed-a953-48d6f3a8ac5c';
    $pane->panel = 'right_sidebar';
    $pane->type = 'views_panes';
    $pane->subtype = 'cod_sponsors_levels-panel_pane_1';
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
    $pane->uuid = '5136ef86-669e-45ed-a953-48d6f3a8ac5c';
    $display->content['new-5136ef86-669e-45ed-a953-48d6f3a8ac5c'] = $pane;
    $display->panels['right_sidebar'][0] = 'new-5136ef86-669e-45ed-a953-48d6f3a8ac5c';
    if (module_exists('cod_sponsors_commerce')) {
      $pane = new stdClass();
      $pane->pid = 'new-37388e4c-e88e-4c13-b703-a96445831a5c';
      $pane->panel = 'right_sidebar';
      $pane->type = 'views_panes';
      $pane->subtype = 'cod_sponsors_commerce-panel_pane_1';
      $pane->shown = TRUE;
      $pane->access = array();
      $pane->configuration = array(
        'arguments' => array(
          'og_group_ref_target_id' => '%node:nid',
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
      $pane->uuid = '37388e4c-e88e-4c13-b703-a96445831a5c';
      $display->content['new-37388e4c-e88e-4c13-b703-a96445831a5c'] = $pane;
      $display->panels['right_sidebar'][1] = 'new-37388e4c-e88e-4c13-b703-a96445831a5c';
    }
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['cod_sponsors_management_pages'] = $page;

  return $pages;

}
