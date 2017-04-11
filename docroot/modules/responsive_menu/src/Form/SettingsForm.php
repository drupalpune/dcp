<?php

/**
 * @file
 * The settings form for the responsive menu module.
 */

namespace Drupal\responsive_menu\Form;

use Drupal\Core\Form\ConfigFormBase;
use Drupal\Core\Form\FormStateInterface;
use Drupal\Core\Link;
use Drupal\Core\Url;
use Drupal\Core\Cache\Cache;

/**
 * Form builder for the responsive_menu admin settings page.
 */
class SettingsForm extends ConfigFormBase {

  /**
   * {@inheritdoc}
   */
  public function getFormId() {
    return 'responsive_menu_settings';
  }

  /**
   * {@inheritdoc}
   */
  protected function getEditableConfigNames() {
    return ['responsive_menu.settings'];
  }

  /**
   * {@inheritdoc}
   */
  public function buildForm(array $form, FormStateInterface $form_state) {

    $form['responsive_menu'] = array(
      '#type' => 'fieldset',
      '#title' => t('Responsive menu'),
    );
    $form['responsive_menu']['horizontal_menu'] = array(
      '#type' => 'select',
      '#title' => t('Choose which Drupal menu will be rendered as a horizontal menu at the breakpoint width'),
      '#default_value' => \Drupal::config('responsive_menu.settings')->get('horizontal_menu'),
      '#options' => $this->getMenuOptions(),
    );
    $form['responsive_menu']['horizontal_depth'] = array(
      '#type' => 'select',
      '#title' => t('A maximum menu depth that the horizontal menu should display'),
      '#default_value' => \Drupal::config('responsive_menu.settings')->get('horizontal_depth'),
      '#options' => array_combine(array(1, 2, 3, 4, 5, 6, 7, 8, 9), array(1, 2, 3, 4, 5, 6, 7, 8, 9)),
      '#description' => t('The mobile menu will always allow all depths to be navigated to. This only controls what menu depth you want to display on the horizontal menu. It can be useful if you want a single row of items because you are handling secondary level and lower in a separate block.'),
    );
    $form['responsive_menu']['off_canvas'] = array(
      '#type' => 'fieldset',
      '#title' => t('Off canvas'),
    );
    $form['responsive_menu']['off_canvas']['off_canvas_menus'] = array(
      '#type' => 'textfield',
      '#title' => t('Enter the name(s) of Drupal menus to be rendered in an off-canvas menu'),
      '#description' => t('Enter the names of menus in a comma delimited format. If more than one menu is entered the menu items will be merged together. This is useful if you have a main menu and a utility menu that display separately at wider screen sizes but should be merged into a single menu at smaller screen sizes. Note that the menus will be merged in the entered order.'),
      '#default_value' => \Drupal::config('responsive_menu.settings')->get('off_canvas_menus'),
    );
    $form['responsive_menu']['horizontal_wrapping_element'] = array(
      '#type' => 'select',
      '#title' => t('Choose the HTML element to wrap the menu block in'),
      '#default_value' => \Drupal::config('responsive_menu.settings')->get('horizontal_wrapping_element'),
      '#options' => array(
        'nav' => 'nav',
        'div' => 'div',
      ),
    );
    $form['responsive_menu']['use_breakpoint'] = array(
      '#type' => 'checkbox',
      '#title' => t('Use a breakpoint'),
      '#description' => t("Unchecking this will disable the breakpoint and your mobile menu icon block will always display (assuming you have placed it on the page). This can be useful if you always want to display the mobile menu icon and don't want a horizontal menu at all, or if you want to control the visibility and breakpoints in your theme's css. Note that the horizontal menu block, if placed, will only be visible if this is checked."),
      '#default_value' => \Drupal::config('responsive_menu.settings')->get('use_breakpoint'),
    );
    // Breakpoints.
    $queries = responsive_menu_get_breakpoints();
    $form['responsive_menu']['horizontal_breakpoint'] = array(
      '#type' => 'select',
      '#title' => t('Choose a breakpoint to trigger the desktop format menu at'),
      '#default_value' => \Drupal::config('responsive_menu.settings')->get('horizontal_breakpoint'),
      '#options' => $queries,
      '#states' => array(
        'visible' => array(
          ':input[name="use_breakpoint"]' => array('checked' => TRUE),
        ),
      ),
    );
    if (empty($queries)) {
      $form['responsive_menu']['horizontal_breakpoint']['#disabled'] = TRUE;
      $form['responsive_menu']['horizontal_breakpoint']['#description'] = '<div class="description">' . t('You must configure at least one @breakpoint to see any options. Until then the select widget above is disabled.', array(
          '@breakpoint' => \Drupal::l('breakpoint', Url::fromUri('https://www.drupal.org/documentation/modules/breakpoint')),
        )) . '</div>';

    }
    // Whether to load the base css.
    $form['responsive_menu']['css'] = array(
      '#type' => 'checkbox',
      '#title' => t("Load the responsive_menu module's css"),
      '#description' => t('It might be that you want to override all of the css that comes with the responsive_menu module in which case you can disable the loading of the css here and include it instead in your theme.'),
      '#default_value' => \Drupal::config('responsive_menu.settings')->get('include_css'),
    );
    // Left or right positioned panel.
    $form['responsive_menu']['position'] = array(
      '#type' => 'select',
      '#options' => array(
        'left' => t('Left'),
        'right' => t('Right'),
      ),
      '#title' => t('Which side the mobile menu panel should slide out from'),
      '#default_value' => \Drupal::config('responsive_menu.settings')->get('off_canvas_position'),
    );
    // The theme of the slideout panel.
    $form['responsive_menu']['theme'] = array(
      '#type' => 'select',
      '#options' => array(
        'theme-light' => t('Light'),
        'theme-dark' => t('Dark'),
        'theme-black' => t('Black'),
        'theme-white' => t('White'),
      ),
      '#title' => t('Which mmenu theme to use'),
      '#default_value' => \Drupal::config('responsive_menu.settings')->get('off_canvas_theme'),
    );
    // A javascript enhancements fieldset.
    $form['responsive_menu']['js'] = array(
      '#type' => 'fieldset',
      '#title' => t('Javascript enhancements'),
    );
    $form['responsive_menu']['js']['superfish'] = array(
      '#type' => 'checkbox',
      '#title' => t('Apply Superfish to the horizontal menu'),
      '#description' => t('Adds the @superfish library functionality to the horizontal menu. This enhances the menu with better support for hovering and support for mobiles.', array(
        '@superfish' => \Drupal::l('Superfish', Url::fromUri('https://github.com/joeldbirch/superfish')),
      )),
      '#default_value' => \Drupal::config('responsive_menu.settings')->get('horizontal_superfish'),
    );
    $form['responsive_menu']['js']['superfish_options'] = array(
      '#type' => 'fieldset',
      '#title' => t('Superfish options'),
      '#states' => array(
        'visible' => array(
          ':input[name="superfish"]' => array('checked' => TRUE),
        ),
      ),
    );
    $form['responsive_menu']['js']['superfish_options']['superfish_delay'] = array(
      '#type' => 'textfield',
      '#title' => t('Delay'),
      '#description' => t('The amount of time in milliseconds a menu will remain after the mouse leaves it.'),
      '#default_value' => \Drupal::config('responsive_menu.settings')->get('horizontal_superfish_delay'),
    );
    $form['responsive_menu']['js']['superfish_options']['superfish_speed'] = array(
      '#type' => 'textfield',
      '#title' => t('Speed'),
      '#description' => t('The amount of time in milliseconds it takes for a menu to reach 100% opacity when it opens.'),
      '#default_value' => \Drupal::config('responsive_menu.settings')->get('horizontal_superfish_speed'),
    );
    $form['responsive_menu']['js']['superfish_options']['superfish_speed_out'] = array(
      '#type' => 'textfield',
      '#title' => t('Speed out'),
      '#description' => t('The amount of time in milliseconds it takes for a menu to reach 0% opacity when it closes.'),
      '#default_value' => \Drupal::config('responsive_menu.settings')->get('horizontal_superfish_speed_out'),
    );
    $form['responsive_menu']['js']['superfish_options']['superfish_hoverintent'] = array(
      '#type' => 'checkbox',
      '#title' => t('Use hoverintent'),
      '#description' => t("Whether to use the @hoverintent plugin with superfish. This library is included in the superfish download and doesn't require separate installation.", array(
        '@hoverintent' => \Drupal::l('hoverIntent', Url::fromUri('http://cherne.net/brian/resources/jquery.hoverIntent.html')),
      )),
      '#default_value' => \Drupal::config('responsive_menu.settings')->get('horizontal_superfish_hoverintent'),
    );
    // Whether the optional superfish library is to be used.
    if (!file_exists(DRUPAL_ROOT . '/libraries/superfish/dist/js/superfish.min.js')) {
      $form['responsive_menu']['js']['superfish']['#disabled'] = TRUE;
      $form['responsive_menu']['js']['superfish']['#description'] .= '<br/><span class="warning">' . t('You need to download the @superfish library and place it in a /libraries directory. Until then the superfish option is disabled.', array(
          '@superfish' => \Drupal::l('superfish', Url::fromUri('https://github.com/joeldbirch/superfish/archive/master.zip')),
        )) . '</span>';
    }
    // The hammer js library is optional.
    $form['responsive_menu']['js']['hammerjs'] = array(
      '#type' => 'checkbox',
      '#title' => t('Add swipe gestures'),
      '#description' => t('Adds the hammer.js library to enhance the mobile experience with swipe gestures to open or close the menu.'),
      '#default_value' => \Drupal::config('responsive_menu.settings')->get('hammerjs'),
    );
    // If the libraries module isn't installed or if the hammer.min.js
    // file isn't in the correct location then disable the hammer option
    // and display an appropriate message.
    if (!file_exists(DRUPAL_ROOT . '/libraries/hammerjs/hammer.min.js')) {
      $form['responsive_menu']['js']['hammerjs']['#disabled'] = TRUE;
      $form['responsive_menu']['js']['hammerjs']['#description'] .= '<br/><span class="warning">' . t('You must download the @hammer file and place it in a hammerjs directory in /libraries. Until then the hammerjs option is disabled.', array(
          '@hammer' => \Drupal::l('hammer.min.js', Url::fromUri('http://hammerjs.github.io/dist/hammer.min.js')),
        )) . '</span>';
    }

    return parent::buildForm($form, $form_state);
  }

