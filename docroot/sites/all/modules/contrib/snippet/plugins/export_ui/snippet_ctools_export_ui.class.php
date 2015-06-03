<?php
/**
 * @file
 * Class file for snippet export ui
 */

class snippet_ctools_export_ui extends ctools_export_ui {
  /**
   * Menu callback to determine if an operation is accessible.
   *
   * This function enforces a basic access check on the configured perm
   * string, and then additional checks as needed.
   *
   * @param string $op
   *   The 'op' of the menu item, which is defined by 'allowed operations'
   *   and embedded into the arguments in the menu item.
   * @param object $item
   *   If an op that works on an item, then the item object, otherwise NULL.
   *
   * @return bool
   *   TRUE if the current user has access, FALSE if not.
   */
  public function access($op, $item) {
    if (!user_access($this->plugin['manage access'])) {
      return FALSE;
    }

    // More fine-grained access control:
    if ($op == 'add' && !user_access($this->plugin['create access'])) {
      return FALSE;
    }

    // More fine-grained access control:
    if (($op == 'delete' || $op == 'version_delete') && !user_access($this->plugin['delete access'])) {
      return FALSE;
    }

    // More fine-grained access control:
    if (($op == 'revert' || $op == 'revertto' || $op == 'revision') && !user_access($this->plugin['manage access'])) {
      return FALSE;
    }

    // More fine-grained access control:
    if (($op == 'export' || $op == 'clone') && !user_access($this->plugin['access'])) {
      return FALSE;
    }

    // If we need to do a token test, do it here.
    if (!empty($this->plugin['allowed operations'][$op]['token'])
      && (!isset($_GET['token']) || !drupal_valid_token($_GET['token'], $op))) {
      return FALSE;
    }

    switch ($op) {
      case 'import':
        return user_access('use PHP for settings');

      case 'revert':
        return ($item->export_type & EXPORT_IN_DATABASE) && ($item->export_type & EXPORT_IN_CODE);

      case 'delete':
        return ($item->export_type & EXPORT_IN_DATABASE) && !($item->export_type & EXPORT_IN_CODE);

      case 'disable':
        return empty($item->disabled);

      case 'enable':
        return !empty($item->disabled);

      default:
        return TRUE;
    }
  }

  /**
   * Adding or editing snippet. A Drupal FAPI form.
   */
  public function edit_form(&$form, &$form_state) {
    // This is to show the preview.
    $form['snippet_preview_wrapper'] = array(
      '#prefix' => '<div id="snippet_preview">',
      '#suffix' => '</div>',
      '#markup' => '',
    );

    // Adding parent element.
    parent::edit_form($form, $form_state);
    if ($form_state['form type'] == 'clone') {
      $default_snippet = $this->load_item($form_state['original name']);
    }
    elseif ($form_state['form type'] == 'add') {
      $default_snippet = $form_state['item'];
      $default_snippet->rid = NULL;
      $default_snippet->content = '';
    }
    else {
      $default_snippet = $form_state['item'];
    }

    // Needs to disable the admin_tile and name (machine name) fields
    // and delete button for editing snippet.
    if ($form_state['op'] == 'edit') {
      $form['info']['admin_title']['#disabled'] = TRUE;
      $form['info']['name']['#disabled'] = TRUE;
      $form['buttons']['delete']['#access'] = FALSE;
    }

    $form['title'] = array(
      '#type' => 'textfield',
      '#title' => t('Title'),
      '#description' => t('Title for the textarea-exportible.'),
      '#default_value' => ($default_snippet->rid) ? $default_snippet->title_revision : $default_snippet->title,
    );

    $form['content'] = array(
      '#type' => 'text_format',
      '#title' => t('Content'),
      '#description' => t('Description of this snippet.'),
      '#default_value' => $default_snippet->content,
      '#format' => @$default_snippet->content_format,
    );

    $form['preview'] = array(
      '#type' => 'button',
      '#limit_validation_errors' => array(),
      '#value' => t('Preview'),
      '#submit' => array('snippet_build_preview'),
      '#ajax' => array(
        'callback' => 'snippet_form_build_preview_callback',
        'wrapper' => 'snippet_preview',
      ),
      '#weight' => 101,
    );

  }

