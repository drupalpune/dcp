<?php
/**
 * @file
 * Ticket Type entity class.
 */

/**
 * Provides an entity class Ticket Type.
 */
class TicketRegistration extends Entity {

  // Allow access to Ticket Type properties.
  public $trid;
  public $revision_id;
  // Essentially ttid is the bundle.
  public $bundle;
  public $label;
  public $user_uid;
  public $author_uid;
  public $created;
  public $changed;

  /**
   * Construct.
   */
  public function __construct(array $values = array()) {
    parent::__construct($values, 'ticket_registration');
  }

  /**
   * Helper function get the registrations label
   */
  public function label() {
    return ticket_registration_label($this, 'entity_registration');
  }
  /**
   * A helper function to get a registration's ticket type entity.
   */
  public function ticket_type() {
    return entity_load_single('ticket_type', $this->bundle);
  }

  /**
   * A helper function to get a registration's host entity.
   */
  public function host() {
    return entity_load_single($this->ticket_type()->entity_type, $this->ticket_type()->entity_id);
  }

  /**
   * A helper function to get a registration's author user.
   */
  public function registrant() {
    return entity_load_single('user', $this->author_uid);
  }

  /**
   * A helper function to get a registration's attendee user.
   */
  public function attendee() {
    return entity_load_single('user', $this->user_uid);
  }

  /**
   * Build content for Registration.
   *
   * @return array
   *   Render array for a registration entity.
   */
  public function buildContent($view_mode = 'full', $langcode = NULL) {
    $build = parent::buildContent($view_mode, $langcode);
    $wrapper = entity_metadata_wrapper('ticket_registration', $this);

    $host_entity_type_info = entity_get_info($this->bundle);
    $host_entity = $this->ticket_type();
    $author = $this->registrant();
    $user = $this->attendee();
    list(, , $host_entity_bundle) = entity_extract_ids($this->bundle, $host_entity);

    $host_label = entity_label($this->bundle, $host_entity);

    $host_uri = $host_entity ? entity_uri($this->bundle, $host_entity) : NULL;

    $build['created'] = array(
      '#prefix' => '<div class="field registration-created"><div class="field-label">' . t('Created') . '</div>',
      '#markup' => format_date($this->created),
      '#suffix' => '</div>',
      '#weight' => -10,
    );

    $build['updated'] = array(
      '#prefix' => '<div class="field registration-updated"><div class="field-label">' . t('Updated') . '</div>',
      '#markup' => format_date($this->changed),
      '#suffix' => '</div>',
      '#weight' => -9,
    );

    $build['author'] = array(
      '#prefix' => '<div class="field registration-author"><div class="field-label">' . t('Registrant') . '</div>',
      '#theme' => 'username',
      '#account' => $author,
      '#suffix' => '</div>',
      '#weight' => -8,
    );

    $build['user'] = array(
      '#prefix' => '<div class="field registration-user"><div class="field-label">' . t('Attendee') . '</div>',
      '#theme' => 'username',
      '#account' => $user,
      '#suffix' => '</div>',
      '#weight' => -7,

    );

    return $build;
  }
}

class TicketRegistrationUIController extends EntityContentUIController {

  /**
   * Implements hook_menu().
   */
  public function hook_menu() {
    // Provide standard entity ui routes for registrations.
    $items = parent::hook_menu();

    $id_count = count(explode('/', $this->path));
    $wildcard = isset($this->entityInfo['admin ui']['menu wildcard']) ? $this->entityInfo['admin ui']['menu wildcard'] : '%entity_object';
    $plural_label = isset($this->entityInfo['plural label']) ? $this->entityInfo['plural label'] : $this->entityInfo['label'] . 's';

    // Remove any management links. We're defining some of these in
    // the ticket_type entity and field_ui will provide the rest.
    foreach (array_keys($items) as $path) {
      if (strpos($path, $this->path . '/manage/') === 0) {
        unset ($items[$path]);
      }
    }

    return $items;
  }

}

/**
 * @file
 *
 * Contains the controller for ticket_registration entities.
 */
class TicketRegistrationController extends EntityAPIController {

  public function create(array $values = array()) {
    global $user;
    $values['uid'] = $user->uid;
    return parent::create($values);
  }

  public function load($registrations = array(), $conditions = array()) {
    global $user;

    $entities = parent::load($registrations, $conditions);
    foreach ($entities AS $entity_id => $entity) {
      // When loading an entity, we default the author uid, unless there is an
      // Overriding user_uid for the current user, then override.
      if ($entity->user_uid == $user->uid) {
        $uid = $user->uid;
      }
      // Is the registration empty? if its not owned by anyone, current user can
      // take control of it.
      else if ($entity->author_uid == 0) {
        $uid = $user->uid;
      }
      else {
        $uid = $entity->author_uid;
      }
      $entities[$entity_id]->uid = $uid;
    }
    return $entities;
  }

  /**
   * Saves a ticket registration entity.
   */
  public function save($registration, DatabaseTransaction $transaction = NULL) {
    $registration->changed = REQUEST_TIME;
    parent::save($registration, $transaction);
  }
}
