<?php
/**
 * @file
 * Field hooks.
 */

/**
 *  Implements hook_field_info().
 */
function ticket_state_field_info() {
  return array(
    'list_ticket_state' => array(
      'label' => t('Ticket State'),
      'description' => t("This field stores the default ticket state values in a 'value => label' pairs."),
      'settings' => array('allowed_values' => array(), 'allowed_values_function' => ''),
      'default_widget' => 'options_select',
      'default_formatter' => 'list_default',
      // Entity API Property Support
      'property_type' => 'text',
    ),
  );
}

/**
 * Implements hook_field_settings_form().
 */
function ticket_state_field_settings_form($field, $instance, $has_data) {
  $settings = $field['settings'];
  switch ($field['type']) {
    case 'list_ticket_state':
      $form['allowed_values'] = array(
        '#type' => 'value',
        '#value' => ticket_state_get_states_options(),
        '#field_has_data' => $has_data,
        '#field' => $field,
        '#multiple' => TRUE,
        '#field_type' => $field['type'],
      );
      break;
  }

  $form['allowed_values_function'] = array(
    '#type' => 'value',
    '#value' => $settings['allowed_values_function'],
  );

  return $form;
}

/**
 * Element validate callback; check that the entered values are valid.
 */
function ticket_state_allowed_values_setting_validate($element, &$form_state) {
  $field = $element['#field'];
  $has_data = $element['#field_has_data'];
  $field_type = $field['type'];

  $values = array_intersect_key(ticket_state_get_states_options(),$element['#value']);

  if (!is_array($values)) {
    form_error($element, t('Allowed values list: invalid input.'));
  }
  else {
    // Check that keys are valid for the field type.
    foreach ($values as $key => $value) {
      if ($field_type == 'list_ticket_state' && !in_array($key,array_keys(ticket_state_get_states_options()))) {
        form_error($element, t('Allowed values list: keys must be a machine content type.'));
        break;
      }
    }

    form_set_value($element, $values, $form_state);
  }
}

/**
 * Implements hook_field_update_field().
 */
function ticket_state_field_update_field($field, $prior_field, $has_data) {
  drupal_static_reset('ticket_state_allowed_values');
}

/**
 * Returns the array of allowed values for a list field.
 *
 * The strings are not safe for output. Keys and values of the array should be
 * sanitized through field_filter_xss() before being displayed.
 *
 * @param $field
 *   The field definition.
 * @param $instance
 *   (optional) A field instance array. Defaults to NULL.
 * @param $entity_type
 *   (optional) The type of entity; e.g. 'node' or 'user'. Defaults to NULL.
 * @param $entity
 *   (optional) The entity object. Defaults to NULL.
 *
 * @return
 *   The array of allowed values. Keys of the array are the raw stored values
 *   (number or text), values of the array are the display labels.
 */
function ticket_state_allowed_values($field, $instance = NULL, $entity_type = NULL, $entity = NULL) {
  $allowed_values = &drupal_static(__FUNCTION__, array());

  if (!isset($allowed_values[$field['id']])) {
    $function = $field['settings']['allowed_values_function'];
    // If $cacheable is FALSE, then the allowed values are not statically
    // cached. See list_test_dynamic_values_callback() for an example of
    // generating dynamic and uncached values.
    $cacheable = TRUE;
    if (!empty($function) && function_exists($function)) {
      $values = $function($field, $instance, $entity_type, $entity, $cacheable);
    }
    else {
      $values = ticket_state_get_states_options();
    }

    if ($cacheable) {
      $allowed_values[$field['id']] = $values;
    }
    else {
      return $values;
    }
  }

  return $allowed_values[$field['id']];
}

/**
 * Parses a string of 'allowed values' into an array.
 *
 * @param $string
 *   The list of allowed values in string format described in
 *   list_allowed_values_string().
 * @param $field_type
 *   The field type. Either 'list_number' or 'list_text'.
 *
 * @return
 *   The array of extracted key/value pairs, or NULL if the string is invalid.
 *
 * @see list_allowed_values_string()
 */