  /**
   * Validation handler for $this->edit_form().
   */
  public function edit_form_validate(&$form, &$form_state) {
    $op = $form_state['op'];
    switch ($op) {
      case 'add':
        // Check if name already exists.
        ctools_include('export');
        $preset = ctools_export_crud_load($form_state['plugin']['schema'], $form_state['values']['name']);
        if ($preset) {
          form_set_error('name', 'Snippet already exists. Snippet names must be unique.');
        }
        break;
    }
  }

  /**
   * Loads the snippet data.
   *
   * @param string $item_name
   *   The name of the snippet to load.
   * @param int $rid
   *   The revision ID of the snippet, if needed.
   */
  public function load_item($item_name, $rid = NULL) {
    $snippet = ctools_export_crud_load($this->plugin['schema'], $item_name);

    $snippet_revision = db_select('snippet_revision', 'sr')
                        ->fields('sr', array())
                        ->condition('name', $item_name);
    if ($rid) {
      $snippet_revision = $snippet_revision->condition('rid', $rid);
    }
    else {
      $snippet_revision = $snippet_revision->condition('is_current', 1);
    }

    $snippet_revision = $snippet_revision->execute()->fetch();
    $snippet->content = !empty($snippet_revision->content) ? $snippet_revision->content : '';
    $snippet->content_format = !empty($snippet_revision->content_format) ? $snippet_revision->content_format : NULL;
    $snippet->timestamp = !empty($snippet_revision->timestamp) ? $snippet_revision->timestamp : NULL;
    $snippet->is_current = !empty($snippet_revision->is_current) ? $snippet_revision->is_current : NULL;
    $snippet->rid = !empty($snippet_revision->rid) ? $snippet_revision->rid : NULL;
    $snippet->title_revision = !empty($snippet_revision->title) ? $snippet_revision->title : NULL;

    return $snippet;
  }

  /**
   * Called to save the final product from the edit form.
   *
   * @param array $form_state
   *   A Drupal FAPI form state array.
   */
  public function edit_save_form($form_state) {
    $item = &$form_state['item'];
    $export_key = $this->plugin['export']['key'];

    $operation_type = $form_state['op'];

    // If snippet is being added for the first time then make entry in snippet
    // and snippet_revison table to have complete information.
    if ($operation_type == 'add') {
      $result = ctools_export_crud_save($this->plugin['schema'], $item);
      $result = _save_snippet($form_state['values']);
    }
    elseif ($operation_type == 'edit') {
      $result = _save_snippet($form_state['values']);
    }

    if ($result) {
      $message = str_replace('%title', check_plain($item->{$export_key}), $this->plugin['strings']['confirmation'][$form_state['op']]['success']);
      drupal_set_message($message);
    }
    else {
      $message = str_replace('%title', check_plain($item->{$export_key}), $this->plugin['strings']['confirmation'][$form_state['op']]['fail']);
      drupal_set_message($message, 'error');
    }
  }

