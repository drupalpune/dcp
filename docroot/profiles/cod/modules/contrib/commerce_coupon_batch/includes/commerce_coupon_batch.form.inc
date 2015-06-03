<?php

// Constant for coupons to generate per batch api run.
define('COMMERCE_COUPON_BATCH_MULTIPASS_SIZE', 5);

/**
 * @file
 * Coupon Batch forms for Drupal Commerce
 *
 * This file contains form data for...
 */

/**
 * Generates the commerce coupon editing form.
 */
function commerce_coupon_batch_form($form, &$form_state, $coupon) {
  $form_state['build_info']['files']['form'] = drupal_get_path('module', 'commerce_coupon_batch') . '/includes/commerce_coupon_batch.form.inc';
  $form_state['commerce_coupon'] = $coupon;  
  
  $form['batch_size'] = array(
    '#title' => t('Batch size'),
    '#type' => 'textfield',
    '#description' => t('Enter the number of coupons which should be generated.'),
    '#element_validate' => array('element_validate_integer_positive'),
    '#size' => 30,
  );
  
  // Add code paramters.
  $form['code'] = array(
    '#type' => 'fieldset',
    '#title' => t('Coupon parameters'),
    '#tree' => TRUE
  );
  
  $form['code']['prefix'] = array(
    '#type' => 'textfield',
    '#title' => t('Prefix'),
    '#size' => 10,
    '#description' => t('Prefix for generated coupon codes.'),      
  );
  
  $form['code']['suffix'] = array(
    '#type' => 'textfield',
    '#title' => t('Suffix'),
    '#size' => 10,
    '#description' => t('Suffix for generated coupon codes.'),    
  );  
  
  $form['commerce_coupon_fields'] = array(
    '#type' => 'container',
    '#parents' => array('commerce_coupon_fields')
  );

  // Attach the couupon form.
  field_attach_form('commerce_coupon', $coupon, $form['commerce_coupon_fields'], $form_state);
  
  // Status
  $form['status'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enabled'),
    '#default_value' => $coupon->status,
  );  

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Process'),
    '#weight' => 40,
  );

  return $form;
}

/*
 * Form validate callback: validate coupon batch form.
 */
function commerce_coupon_batch_form_validate(&$form, &$form_state) {
  $values = &$form_state['values'];

  // Strip invalid chars; @see commerce_coupon_generate_coupon_code().
  $values['code']['suffix'] = preg_replace('/[^a-z0-9]*/i', '', $values['code']['suffix']);
  $values['code']['prefix'] = preg_replace('/[^a-z0-9-]*/i', '', $values['code']['prefix']);
  
  field_attach_form_validate('commerce_coupon', $form_state['commerce_coupon'], $form, $form_state);
}


/**
 * Form submit callback: submit coupon batch form.
 */
function commerce_coupon_batch_form_submit(&$form, &$form_state) {

  // Base commerce coupon object for cloning.
  $template_coupon = $form_state['commerce_coupon'];
  
  // Attach fields.
  field_attach_submit('commerce_coupon', $template_coupon, $form, $form_state);

  $params = $form_state['values']['code'];
  $params['n'] = $form_state['values']['batch_size'];
  $params['status'] = $form_state['values']['status'];
  
  $batch = array(
    'operations' => array(
      array('commerce_coupon_batch_create_process', array($template_coupon, $params))
    ),
    'finished' => 'commerce_coupon_batch_create_finished',
    'file' => drupal_get_path('module', 'commerce_coupon_batch') . '/includes/commerce_coupon_batch.form.inc',
    'progress_message' => t('Processing ...')
  );    
  
  batch_set($batch);
}

/*
 * Batch worker callback: process a batch of coupon creations.
 */
function commerce_coupon_batch_create_process($template_coupon, $params, &$context) {
  if (empty($context['sandbox'])) {
    $context['sandbox']['max'] = $params['n'];
    $context['sandbox']['progress'] = 0;
  }

  $sandbox =& $context['sandbox'];
  $max = (int) $sandbox['max'];
  $progress =& $sandbox['progress'];
  $remaining = $max - $progress;

  // Create coupons until the multipass batch size is reached, or we run out of
  // coupons to create.
  $counter = 0;
  $limit = $remaining < COMMERCE_COUPON_BATCH_MULTIPASS_SIZE ? $remaining : COMMERCE_COUPON_BATCH_MULTIPASS_SIZE;  
  global $user;
  
  while ($counter < $limit) {
    $context['message'] = t('Creating coupon @n of @max', array('@n' => $progress, '@max' => $max));
    
    $coupon = clone $template_coupon;
    
    // Assign unique code body.
    $code_body = commerce_coupon_generate_coupon_code($coupon->type);
    $coupon->bulk = TRUE;
    $coupon->uid = $user->uid;
    $coupon->code = $params['prefix'] . $code_body . $params['suffix'];
    $coupon->status = $params['status'];
    
    // Save coupon.
    commerce_coupon_save($coupon);
    
    $context['results'][] = $coupon->code;
    
    // Increment the counter
    $counter++;
    $progress++;
  }
  
  // Update progress
  if ($progress != $max) {
    $context['finished'] = $progress / $max;
  }  
}

/*
 * Batch finished callback: display batch statistics
 */
function commerce_coupon_batch_create_finished($success, $results, $operations) {
  if ($success) {
    // Display success message. 
    $message = t('Created @n coupons.', array('@n' => count($results)));
    drupal_set_message($message);
  }
  else {
    // Report the last error.
    $error_operation = reset($operations);
    $message = t('An error occurred while processing %error_operation with arguments: @arguments', array('%error_operation' => $error_operation[0], '@arguments' => print_r($error_operation[1], TRUE)));
    
    drupal_set_message($message, 'error');
  }
}
