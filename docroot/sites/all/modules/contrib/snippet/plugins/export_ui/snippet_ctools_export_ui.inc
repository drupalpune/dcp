<?php
/**
 * @file
 * snippet_ctools_export_ui.inc
 *
 * Define this Export UI plugin
 */

$plugin = array(
  'schema' => 'snippet',  // As defined in hook_schema().
  'access' => 'administer snippet',  // Define a permission users must have to access these pages.
  'create access' => 'administer snippet',
  'manage access' => 'manage snippet',
  'delete access' => 'administer snippet',

  'export' => array(
    'admin_title' => "admin_title",
  ),

  // Define the menu item.
  'menu' => array(
    'menu item' => 'snippet',
    'menu title' => 'Snippet',
    'menu description' => 'Create a snippet that will be used as a pane.',
    'items' => array(
      'revision' => array(
        'path' => 'list/%ctools_export_ui/revision',
        'title' => 'Enable',
        'page callback' => 'ctools_export_ui_switcher_page',
        'page arguments' => array('snippet_ctools_export_ui', 'revision', 4),
        'load arguments' => array('snippet_ctools_export_ui', 6),
        'access callback' => 'ctools_export_ui_task_access',
        'access arguments' => array('snippet_ctools_export_ui', 'revision', 4),
        'type' => MENU_CALLBACK,
      ),
      'revertto' => array(
        'path' => 'list/%ctools_export_ui/revision/%/revertto',
        'title' => 'Revert to version',
        'page callback' => 'ctools_export_ui_switcher_page',
        'page arguments' => array('snippet_ctools_export_ui', 'revertto', 4),
        'load arguments' => array('snippet_ctools_export_ui', 6),
        'access callback' => 'ctools_export_ui_task_access',
        'access arguments' => array('snippet_ctools_export_ui', 'revertto', 4),
        'type' => MENU_CALLBACK,
      ),

      'view' => array(
        'path' => 'list/%ctools_export_ui/revision/%/view',
        'title' => 'Revert to version',
        'page callback' => 'ctools_export_ui_switcher_page',
        'page arguments' => array('snippet_ctools_export_ui', 'view', 4),
        'load arguments' => array('snippet_ctools_export_ui', 6),
        'access callback' => 'ctools_export_ui_task_access',
        'access arguments' => array('snippet_ctools_export_ui', 'view', 4),
        'type' => MENU_CALLBACK,
      ),
      'version-delete' => array(
        'path' => 'list/%ctools_export_ui/revision/%/delete',
        'title' => 'Delete revision',
        'page callback' => 'ctools_export_ui_switcher_page',
        'page arguments' => array('snippet_ctools_export_ui', 'version_delete', 4),
        'load arguments' => array('snippet_ctools_export_ui', 6),
        'access callback' => 'ctools_export_ui_task_access',
        'access arguments' => array('snippet_ctools_export_ui', 'version_delete', 4),
        'type' => MENU_CALLBACK,
      ),
    ),
  ),

  'allowed operations' => array(
    'edit'    => array('title' => t('Edit')),
    'enable'  => array('title' => t('Enable'), 'ajax' => TRUE, 'token' => TRUE),
    'disable' => array('title' => t('Disable'), 'ajax' => TRUE, 'token' => TRUE),
    'revert'  => array('title' => t('Revert')),
    'delete'  => array('title' => t('Delete')),
    'clone'   => array('title' => t('Clone')),
    'import'  => array('title' => t('Import')),
    'export'  => array('title' => t('Export')),
    'revision'  => array('title' => t('Revisions')),
  ),

  // Define user interface texts.
  'title singular' => t('Snippet'),
  'title plural' => t('Snippets'),
  'title singular proper' => t('Snippet'),
  'title plural proper' => t('Snippets'),

  'handler' => 'snippet_ctools_export_ui',
);