  /**
   * Build a row based on the item.
   *
   * By default all of the rows are placed into a table by the render
   * method, so this is building up a row suitable for theme('table').
   * This doesn't have to be true if you override both.
   *
   * @param object $item
   *   The ctools snippet object.
   * @param array $form_state
   *   A Drupal FAPI form state array.
   * @param array $operations
   *   Array of operations to show in the table row.
   */
  public function list_build_row($item, &$form_state, $operations) {
    // Set up sorting.
    $name = $item->{$this->plugin['export']['key']};
    $schema = ctools_export_get_schema($this->plugin['schema']);

    // Note: $item->{$schema['export']['export type string']} should have
    // already been set up by export.inc so we can use it safely.
    switch ($form_state['values']['order']) {
      case 'disabled':
        $this->sorts[$name] = empty($item->disabled) . $name;
        break;

      case 'title':
        $this->sorts[$name] = $item->{$this->plugin['export']['admin_title']};
        break;

      case 'name':
        $this->sorts[$name] = $name;
        break;

      case 'storage':
        $this->sorts[$name] = $item->{$schema['export']['export type string']} . $name;
        break;
    }

    $this->rows[$name]['data'] = array();
    $this->rows[$name]['class'] = !empty($item->disabled) ? array('ctools-export-ui-disabled') : array('ctools-export-ui-enabled');

    // If we have an admin title, make it the first row.
    if (!empty($this->plugin['export']['admin_title'])) {
      $this->rows[$name]['data'][] = array('data' => check_plain($item->{$this->plugin['export']['admin_title']}), 'class' => array('ctools-export-ui-title'));
    }
    $this->rows[$name]['data'][] = array('data' => check_plain($name), 'class' => array('ctools-export-ui-name'));

    $this->rows[$name]['data'][] = array('data' => check_plain($item->{$schema['export']['export type string']}), 'class' => array('ctools-export-ui-storage'));

    // To display whether this has any description.
    $snippet = $this->load_item($name);
    $label = "No";
    if ($snippet->rid) {
      $label = 'Yes';
    }
    $this->rows[$name]['data'][] = array('data' => $label, 'class' => array('ctools-export-ui-title'));

    // Short down the list of operation as per permission.
    $snippet_operations = array();
    foreach ($operations as $key => $value) {
      $do_list = ($key == 'enable' || $key == 'disable') ? TRUE : $this->access($key, $item);
      if ($do_list) {
        $snippet_operations[$key] = $value;
      }
    }

    $ops = theme(
      'links__ctools_dropbutton',
      array(
        'links' => $snippet_operations,
        'attributes' => array('class' => array('links', 'inline')),
      )
    );

    $this->rows[$name]['data'][] = array('data' => $ops, 'class' => array('ctools-export-ui-operations'));

    // Add an automatic mouseover of the description if one exists.
    if (!empty($this->plugin['export']['admin_description'])) {
      $this->rows[$name]['title'] = $item->{$this->plugin['export']['admin_description']};
    }
  }

  /**
   * Provide the table header.
   *
   * If you've added columns via list_build_row() but are still using a
   * table, override this method to set up the table header.
   */
  function list_table_header() {
    $header = array();
    if (!empty($this->plugin['export']['admin_title'])) {
      $header[] = array('data' => t('Title'), 'class' => array('ctools-export-ui-title'));
    }

    $header[] = array('data' => t('Name'), 'class' => array('ctools-export-ui-name'));
    $header[] = array('data' => t('Storage'), 'class' => array('ctools-export-ui-storage'));
    $header[] = array('data' => t('Has Content/Revised'), 'class' => array('ctools-export-ui-name'));
    $header[] = array('data' => t('Operations'), 'class' => array('ctools-export-ui-operations'));

    return $header;
  }

  /**
   * Page callback to see revisions.
   *
   * @param string $js
   *   Not used.
   * @param string $input
   *   Not used.
   * @param object $item
   *   The ctools snippet object.
   */
  public function revision_page($js, $input, $item) {
    return snippet_revision_list($item);
  }

  /**
   * Page callback to revert to a specific version.
   *
   * @param string $js
   *   Not used.
   * @param string $input
   *   Not used.
   * @param object $item
   *   The ctools snippet object.
   */
  public function revertto_page($js, $input, $item) {
    // Hard-coded.
    $revision_id = arg(6);
    $revision = $this->load_item($item->name, $revision_id);
    return drupal_get_form('snippet_revision_revert', $revision);
  }

