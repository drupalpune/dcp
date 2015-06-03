<?php

/**
 * @file
 * CKEditor hooks implemented by the CKEditor module.
 */

/**
 * Implements hook_ckeditor_plugin().
 */
function ckeditor_ckeditor_plugin() {
  $plugins = array();
  $base_path = '%base_path%';
  $editor_path = '%editor_path%';
  $plugin_dir = '%plugin_dir%';
  $plugin_dir_additional = '%plugin_dir_extra%';
  $pattern = '#\.addButton\([\s]*[\'"](.*?)[\'"][\s]*\,[\s]*\{[\s]*(.*?)[\s]*\}#s';

  /*
   * CKEditor build-in plugins
   */
  $_editor_path = ckeditor_path('local');
  //die($editor_path);
  if ($_editor_path != '<URL>') {
    if (file_exists($_editor_path . '/plugins/tableresize/plugin.js')) {
      $plugins['tableresize'] = array(
        'name' => 'tableresize',
        'desc' => t('Table Resize plugin'),
        'path' => $editor_path . '/plugins/tableresize/',
        'buttons' => FALSE,
        'default' => 't'
      );
    }

    if (file_exists($_editor_path . '/plugins/autogrow/plugin.js')) {
      $plugins['autogrow'] = array(
        'name' => 'autogrow',
        'desc' => t('Auto Grow plugin'),
        'path' => $editor_path . '/plugins/autogrow/',
        'buttons' => FALSE,
        'default' => 'f'
      );
    }

    if (file_exists($_editor_path . '/plugins/stylesheetparser/plugin.js')) {
      $plugins['stylesheetparser'] = array(
        'name' => 'stylesheetparser',
        'desc' => t('Stylesheet Parser plugin'),
        'path' => $editor_path . '/plugins/stylesheetparser/',
        'buttons' => FALSE,
        'default' => 'f'
      );
    }
  }
  else {
    $_editor_url = ckeditor_path('url');
    if (preg_match("/\/(standard|full)-all/", $_editor_url)) {
      $plugins['tableresize'] = array(
        'name' => 'tableresize',
        'desc' => t('Table Resize plugin'),
        'path' => $_editor_url . '/plugins/tableresize/',
        'buttons' => FALSE,
        'default' => 't'
      );
      $plugins['autogrow'] = array(
        'name' => 'autogrow',
        'desc' => t('Auto Grow plugin'),
        'path' => $_editor_url . '/plugins/autogrow/',
        'buttons' => FALSE,
        'default' => 'f'
      );
      $plugins['stylesheetparser'] = array(
        'name' => 'stylesheetparser',
        'desc' => t('Stylesheet Parser plugin'),
        'path' => $_editor_url . '/plugins/stylesheetparser/',
        'buttons' => FALSE,
        'default' => 'f'
      );
    }
  }

  /*
   * CKEditor module plugins
   */
  $_plugin_dir = ckeditor_module_path('local') . '/plugins/';
  if ($handle = opendir($_plugin_dir)) {
    while (false !== ($file = readdir($handle))) {
      if (is_dir($_plugin_dir . $file) && file_exists($_plugin_dir . $file . '/plugin.js')) {
        $source = file_get_contents($_plugin_dir . $file . '/plugin.js');
        $buttons = array();
        if (preg_match_all($pattern, $source, $matches)) {
          foreach ($matches[1] as $i => $button_name) {
            if (preg_match('#(icon)[\s]*\:[\s]*([^\,\n]*)#', $matches[2][$i], $matches2)) {
              $buttons[$button_name] = array();
              $buttons[$button_name]['label'] = $button_name;
              $matches2[2] = str_replace(array('this.path', '+', '\'', '"'), array('', '', '', ''), $matches2[2]);
              $buttons[$button_name]['icon'] = trim($matches2[2]);
            }
          }
        }
        if (preg_match('#@file ([^\n\r]*)#', $source, $matches)) {
          $plugins[$file] = array(
            'name' => $file,
            'desc' => t($matches[1]),
            'path' => $plugin_dir . $file . '/',
            'buttons' => (count($buttons) > 0) ? $buttons : FALSE,
            'default' => 'f'
          );
        }
        else {
          $plugins[$file] = array(
            'name' => $file,
            'desc' => t('Plugin file: ' . $file),
            'path' => $plugin_dir . $file . '/',
            'buttons' => (count($buttons) > 0) ? $buttons : FALSE,
            'default' => 'f'
          );
        }
      }
    }
    closedir($handle);
  }

  /*
   * CKEditor module plugins - additional directory
   */
  $_plugin_dir_additional = ckeditor_plugins_path('local') . '/';
  if ($_plugin_dir != $_plugin_dir_additional && is_dir($_plugin_dir_additional) && $handle = opendir($_plugin_dir_additional)) {
    while (false !== ($file = readdir($handle))) {
      if (is_dir($_plugin_dir_additional . $file) && file_exists($_plugin_dir_additional . $file . '/plugin.js')) {
        $source = file_get_contents($_plugin_dir_additional . $file . '/plugin.js');
        $buttons = array();
        if (preg_match_all($pattern, $source, $matches)) {
          foreach ($matches[1] as $i => $button_name) {
            if (preg_match('#(icon)[\s]*\:[\s]*([^\,\n]*)#', $matches[2][$i], $matches2)) {
              $buttons[$button_name] = array();
              $buttons[$button_name]['label'] = $button_name;
              $matches2[2] = str_replace(array('this.path', '+', '\'', '"'), array('', '', '', ''), $matches2[2]);
              $buttons[$button_name]['icon'] = trim($matches2[2]);
            }
          }
        }
        if (preg_match('#@file ([^\n\r]*)#', $source, $matches)) {
          $plugins[$file] = array(
            'name' => $file,
            'desc' => t($matches[1]),
            'path' => $plugin_dir_additional . $file . '/',
            'buttons' => (count($buttons) > 0) ? $buttons : FALSE,
            'default' => 'f'
          );
        }
        else {
          $plugins[$file] = array(
            'name' => $file,
            'desc' => t('Plugin file: ' . $file),
            'path' => $plugin_dir_additional . $file . '/',
            'buttons' => (count($buttons) > 0) ? $buttons : FALSE,
            'default' => 'f'
          );
        }
      }
    }

    closedir($handle);
  }

  return $plugins;
}

