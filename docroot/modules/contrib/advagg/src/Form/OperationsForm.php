<?php

namespace Drupal\advagg\Form;

use Drupal\Core\Cache\Cache;
use Drupal\Core\Cache\CacheBackendInterface;
use Drupal\Core\Config\ConfigFactoryInterface;
use Drupal\Core\Datetime\DateFormatterInterface;
use Drupal\Core\File\FileSystemInterface;
use Drupal\Core\Form\ConfigFormBase;
use Drupal\Core\Form\FormStateInterface;
use Drupal\Core\PrivateKey;
use Drupal\Component\Utility\Crypt;
use Symfony\Component\DependencyInjection\ContainerInterface;

/**
 * Configure advagg settings for this site.
 */
class OperationsForm extends ConfigFormBase {

  /**
   * The private key service.
   *
   * @var \Drupal\Core\PrivateKey
   */
  protected $privateKey;

  /**
   * The date formatter service.
   *
   * @var \Drupal\Core\Datetime\DateFormatterInterface
   */
  protected $dateFormatter;

  /**
   * The AdvAgg cache.
   *
   * @var \Drupal\Core\Cache\CacheBackendInterface
   */
  protected $cache;

  /**
   * The File System service.
   *
   * @var \Drupal\Core\File\FileSystemInterface
   */
  protected $fileSystem;

  /**
   * Constructs the OperationsForm object.
   *
   * @param \Drupal\Core\Config\ConfigFactoryInterface $config_factory
   *   The factory for configuration objects.
   * @param \Drupal\Core\PrivateKey $private_key
   *   The private key service.
   * @param \Drupal\Core\Datetime\DateFormatterInterface $date_formatter
   *   The Date formatter service.
   * @param \Drupal\Core\Cache\CacheBackendInterface $cache
   *   The AdvAgg cache.
   * @param \Drupal\Core\File\FileSystemInterface $file_system
   *   The File System service.
   */
  public function __construct(ConfigFactoryInterface $config_factory, PrivateKey $private_key, DateFormatterInterface $date_formatter, CacheBackendInterface $cache, FileSystemInterface $file_system) {
    parent::__construct($config_factory);
    $this->privateKey = $private_key;
    $this->dateFormatter = $date_formatter;
    $this->cache = $cache;
    $this->fileSystem = $file_system;
  }

  /**
   * {@inheritdoc}
   */
  public static function create(ContainerInterface $container) {
    return new static(
      $container->get('config.factory'),
      $container->get('private_key'),
      $container->get('date.formatter'),
      $container->get('cache.advagg'),
      $container->get('file_system')
    );
  }

  /**
   * {@inheritdoc}
   */
  public function getFormId() {
    return 'advagg_operations';
  }

  /**
   * {@inheritdoc}
   */
  protected function getEditableConfigNames() {
    return ['advagg.settings'];
  }