  /**
   * Page callback to view snippet.
   *
   * @param string $js
   *   Not used.
   * @param string $input
   *   Not used.
   * @param object $item
   *   The ctools snippet object.
   */
  public function view_page($js, $input, $item) {
    // Hard-coded.
    $revision_id = arg(6);
    $snippet_revision = $this->load_item($item->name, $revision_id);

    // Prepare array for theme.
    $variable['rid'] = $snippet_revision->rid;
    $variable['name'] = $item->name;

    $title = ($snippet_revision->rid) ? $snippet_revision->title_revision : $snippet->title;
    $title = trim($title);
    $variable['title'] = check_plain($title);
    $variable['content'] = check_markup($snippet_revision->content, $snippet_revision->content_format);

    return theme('snippet', $variable);
  }

  /**
   * Page callback to delete a specific version.
   *
   * @param string $js
   *   Not used.
   * @param string $input
   *   Not used.
   * @param object $item
   *   The ctools snippet object.
   */
  public function version_delete_page($js, $input, $item) {
    // Hard-coded.
    $revision_id = arg(6);
    $revision = $this->load_item($item->name, $revision_id);
    return drupal_get_form('snippet_version_delete', $revision);
  }

}

/**
 * Helper function to save the snippet data.
 *
 * @param array $values
 *   The form values to be saved.
 *
 * @return bool|int
 *   The return value from drupal_write_record().
 *
 * @see drupal_write_record()
 */
function _save_snippet($values) {
  // Need to set is_current to 0 before setting up the new one.
  _snippet_revision_reset_current($values['name']);

  $revision = new stdClass();
  $revision->name = $values['name'];
  $revision->title = $values['title'];
  $revision->content = $values['content']['value'];
  $revision->content_format = $values['content']['format'];
  $revision->timestamp = strtotime('now');
  $revision->is_current = 1;

  $status = drupal_write_record('snippet_revision', $revision);
  return $status;
}

/**
 * Reset the snippet's current state.
 *
 * @param string $name
 *   The name of the snippet whose status to reset.
 *
 * @return int
 *   The number of rows affected by the query.
 */
function _snippet_revision_reset_current($name) {
  $set_is_current = db_update('snippet_revision')
                    ->fields(array(
                      'is_current' => 0,
                    ))
                    ->condition('name', $name)
                    ->execute();
  return $set_is_current;
}


/**
 * Helper function for outputting the preview above the form.
 *
 * @param array $form
 *   The Drupal FAPI form. Not used.
 * @param array $form_state
 *   The Drupal FAPI form state array.
 *
 * @return array|bool
 *   A render array containing markup, or FALSE if the form has errors.
 */
function snippet_form_build_preview_callback($form, &$form_state) {
  // Display a preview of the snippet.
  if (!form_get_errors()) {
    $variable = array();
    $variable['rid'] = $form_state['values']['rid'];
    $variable['name'] = $form_state['values']['name'];
    $variable['title'] = check_plain($form_state['values']['title']);
    $variable['content'] = check_markup($form_state['values']['content']['value'], $form_state['values']['content']['format']);
    $variable['in_preview'] = 1;
    return array("#markup" => '<div id="snippet_preview">' . theme('snippet', $variable) . '</div>');
  }

  return FALSE;
}

/**
 * Build a preview of a snippet.
 *
 * @param array $form
 *   The Drupal FAPI form. Not used.
 * @param array $form_state
 *   The Drupal FAPI form state array.
 */
function snippet_build_preview($form, &$form_state) {
  $form_state['rebuild'] = TRUE;
}


/**
 * Generate an overview table of older revisions of a node.
 *
 * @param object $snippet
 *   The ctools snippet object.
 *
 * @return array
 *   A table expressed as a Drupal render array.
 */
