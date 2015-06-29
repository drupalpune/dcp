<?php
/**
 * @file
 * Contains \Drupal\recaptcha\Form\ReCaptchaAdminSettingsForm.
 */

namespace Drupal\recaptcha\Form;

use Drupal\Core\Form\ConfigFormBase;
use Drupal\Core\Form\FormStateInterface;
use Drupal\Core\Url;

/**
 * Configure reCAPTCHA settings for this site.
 */
class ReCaptchaAdminSettingsForm extends ConfigFormBase {

  /**
   * {@inheritdoc}
   */
  public function getFormId() {
    return 'recaptcha_admin_settings';
  }

  /**
   * {@inheritdoc}
   */
  protected function getEditableConfigNames() {
    return ['recaptcha.settings'];
  }

  /**
   * {@inheritdoc}
   */
  public function buildForm(array $form, FormStateInterface $form_state) {
    $config = $this->config('recaptcha.settings');

    $form['general'] = [
      '#type' => 'details',
      '#title' => t('General settings'),
      '#open' => TRUE,
    ];

    $form['general']['recaptcha_site_key'] = [
      '#default_value' => $config->get('site_key'),
      '#description' => t('The site key given to you when you <a href="@url">register for reCAPTCHA</a>.', ['@url' => 'http://www.google.com/recaptcha/admin']),
      '#maxlength' => 40,
      '#required' => TRUE,
      '#title' => t('Site key'),
      '#type' => 'textfield',
    ];

    $form['general']['recaptcha_secret_key'] = [
      '#default_value' => $config->get('secret_key'),
      '#description' => t('The secret key given to you when you <a href="@url">register for reCAPTCHA</a>.', ['@url' => 'http://www.google.com/recaptcha/admin']),
      '#maxlength' => 40,
      '#required' => TRUE,
      '#title' => t('Secret key'),
      '#type' => 'textfield',
    ];

    // Widget configurations.
    $form['widget'] = [
      '#type' => 'details',
      '#title' => t('Widget settings'),
      '#open' => TRUE,
    ];
    $form['widget']['recaptcha_theme'] = [
      '#default_value' => $config->get('widget.theme'),
      '#description' => t('Defines which theme to use for reCAPTCHA.'),
      '#options' => [
        'light' => t('Light (default)'),
        'dark' => t('Dark'),
      ],
      '#title' => t('Theme'),
      '#type' => 'select',
    ];
    $form['widget']['recaptcha_type'] = [
      '#default_value' => $config->get('widget.type'),
      '#description' => t('The type of CAPTCHA to serve.'),
      '#options' => [
        'image' => t('Image (default)'),
        'audio' => t('Audio'),
      ],
      '#title' => t('Type'),
      '#type' => 'select',
    ];
    $form['widget']['recaptcha_size'] = [
      '#default_value' => $config->get('widget.size'),
      '#description' => t('The size of CAPTCHA to serve.'),
      '#options' => [
        '' => t('Normal (default)'),
        'small' => t('Small'),
      ],
      '#title' => t('Size'),
      '#type' => 'select',
    ];
    $form['widget']['recaptcha_tabindex'] = [
      '#default_value' => $config->get('widget.tabindex'),
      '#description' => t('Set the <a href="@tabindex">tabindex</a> of the widget and challenge (Default = 0). If other elements in your page use tabindex, it should be set to make user navigation easier.', ['@tabindex' => Url::fromUri('http://www.w3.org/TR/html4/interact/forms.html', ['fragment' => 'adef-tabindex'])->toString()]),
      '#maxlength' => 4,
      '#title' => t('Tabindex'),
      '#type' => 'textfield',
    ];
    $form['widget']['recaptcha_noscript'] = [
      '#default_value' => $config->get('widget.noscript'),
      '#description' => t('If JavaScript is a requirement for your site, you should <strong>not</strong> enable this feature. With this enabled, a compatibility layer will be added to the captcha to support non-js users.'),
      '#title' => t('Enable fallback for browsers with JavaScript disabled'),
      '#type' => 'checkbox',
    ];

    return parent::buildForm($form, $form_state);
  }

  /**
   * {@inheritdoc}
   */
  public function validateForm(array &$form, FormStateInterface $form_state) {
    parent::validateForm($form, $form_state);

    $tabindex = $form_state->getValue('recaptcha_tabindex');
    if (!is_numeric($tabindex)) {
      $form_state->setErrorByName('recaptcha_tabindex', t('The tabindex must be an integer.'));
    }
  }

  /**
   * {@inheritdoc}
   */
  public function submitForm(array &$form, FormStateInterface $form_state) {
    $config = $this->config('recaptcha.settings');
    $config
      ->set('site_key', $form_state->getValue('recaptcha_site_key'))
      ->set('secret_key', $form_state->getValue('recaptcha_secret_key'))
      ->set('widget.theme', $form_state->getValue('recaptcha_theme'))
      ->set('widget.type', $form_state->getValue('recaptcha_type'))
      ->set('widget.tabindex', $form_state->getValue('recaptcha_tabindex'))
      ->set('widget.noscript', $form_state->getValue('recaptcha_noscript'))
      ->save();

    parent::submitForm($form, $form_state);
  }

}
