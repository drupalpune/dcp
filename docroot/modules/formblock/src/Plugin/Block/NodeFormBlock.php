<?php

namespace Drupal\formblock\Plugin\Block;

use Drupal\Core\Block\BlockBase;
use Drupal\Core\Block\Annotation\Block;
use Drupal\Core\Annotation\Translation;
use Drupal\Core\Session\AccountInterface;
use Drupal\Core\Form\FormStateInterface;
use Drupal\Component\Utility\Xss;
use Drupal\Core\Plugin\ContainerFactoryPluginInterface;
use Drupal\node\Entity\NodeType;
use Symfony\Component\DependencyInjection\ContainerInterface;
use Drupal\Core\Entity\EntityManagerInterface;
use Drupal\Core\Extension\ModuleHandlerInterface;
use Drupal\Core\Language\LanguageManagerInterface;
use Drupal\Core\Entity\EntityFormBuilderInterface;

/**
 * Provides a block for node forms.
 *
 * @Block(
 *   id = "formblock_node",
 *   admin_label = @Translation("Node form"),
 *   provider = "node"
 * )
 *
 * Note that we set module to node so that blocks will be disabled correctly
 * when the module is disabled.
 */
class NodeFormBlock extends BlockBase implements ContainerFactoryPluginInterface {

  /**
   * The entity manager.
   *
   * @var \Drupal\Core\Entity\EntityManagerInterface
   */
  protected $entityManager;

  /**
   * The entity form builder.
   *
   * @var \Drupal\Core\Entity\EntityFormBuilderInterface.
   */
  protected $entityFormBuilder;

  /**
   * Constructs a new NodeFormBlock plugin
   *
   * @param array $configuration
   *   A configuration array containing information about the plugin instance.
   * @param string $plugin_id
   *   The plugin_id for the plugin instance.
   * @param mixed $plugin_definition
   *   The plugin implementation definition.
   * @param \Drupal\Core\Entity\EntityManagerInterface $entityManger
   *   The entity manager.
   * @param \Drupal\Core\Entity\EntityFormBuilderInterface $entityFormBuilder
   *   The entity form builder.
   */
  public function __construct(array $configuration, $plugin_id, $plugin_definition, EntityManagerInterface $entityManager, EntityFormBuilderInterface $entityFormBuilder) {
    parent::__construct($configuration, $plugin_id, $plugin_definition);
    $this->setConfiguration($configuration);

    $this->entityManager = $entityManager;
    $this->entityFormBuilder = $entityFormBuilder;
  }

  /**
   * {@inheritdoc}
   */
  public static function create(ContainerInterface $container, array $configuration, $plugin_id, $plugin_definition) {
    return new static(
      $configuration,
      $plugin_id,
      $plugin_definition,
      $container->get('entity.manager'),
      $container->get('entity.form_builder')
    );
  }

  /**
   * Overrides \Drupal\block\BlockBase::settings().
   */
  public function defaultConfiguration() {
    return array(
      'type' => NULL,
      'show_help' => FALSE,
    );
  }

  /**
   * Overrides \Drupal\block\BlockBase::blockForm().
   */
  public function blockForm($form, FormStateInterface $form_state) {
    $form['formblock_node_type'] = array(
      '#title' => $this->t('Node type'),
      '#description' => $this->t('Select the node type whose form will be shown in the block.'),
      '#type' => 'select',
      '#required' => TRUE,
      '#options' => node_type_get_names(),
      '#default_value' => $this->configuration['type'],
    );
    $form['formblock_show_help'] = array(
      '#type' => 'checkbox',
      '#title' => $this->t('Show submission guidelines'),
      '#default_value' => $this->configuration['show_help'],
      '#description' => $this->t('Enable this option to show the submission guidelines in the block above the form.'),
    );

    return $form;
  }

  /**
   * Overrides \Drupal\block\BlockBase::blockSubmit().
   */
  public function blockSubmit($form, FormStateInterface $form_state) {
    $this->configuration['type'] = $form_state->getValue('formblock_node_type');
    $this->configuration['show_help'] = $form_state->getValue('formblock_show_help');
  }

  /**
   * Implements \Drupal\block\BlockBase::build().
   */
  public function build() {
    $build = array();

    $node_type = NodeType::load($this->configuration['type']);

    if ($this->configuration['show_help']) {
      $build['help'] = array('#markup' => !empty($node_type->getHelp()) ? '<p>' . Xss::filterAdmin($node_type->getHelp()) . '</p>' : '');
    }

    $node = $this->entityManager->getStorage('node')->create(array(
      'type' => $node_type->id(),
    ));

    $build['form'] = $this->entityFormBuilder->getForm($node);

    return $build;
  }

  /**
   * Implements \Drupal\block\BlockBase::blockAccess().
   */
  public function blockAccess(AccountInterface $account) {
    $access_control_handler = $this->entityManager->getAccessControlHandler('node');
    return $access_control_handler->createAccess($this->configuration['type'], $account, array(), TRUE);
  }
}
