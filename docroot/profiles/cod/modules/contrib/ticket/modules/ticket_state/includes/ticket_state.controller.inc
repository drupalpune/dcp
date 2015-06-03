<?php

/**
 * The controller class used for ticket registration state entities
 */
class TicketStateController extends EntityAPIControllerExportable {

  public function save($entity, DatabaseTransaction $transaction = NULL) {
    parent::save($entity, $transaction);
  }

}