function snippet_revision_list($snippet) {
  drupal_set_title(t('Revisions for %title', array('%title' => $snippet->admin_title)), PASS_THROUGH);

  $header = array(
    t('Revision'),
    array(
      'data' => t('Operations'),
      'colspan' => 2,
    ),
  );
  $snippet_revisions = db_select('snippet_revision', 'sr')
                      ->fields('sr', array())
                      ->condition('name', $snippet->name)
                      ->orderBy('is_current', 'DESC')
                      ->orderBy('rid', 'DESC')
                      ->execute()->fetchAll();

  $rows = array();
  $revert_permission = $delete_revision_permission = FALSE;

  if (user_access('manage snippet')) {
    $revert_permission = TRUE;
  }

  if (user_access('administer snippet')) {
    $delete_revision_permission = TRUE;
  }

  // If only a version available then don't show revert option.
  if (count($snippet_revisions) == 1) {
    $revert_permission = FALSE;
    $delete_revision_permission = FALSE;
  }

  // Assign a destination if available.
  $destination = drupal_get_destination();

  foreach ($snippet_revisions as $revision) {
    $row = array();
    $operations = array();
    $row['data']['revision'] = array(
      'data' => t('!date', array('!date' => format_date($revision->timestamp, 'short'))),
    );

    // Build a list of all the accessible operations for the current node.
    $operations['view'] = array(
      'title' => t('View'),
      'href' => SNIPPET_MENU_PREFIX . "/$snippet->name/revision/$revision->rid/view",
      'query' => $destination,
    );

    if ($revert_permission) {
      $operations['revert'] = array(
        'title' => t('Revert'),
        'href' => SNIPPET_MENU_PREFIX . "/$snippet->name/revision/$revision->rid/revertto",
        'query' => $destination,
      );
    }

    if ($delete_revision_permission) {
      $operations['delete-version'] = array(
        'title' => t('Delete'),
        'href' => SNIPPET_MENU_PREFIX . "/$snippet->name/revision/$revision->rid/delete",
        'query' => $destination,
      );
    }

    $row['data']['operations'] = array(
      'data' => array(
        '#theme' => 'links',
        '#links' => $operations,
        '#attributes' => array('class' => array('links', 'inline', 'nowrap')),
      ),
    );

    $rows[] = $row;
  }

  $build['snippet_revisions_table'] = array(
    '#theme' => 'table',
    '#rows' => $rows,
    '#header' => $header,
    '#empty' => t('There is no revisions for %title to list.', array('%title' => $snippet->admin_title)),
  );

  return $build;
}


/**
 * Ask for confirmation of the reversion to prevent against CSRF attacks.
 *
 * @param array $form
 *   The Drupal FAPI form.
 * @param array $form_state
 *   The Drupal FAPI form state array. Not used.
 * @param object $revision
 *   The snippet revision object.
 */
function snippet_revision_revert($form, $form_state, $revision) {
  $form['#revision'] = $revision;
  return confirm_form(
    $form,
    t(
      'Are you sure you want to revert to the revision from %revision-date?',
      array(
        '%revision-date' => format_date($revision->timestamp),
      )
    ),
    SNIPPET_MENU_PREFIX . "/$revision->name/revision",
    t(
      'This will revert the snippet %revision-title to revision %revision-date',
      array(
        '%revision-title' => $revision->title,
        '%revision-date'  => format_date($revision->timestamp),
      )
    ),
    t('Revert'),
    t('Cancel')
  );
}

/**
 * Revert to the given rid.
 *
 * @param array $form
 *   The Drupal FAPI form.
 * @param array $form_state
 *   The Drupal FAPI form state array.
 */