function ticket_state_extract_allowed_values($string, $field_type) {
  $values = array();

  $list = explode("\n", $string);
  $list = array_map('trim', $list);
  $list = array_filter($list, 'strlen');

  $generated_keys = $explicit_keys = FALSE;
  foreach ($list as $position => $text) {
    $value = $key = FALSE;

    // Check for an explicit key.
    $matches = array();
    if (preg_match('/(.*)\|(.*)/', $text, $matches)) {
      $key = $matches[1];
      $value = $matches[2];
      $explicit_keys = TRUE;
    }
    // Otherwise see if we can use the value as the key. Detecting true integer
    // strings takes a little trick.
    elseif ($field_type == 'list_text'
    || ($field_type == 'list_float' && is_numeric($text))
    || ($field_type == 'list_integer' && is_numeric($text) && (float) $text == intval($text))) {
      $key = $value = $text;
      $explicit_keys = TRUE;
    }
    // Otherwise see if we can generate a key from the position.
    elseif ($generate_keys) {
      $key = (string) $position;
      $value = $text;
      $generated_keys = TRUE;
    }
    else {
      return;
    }

    // Float keys are represented as strings and need to be disambiguated
    // ('.5' is '0.5').
    if ($field_type == 'list_float' && is_numeric($key)) {
      $key = (string) (float) $key;
    }

    $values[$key] = $value;
  }

  // We generate keys only if the list contains no explicit key at all.
  if ($explicit_keys && $generated_keys) {
    return;
  }

  return $values;
}

/**
 * Generates a string representation of an array of 'allowed values'.
 *
 * This string format is suitable for edition in a textarea.
 *
 * @param $values
 *   An array of values, where array keys are values and array values are
 *   labels.
 *
 * @return
 *   The string representation of the $values array:
 *    - Values are separated by a carriage return.
 *    - Each value is in the format "value|label" or "value".
 */
function ticket_state_allowed_values_string($values) {
  $lines = array();
  foreach ($values as $key => $value) {
    $lines[] = "$key|$value";
  }
  return implode("\n", $lines);
}

/**
 * Implements hook_field_update_forbid().
 */
function ticket_state_field_update_forbid($field, $prior_field, $has_data) {
  if ($field['module'] == 'list' && $has_data) {
    // Forbid any update that removes allowed values with actual data.
    $lost_keys = array_diff(array_keys($prior_field['settings']['allowed_values']), array_keys($field['settings']['allowed_values']));
    if (_list_values_in_use($field, $lost_keys)) {
      throw new FieldUpdateForbiddenException(t('A list field (@field_name) with existing data cannot have its keys changed.', array('@field_name' => $field['field_name'])));
    }
  }
}

/**
 * Implements hook_field_validate().
 *
 * Possible error codes:
 * - 'list_illegal_value': The value is not part of the list of allowed values.
 */
function ticket_state_field_validate($entity_type, $entity, $field, $instance, $langcode, $items, &$errors) {
  $allowed_values = ticket_state_allowed_values($field, $instance, $entity_type, $entity);
  foreach ($items as $delta => $item) {
    if (!empty($item['value'])) {
      if (!empty($allowed_values) && !isset($allowed_values[$item['value']])) {
        $errors[$field['field_name']][$langcode][$delta][] = array(
          'error' => 'list_illegal_value',
          'message' => t('%name: illegal value.', array('%name' => $instance['label'])),
        );
      }
    }
  }
}

/**
 * Implements hook_field_is_empty().
 */
function ticket_state_field_is_empty($item, $field) {
  if (!$item['value']) {
    return TRUE;
  }
  return FALSE;
}

/**
 * Implements hook_field_widget_info_alter().
 *
 * The List module does not implement widgets of its own, but reuses the
 * widgets defined in options.module.
 *
 * @see list_options_list()
 */
function ticket_state_field_widget_info_alter(&$info) {
  $widgets = array(
    'options_select' => array('list_ticket_state'),
    'options_buttons' => array('list_ticket_state'),
  );

  foreach ($widgets as $widget => $field_types) {
    $info[$widget]['field types'] = array_merge($info[$widget]['field types'], $field_types);
  }
}

/**
 * Implements hook_options_list().
 */
function ticket_state_options_list($field, $instance, $entity_type, $entity) {
  return ticket_state_get_states_options();
}

function ticket_state_field_attach_form($entity_type, $entity, &$form, &$form_state, $langcode) {
  if ($entity_type == 'ticket_registration' && isset($entity->state)) {
    $form['state'] = array(
      '#type' => 'select',
      '#title' => t('Registration State'),
      '#options' => ticket_state_get_states_options(),
      '#default_value' => !empty($entity->state) ? $entity->state : '',
      '#weight' => 50,
    );
  }
}