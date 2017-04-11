<?php /**
 * @file
 * Contains \Drupal\responsive_menu\Plugin\Block\Toggle.
 */

namespace Drupal\responsive_menu\Plugin\Block;

use Drupal\Core\Block\BlockBase;

/**
 * Provides the Toggle block.
 *
 * @Block(
 *   id = "responsive_menu_toggle",
 *   admin_label = @Translation("Responsive menu mobile icon")
 * )
 */
class Toggle extends BlockBase {

  /**
   * {@inheritdoc}
   */
  public function build() {
    return array(
      '#theme' => 'responsive_menu_block_toggle',
    );
  }


}