function snippet_revision_revert_submit($form, &$form_state) {
  $snippet_revision = $form['#revision'];

  _snippet_revision_reset_current($snippet_revision->name);

  $revision = new stdClass();
  $revision->rid = $snippet_revision->rid;
  $revision->is_current = 1;

  $status = drupal_write_record('snippet_revision', $revision, 'rid');

  watchdog(
    'snippet content',
    'Snippets reverted %title revision %revision.',
    array(
      '%title' => $snippet_revision->admin_title,
      '%revision' => $snippet_revision->rid,
    )
  );
  drupal_set_message(
    t('Snippets %title has been reverted back to the revision from %revision-date.',
      array(
        '%title' => $snippet_revision->admin_title,
        '%revision-date' => format_date($snippet_revision->timestamp),
      )
    )
  );
  $form_state['redirect'] = SNIPPET_MENU_PREFIX . "/$snippet_revision->name/revision";
}

/**
 * Ask for confirmation for the version delete to prevent against CSRF attacks.
 *
 * @param array $form
 *   The Drupal FAPI form.
 * @param array $form_state
 *   The Drupal FAPI form state array. Not used.
 * @param object $revision
 *   The snippet revision object.
 *
 * @return array
 *   The result of a call to confirm_form().
 *
 * @see confirm_form()
 */
function snippet_version_delete($form, $form_state, $revision) {
  $form['#revision'] = $revision;

  // If we are deleting the current version of drupal then we need to set new
  // current version.
  if ($revision->is_current) {
    $revision_id = _snippet_version_get_previous_recent($revision);
    $form['#snippet_new_current'] = $revision_id;
  }

  return confirm_form(
    $form,
    t(
      'Are you sure you want to delete this revision posted on %revision-date?',
      array(
        '%revision-date' => format_date($revision->timestamp),
      )
    ),
    SNIPPET_MENU_PREFIX . "/$revision->name/revision",
    t(
      'This will delete the snippet %revision-title posted on %revision-date',
      array(
        '%revision-title' => $revision->title,
        '%revision-date'  => format_date($revision->timestamp),
      )
    ),
    t('Delete'),
    t('Cancel')
  );
}

/**
 * Delete the verion to the given rid.
 *
 * @param array $form
 *   The Drupal FAPI form.
 * @param array $form_state
 *   The Drupal FAPI form state array.
 */
function snippet_version_delete_submit($form, &$form_state) {
  $snippet_revision = $form['#revision'];

  db_delete('snippet_revision')
    ->condition('rid', $snippet_revision->rid)
    ->execute();

  watchdog(
    'snippet content',
    'Revision for snippet %title posted on %revision-date has been deleted.',
    array(
      '%title' => $snippet_revision->admin_title,
      format_date($snippet_revision->timestamp),
    )
  );

  if (!empty($form['#snippet_new_current'])) {
    $new_current_revision_rid = $form['#snippet_new_current'];
    $new_current_revision = new stdClass();
    $new_current_revision->rid = $new_current_revision_rid;
    $new_current_revision->is_current = 1;
    $status = drupal_write_record('snippet_revision', $new_current_revision, 'rid');
    watchdog(
      'snippet content',
      'Snippet %title now has new current revision at %revision.',
      array(
        '%title' => $snippet_revision->admin_title,
        '%revision' => $snippet_revision->rid,
      )
    );
  }

  drupal_set_message(
    t(
      'Revision for snippet %title posted on %revision-date has been deleted',
      array(
        '%title' => $snippet_revision->admin_title,
        '%revision-date' => format_date($snippet_revision->timestamp),
      )
    )
  );
  $form_state['redirect'] = SNIPPET_MENU_PREFIX . "/$snippet_revision->name/revision";
}

/**
 * Get the most recent previous snippet revision.
 *
 * @param object $snippet
 *   The ctools snippet object.
 *
 * @return int
 *   The revision ID of the most recent previous revision.
 */
function _snippet_version_get_previous_recent($snippet) {
  $snippet_name = $snippet->name;
  $query = db_select('snippet_revision', 'sr')
    ->fields('sr', array('rid'))
    ->condition('name', $snippet_name)
    ->condition('is_current', 0)
    ->orderBy('timestamp', 'desc')
    ->range(0, 1);
  $revision_id = $query->execute()->fetchField();
  return $revision_id;
}