  /**
   * {@inheritdoc}
   */
  public function buildForm(array $form, FormStateInterface $form_state) {
    // Explain what can be done on this page.
    $form['tip'] = [
      '#markup' => '<p>' . t('This is a collection of commands to control the cache and to manage testing of this module. In general this page is useful when troubleshooting some aggregation issues. For normal operations, you do not need to do anything on this page below the Smart Cache Flush. There are no configuration options here.') . '</p>',
    ];
    $form['wrapper'] = [
      '#prefix' => "<div id='operations-wrapper'>",
      '#suffix' => "</div>",
    ];

    // Set/Remove Bypass Cookie.
    $form['bypass'] = [
      '#type' => 'fieldset',
      '#title' => t('Aggregation Bypass Cookie'),
      '#description' => t('This will set or remove a cookie that disables aggregation for a set period of time.'),
    ];
    $form['bypass']['timespan'] = [
      '#type' => 'select',
      '#title' => 'Bypass length',
      '#options' => [
        21600 => t('6 hours'),
        43200 => t('12 hours'),
        86400 => t('1 day'),
        172800 => t('2 days'),
        604800 => t('1 week'),
        2592000 => t('1 month'),
        31536000 => t('1 year'),
      ],
    ];
    $form['bypass']['submit'] = [
      '#type' => 'submit',
      '#value' => t('Toggle The "aggregation bypass cookie" For This Browser'),
      '#attributes' => [
        'onclick' => 'javascript:return advagg_toggle_cookie()',
      ],
      '#submit' => ['::toggleBypassCookie'],
    ];
    // Add in aggregation bypass cookie javascript.
    $form['#attached']['drupalSettings']['advagg'] = [
      'key' => Crypt::hashBase64($this->privateKey->get()),
    ];
    $form['#attached']['library'][] = 'advagg/admin.operations';

    // Tasks run by cron.
    $form['cron'] = [
      '#type' => 'details',
      '#open' => TRUE,
      '#title' => t('Cron Maintenance Tasks'),
      'description' => [
        '#markup' => t('The following operation is ran on cron but you can run it manually here.'),
      ],
    ];
    $form['cron']['wrapper'] = [
      '#prefix' => "<div id='cron-wrapper'>",
      '#suffix' => "</div>",
    ];
    $form['cron']['smart_file_flush'] = [
      '#type' => 'fieldset',
      '#title' => t('Clear Stale Files'),
      '#description' => t('Scan all files in the css/js optimized directories and remove outdated ones.'),
    ];
    $form['cron']['smart_file_flush']['advagg_flush_stale_files'] = [
      '#type' => 'submit',
      '#value' => t('Remove All Stale Files'),
      '#submit' => ['::clearStaleAggregates'],
      '#ajax' => [
        'callback' => '::cronTasksAjax',
        'wrapper' => 'cron-wrapper',
      ],
    ];

    // Hide drastic measures as they should not be done unless really needed.
    $form['drastic_measures'] = [
      '#type' => 'details',
      '#title' => t('Drastic Measures'),
      '#description' => t('The options below should normally never need to be done.'),
    ];
    $form['drastic_measures']['wrapper'] = [
      '#prefix' => "<div id='drastic-measures-wrapper'>",
      '#suffix' => "</div>",
    ];
    $form['drastic_measures']['dumb_cache_flush'] = [
      '#type' => 'fieldset',
      '#title' => t('Clear All Caches'),
      '#description' => t('Remove all entries from the advagg cache and file information stores. Useful if you suspect a cache is not getting cleared.'),
    ];
    $form['drastic_measures']['dumb_cache_flush']['advagg_flush_all_caches'] = [
      '#type' => 'submit',
      '#value' => t('Clear All Caches & File Information'),
      '#submit' => ['::clearAggregates'],
      '#ajax' => [
        'callback' => '::drasticTasksAjax',
        'wrapper' => 'drastic-measures-wrapper',
      ],
    ];
    $form['drastic_measures']['force_change'] = [
      '#type' => 'fieldset',
      '#title' => t('Force new files'),
      '#description' => t('Force the creation of all new optimized files by incrementing a global counter. Current value of counter: %value. This is useful if a CDN has cached a file incorrectly as it will force new ones to be used even if nothing else has changed.', [
        '%value' => $this->config('advagg.settings')->get('global_counter'),
      ]),
    ];
    $form['drastic_measures']['force_change']['increment_global_counter'] = [
      '#type' => 'submit',
      '#value' => t('Increment Global Counter'),
      '#submit' => ['::incrementCounter'],
      '#ajax' => [
        'callback' => '::drasticTasksAjax',
        'wrapper' => 'drastic-measures-wrapper',
      ],
    ];
    return parent::buildForm($form, $form_state);
  }

  /**
   * Report results via Ajax.
   *
   * @param array $form
   *   An associative array containing the structure of the form.
   *
   * @return array
   *   The wrapper element.
   */
  public function tasksAjax(array &$form) {
    return $form['wrapper'];
  }

