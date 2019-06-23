<?php

namespace Drupal\social_media_links\Plugin\SocialMediaLinks\Platform;

use Drupal\social_media_links\PlatformBase;
use Drupal\Core\Form\FormStateInterface;
use Egulias\EmailValidator\EmailValidator;
use Drupal\Core\Url;

/**
 * Provides 'email' platform.
 *
 * @Platform(
 *   id = "email",
 *   name = @Translation("E-Mail"),
 * )
 */
class Email extends PlatformBase {

  /**
   * {@inheritdoc}
   */
  public function getUrl() {
    return Url::fromUri('mailto:' . $this->getValue());
  }

  /**
   * {@inheritdoc}
   */
  public static function validateValue(array &$element, FormStateInterface $form_state, array $form) {
    if (!empty($element['#value'])) {
      $validator = new EmailValidator();

      if (!$validator->isValid($element['#value'], TRUE)) {
        $form_state->setError($element, t('The entered email address is not valid.'));
      }
    }
  }

}
