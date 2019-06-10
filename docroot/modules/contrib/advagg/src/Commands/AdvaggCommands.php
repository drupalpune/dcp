<?php

namespace Drupal\advagg\Commands;

use Drupal\Core\Cache\Cache;
use Drupal\Core\Cache\CacheBackendInterface;
use Drupal\Core\Config\ConfigFactoryInterface;
use Drush\Commands\DrushCommands;

/**
 * Advagg commands for Drush 9+.
 */
class AdvaggCommands extends DrushCommands {

  /**
   * An editable config object for the advagg configuration.
   *
   * @var \Drupal\Core\Config\Config
   */
  protected $config;

  /**
   * The AdvAgg cache.
   *
   * @var \Drupal\Core\Cache\CacheBackendInterface
   */
  protected $cache;

  /**
   * Constructs the commands instance.
   *
   * @param \Drupal\Core\Config\ConfigFactoryInterface $config_factory
   *   A config factory for retrieving required config objects.
   * @param \Drupal\Core\Cache\CacheBackendInterface $cache
   *   The AdvAgg cache.
   */
  public function __construct(ConfigFactoryInterface $config_factory, CacheBackendInterface $cache) {
    $this->config = $config_factory->getEditable('advagg.settings');
    $this->cache = $cache;
  }

  /**
   * Run the advagg cron hook.
   *
   * @command advagg-cron
   * @usage Standard example
   *   drush advagg-cron
   * @aliases advagg-c
   */
  public function cron() {
    // Run AdvAgg cron job.
    $output = advagg_cron(TRUE);

    if (!empty($output['css']) || !empty($output['js'])) {
      $this->logger()->notice(dt('All stale aggregates have been deleted. %css_count CSS files and %js_count JS files have been removed.', [
        '%css_count' => count($output['css']),
        '%js_count' => count($output['js']),
      ]));
    }
    else {
      $this->logger()->notice(dt('No stale aggregates found. Nothing was deleted.'));
    }
  }

  /**
   * Disable Advagg.
   *
   * @command advagg-disable
   * @usage Standard example
   *   drush advagg-disable
   * @aliases advagg-da
   */
  public function disable() {
    $this->config->set('enabled', 0)->save();
    $this->logger()->notice(dt('All Advagg functionality is disabled.'));
  }

  /**
   * Enable Advagg.
   *
   * @command advagg-enable
   * @usage Standard example
   *   drush advagg-enable
   * @aliases advagg-en
   */
  public function enable() {
    $this->config->set('enabled', 1)->save();
    $this->logger()->notice(dt('All Advagg functionality is enabled.'));
  }

  /**
   * Remove all generated files.
   *
   * @command advagg-clear-all-files
   * @usage Standard example
   *   drush advagg-clear-all-files
   * @aliases advagg-caf
   */
  public function clearAllFiles() {
    // Clear out the cache.
    Cache::invalidateTags(['library_info']);
    $this->cache->invalidateAll();
    $pub = \Drupal::service('file_system')->realpath('public://');
    $css_count = count(glob($pub . '/css/optimized/*.css'));
    $js_count = count(glob($pub . '/js/optimized/*.js'));
    file_unmanaged_delete_recursive('public://js/optimized/');
    file_unmanaged_delete_recursive('public://css/optimized/');

    // Report back the results.
    $this->logger()->notice(dt('All AdvAgg optimized files have been deleted. %css_count CSS files and %js_count JS files have been removed.', [
      '%css_count' => $css_count,
      '%js_count' => $js_count,
    ]));
  }

  /**
   * Force the creation of all new files by incrementing a global counter.
   *
   * @command advagg-force-new-aggregates
   * @usage Standard example
   *   drush advagg-force-new-aggregates
   * @aliases advagg-fna
   */
  public function forceNewAggregates() {
    // Clear out the cache.
    $this->clearAllFiles();

    // Increment counter.
    $new_value = $this->config->get('global_counter') + 1;
    $this->config->set('global_counter', $new_value)->save();
    $this->logger()->notice(dt('Global counter is now set to @new_value', ['@new_value' => $new_value]));
    _drupal_flush_css_js();
  }

}