/**
 * Implements hook_ckeditor_plugin_alter().
 */
function ckeditor_ckeditor_plugin_alter(&$plugins) {
  if (isset($plugins['media']) && module_exists('media') == FALSE) {
    unset($plugins['media']);
  }

  if (isset($plugins['imce']) && module_exists('imce') == FALSE) {
    unset($plugins['imce']);
  }
  //remove page break button if there is no module to do this
  if (isset($plugins['drupalbreaks']['buttons']['DrupalPageBreak']) && !module_exists('paging') && !module_exists('pagebreak')) {
    unset($plugins['drupalbreaks']['buttons']['DrupalPageBreak']);
  }

  if (isset($plugins['drupalbreaks'])) {
    $plugins['drupalbreaks']['default'] = 't';
  }

  /*
   * External plugins - complete hook info and adjust path
   * Workaround, until modules have adapted their hook implementations.
   * @see https://www.drupal.org/node/2159403#comment-9019373
   * @see https://www.drupal.org/node/2217579
   */
  $base_path = '%base_path%';

  if (isset($plugins['ckeditor_swf'])) {
    $plugins['ckeditor_swf']['default'] = 't';
    $plugins['ckeditor_swf']['path'] = '%base_path%' . $plugins['ckeditor_swf']['path'];
  }

  if (isset($plugins['ckeditor_link'])) {
    $plugins['ckeditor_link']['default'] = 't';
    $plugins['ckeditor_link']['path'] = '%base_path%' . $plugins['ckeditor_link']['path'];
  }

  if (isset($plugins['linkit'])) {
    $plugins['linkit']['default'] = 't';
    $plugins['linkit']['path'] = '%base_path%' . $plugins['linkit']['path'];
  }
}
