<?php
/**
 * @file
 * dcp_community.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function dcp_community_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'foss_promoters';
  $page->task = 'page';
  $page->admin_title = 'FOSS Promoters';
  $page->admin_description = '';
  $page->path = 'about/foss-promoters';
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
  $handler->name = 'page_foss_promoters__panel_context_7f0bba28-1c63-44ec-8434-aeeb301eca3d';
  $handler->task = 'page';
  $handler->subtask = 'foss_promoters';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'FOSS Promoters ',
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
  $display->uuid = 'b2bd9ea6-d869-4f28-8ca6-c867ede6142d';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-5dc7d0e5-ed7a-432e-82f9-7e8fa6a81432';
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
    $pane->uuid = '5dc7d0e5-ed7a-432e-82f9-7e8fa6a81432';
    $display->content['new-5dc7d0e5-ed7a-432e-82f9-7e8fa6a81432'] = $pane;
    $display->panels['right'][0] = 'new-5dc7d0e5-ed7a-432e-82f9-7e8fa6a81432';
    $pane = new stdClass();
    $pane->pid = 'new-730c474c-48e3-4f4f-84f3-a71715702215';
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
    $pane->uuid = '730c474c-48e3-4f4f-84f3-a71715702215';
    $display->content['new-730c474c-48e3-4f4f-84f3-a71715702215'] = $pane;
    $display->panels['right'][1] = 'new-730c474c-48e3-4f4f-84f3-a71715702215';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['foss_promoters'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'venue_details';
  $page->task = 'page';
  $page->admin_title = 'Venue Details';
  $page->admin_description = '';
  $page->path = 'venue-details';
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
  $handler->name = 'page_venue_details__panel_context_589d9e31-58f3-4c43-998f-efc07ea7cc58';
  $handler->task = 'page';
  $handler->subtask = 'venue_details';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Venue Details',
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
  $display->uuid = '5cb38297-7dcd-48f2-9455-9efd0fba7ecd';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-85e6f266-6154-4800-95ae-2ce18f1f1b6c';
    $pane->panel = 'left';
    $pane->type = 'snippet';
    $pane->subtype = 'venue_details';
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
    $pane->uuid = '85e6f266-6154-4800-95ae-2ce18f1f1b6c';
    $display->content['new-85e6f266-6154-4800-95ae-2ce18f1f1b6c'] = $pane;
    $display->panels['left'][0] = 'new-85e6f266-6154-4800-95ae-2ce18f1f1b6c';
    $pane = new stdClass();
    $pane->pid = 'new-139e30df-e5be-4449-b098-e4e92326b62e';
    $pane->panel = 'right';
    $pane->type = 'snippet';
    $pane->subtype = 'direction';
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
    $pane->uuid = '139e30df-e5be-4449-b098-e4e92326b62e';
    $display->content['new-139e30df-e5be-4449-b098-e4e92326b62e'] = $pane;
    $display->panels['right'][0] = 'new-139e30df-e5be-4449-b098-e4e92326b62e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-85e6f266-6154-4800-95ae-2ce18f1f1b6c';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['venue_details'] = $page;

  return $pages;

}
