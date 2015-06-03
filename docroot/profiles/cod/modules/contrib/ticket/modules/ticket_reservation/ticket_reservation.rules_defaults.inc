<?php
/**
 * @file
 * commerce_billy.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function ticket_reservation_default_rules_configuration() {
  $items = array();
  $items['rules_ticket_registration_cancelled_code'] = entity_import('rules_config', '{ "rules_ticket_registration_cancelled_code" : {
          "LABEL" : "Ticket Registration is cancelled",
          "PLUGIN" : "reaction rule",
          "OWNER" : "rules",
          "REQUIRES" : [ "rules", "ticket_reservation" ],
          "ON" : { "ticket_reservation_cancel_ticket" : [] },
          "DO" : [
            { "mail" : {
                "to" : "[acting-user:mail]",
                "subject" : "Your ticket for Drupalcon has been cancelled. ",
                "message" : "Hello [acting-user:name],\r\n\r\nYour ticket has been successfully cancelled. You can redeem the ticket here: http:\/\/events.drupal.org\/ticket\/redeem\r\n\r\nThe code is: [ticket:reservation_code]",
                "language" : [ "ticket:entity-type" ]
              }
            }
          ]
        }
      }');
  return $items;
}