  /**
   * Clear out all advagg cache bins and clear out all advagg aggregated files.
   */
  public function clearAggregates() {
    // Clear out the cache.
    Cache::invalidateTags(['library_info']);
    $this->cache->invalidateAll();
    $pub = $this->fileSystem->realpath('public://');
    $css_count = count(glob($pub . '/css/optimized/*.css'));
    $js_count = count(glob($pub . '/js/optimized/*.js'));
    file_unmanaged_delete_recursive('public://js/optimized/');
    file_unmanaged_delete_recursive('public://css/optimized/');

    // Report back the results.
    drupal_set_message(t('All AdvAgg optimized files have been deleted. %css_count CSS files and %js_count JS files have been removed.', [
      '%css_count' => $css_count,
      '%js_count' => $js_count,
    ]));
  }

  /**
   * Clear out all stale advagg aggregated files.
   */
  public function clearStaleAggregates() {
    $counts = advagg_cron(TRUE);

    // Report back the results.
    if (!empty($counts['css']) || !empty($counts['js'])) {
      drupal_set_message(t('All stale aggregates have been deleted. %css_count CSS files and %js_count JS files have been removed.', [
        '%css_count' => count($counts['css']),
        '%js_count' => count($counts['js']),
      ]));
    }
    else {
      drupal_set_message(t('No stale aggregates found. Nothing was deleted.'));
    }
  }

  /**
   * Increment the global counter. Also full cache clear.
   */
  public function incrementCounter() {
    // Clear out the cache and delete aggregates.
    $this->clearAggregates();

    // Increment counter.
    $new_value = $this->config('advagg.settings')->get('global_counter') + 1;
    $this->config('advagg.settings')
      ->set('global_counter', $new_value)
      ->save();
    drupal_set_message(t('Global counter is now set to %new_value', [
      '%new_value' => $new_value,
    ]));
  }

  /**
   * Report results from the drastic measure tasks via Ajax.
   *
   * @param array $form
   *   An associative array containing the structure of the form.
   *
   * @return array
   *   The wrapper element.
   */
  public function drasticTasksAjax(array &$form) {
    return $form['drastic_measures']['wrapper'];
  }

  /**
   * Report results from the cron tasks via Ajax.
   *
   * @param array $form
   *   An associative array containing the structure of the form.
   *
   * @return array
   *   The wrapper element.
   */
  public function cronTasksAjax(array &$form) {
    return $form['cron']['wrapper'];
  }

  /**
   * Set or remove the AdvAggDisabled cookie.
   *
   * @param array $form
   *   An associative array containing the structure of the form.
   * @param \Drupal\Core\Form\FormStateInterface $form_state
   *   The current state of the form.
   */
  public function toggleBypassCookie(array &$form, FormStateInterface $form_state) {
    $cookie_name = 'AdvAggDisabled';
    $key = Crypt::hashBase64($this->privateKey->get());

    // If the cookie does exist then remove it.
    if (!empty($_COOKIE[$cookie_name]) && $_COOKIE[$cookie_name] == $key) {
      setcookie($cookie_name, '', -1, $GLOBALS['base_path'], '.' . $_SERVER['HTTP_HOST']);
      unset($_COOKIE[$cookie_name]);
      drupal_set_message(t('AdvAgg Bypass Cookie Removed.'));
    }
    // If the cookie does not exist then set it.
    else {
      setcookie($cookie_name, $key, REQUEST_TIME + $form_state->getValue('timespan'), $GLOBALS['base_path'], '.' . $_SERVER['HTTP_HOST']);
      $_COOKIE[$cookie_name] = $key;
      drupal_set_message(t('AdvAgg Bypass Cookie Set for %time.', [
        '%time' => $this->dateFormatter->formatInterval($form_state->getValue('timespan')),
      ]));
    }
    $this->clearAggregates();
  }

}