  /**
   * {@inheritdoc}
   */
  public function validateForm(array &$form, FormStateInterface $form_state) {
    // Ensure there are breakpoints configured.
    $values = $form_state->getValues();
    if ($values['use_breakpoint'] && empty($values['horizontal_breakpoint'])) {
      $breakpoint_message = Link::fromTextAndUrl('breakpoint file', Url::fromUri('https://www.drupal.org/node/1803874'))->toRenderable();
      $form_state->setErrorByName('horizontal_breakpoint', $this->t("You have chosen to use a breakpoint but you have not selected one. This may happen if your @breakpoint is not properly set up.", array(
        '@breakpoint' => render($breakpoint_message),
      )));
    }
  }

  /**
   * {@inheritdoc}
   */
  public function submitForm(array &$form, FormStateInterface $form_state) {

    $values = $form_state->getValues();

    // Save all the submitted form values into config.
    \Drupal::configFactory()
      ->getEditable('responsive_menu.settings')
      ->set('horizontal_menu', $values['horizontal_menu'])
      ->set('horizontal_depth', $values['horizontal_depth'])
      ->set('horizontal_wrapping_element', $values['horizontal_wrapping_element'])
      ->set('use_breakpoint', $values['use_breakpoint'])
      ->set('include_css', $values['css'])
      ->set('off_canvas_menus', $values['off_canvas_menus'])
      ->set('off_canvas_position', $values['position'])
      ->set('off_canvas_theme', $values['theme'])
      ->set('horizontal_superfish', $values['superfish'])
      ->set('horizontal_superfish_delay', $values['superfish_delay'])
      ->set('horizontal_superfish_speed', $values['superfish_speed'])
      ->set('horizontal_superfish_speed_out', $values['superfish_speed_out'])
      ->set('horizontal_superfish_hoverintent', $values['superfish_hoverintent'])
      ->set('hammerjs', $values['hammerjs'])
      ->save();

    // Handle the breakpoint.
    $queries = responsive_menu_get_breakpoints();
    // Check if the breakpoint exists and the user has chosen
    // to use a breakpoint.
    if ($values['use_breakpoint'] && isset($queries[$values['horizontal_breakpoint']])) {
      // Store the breakpoint for using again in the form.
      \Drupal::configFactory()
        ->getEditable('responsive_menu.settings')
        ->set('horizontal_breakpoint', $values['horizontal_breakpoint'])
        // Also store the actual breakpoint string for use in calling
        // the stylesheet.
        ->set('horizontal_media_query', $queries[$values['horizontal_breakpoint']])
        ->save();

      // Generate the breakpoint css file.
      $breakpoint = \Drupal::config('responsive_menu.settings')->get('horizontal_media_query');
      responsive_menu_generate_breakpoint_css($breakpoint);
    }

    // Invalidate the block cache for the horizontal menu so these settings get
    // applied when rebuilding the block on view.
    Cache::invalidateTags(array('config:block.block.horizontalmenu'));

    parent::submitForm($form, $form_state);
  }

  /**
   * Gets a list of menu names for use as options.
   *
   * @param array $menu_names
   *   (optional) Array of menu names to limit the options, or NULL to load all.
   *
   * @return array
   *   Keys are menu names (ids) values are the menu labels.
   */
  protected function getMenuOptions(array $menu_names = NULL) {
    $menus = \Drupal::entityManager()->getStorage('menu')->loadMultiple($menu_names);
    $options = array();
    /** @var \Drupal\system\MenuInterface[] $menus */
    foreach ($menus as $menu) {
      $options[$menu->id()] = $menu->label();
    }
    return $options;
  }

}
