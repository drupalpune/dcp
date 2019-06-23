<?php

namespace Drupal\social_media_links\Plugin\SocialMediaLinks\Iconset;

use Drupal\social_media_links\IconsetBase;
use Drupal\social_media_links\IconsetInterface;

/**
 * Provides 'webtoolkit' iconset.
 *
 * @Iconset(
 *   id = "webtoolkit",
 *   name = "webtoolkit Icon Set",
 *   publisher = "webtoolkit4.me",
 *   publisherUrl = "http://webtoolkit4.me",
 *   downloadUrl = "http://webtoolkit4.me/2008/09/05/webtoolkit4me-releases-the-first-icon-set",
 * )
 */
class Webtoolkit extends IconsetBase implements IconsetInterface {

  /**
   * {@inheritdoc}
   */
  public function getStyle() {
    return [
      '24' => '24x24',
      '32' => '32x32',
      '48' => '48x48',
      '62' => '62x62',
    ];
  }

  /**
   * {@inheritdoc}
   */
  public function getIconPath($icon_name, $style) {
    return $this->path . '/PNG/' . $icon_name . '.png';
  }

}
