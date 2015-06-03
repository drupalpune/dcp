<?php
/**
 * @file
 * dcp_rooms_and_slots.features.inc
 */

/**
 * Implements hook_default_cod_event_room().
 */
function dcp_rooms_and_slots_default_cod_event_room() {
  $items = array();
  $items['1'] = entity_import('cod_event_room', '{
    "name" : "Auditorium",
    "capacity" : "250",
    "weight" : 0,
    "evtrid" : "1",
    "og_group_ref" : { "und" : [ { "target_id" : "1" } ] }
  }');
  $items['2'] = entity_import('cod_event_room', '{
    "name" : "ClassRoom 1",
    "capacity" : "40",
    "weight" : 0,
    "evtrid" : "2",
    "og_group_ref" : { "und" : [ { "target_id" : "1" } ] }
  }');
  $items['3'] = entity_import('cod_event_room', '{
    "name" : "Computer Lab 1",
    "capacity" : "30",
    "weight" : 0,
    "evtrid" : "3",
    "og_group_ref" : { "und" : [ { "target_id" : "1" } ] }
  }');
  $items['4'] = entity_import('cod_event_room', '{
    "name" : "Computer Lab 2",
    "capacity" : "30",
    "weight" : 0,
    "evtrid" : "4",
    "og_group_ref" : { "und" : [ { "target_id" : "1" } ] }
  }');
  return $items;
}

/**
 * Implements hook_default_cod_event_time().
 */
function dcp_rooms_and_slots_default_cod_event_time() {
  $items = array();
  $items['1'] = entity_import('cod_event_time', '{
    "date_label" : "08\\/22\\/2015 - 08:30-08\\/22\\/2015 - 09:30",
    "evttid" : "1",
    "field_evttime_date" : { "und" : [
        {
          "value" : "2015-08-22 08:30:00",
          "value2" : "2015-08-22 09:30:00",
          "timezone" : "Asia\\/Kolkata",
          "offset" : "19800",
          "offset2" : "19800",
          "timezone_db" : "Asia\\/Kolkata",
          "date_type" : "datetime"
        }
      ]
    },
    "og_group_ref" : { "und" : [ { "target_id" : "1" } ] }
  }');
  $items['2'] = entity_import('cod_event_time', '{
    "date_label" : "08\\/22\\/2015 - 09:30-08\\/22\\/2015 - 11:00",
    "evttid" : "2",
    "field_evttime_date" : { "und" : [
        {
          "value" : "2015-08-22 09:30:00",
          "value2" : "2015-08-22 11:00:00",
          "timezone" : "Asia\\/Kolkata",
          "offset" : "19800",
          "offset2" : "19800",
          "timezone_db" : "Asia\\/Kolkata",
          "date_type" : "datetime"
        }
      ]
    },
    "og_group_ref" : { "und" : [ { "target_id" : "1" } ] }
  }');
  $items['3'] = entity_import('cod_event_time', '{
    "date_label" : "08\\/22\\/2015 - 11:00-08\\/22\\/2015 - 11:15",
    "evttid" : "3",
    "field_evttime_date" : { "und" : [
        {
          "value" : "2015-08-22 11:00:00",
          "value2" : "2015-08-22 11:15:00",
          "timezone" : "Asia\\/Kolkata",
          "offset" : "19800",
          "offset2" : "19800",
          "timezone_db" : "Asia\\/Kolkata",
          "date_type" : "datetime"
        }
      ]
    },
    "og_group_ref" : { "und" : [ { "target_id" : "1" } ] }
  }');
  $items['4'] = entity_import('cod_event_time', '{
    "date_label" : "08\\/22\\/2015 - 11:15-08\\/22\\/2015 - 12:00",
    "evttid" : "4",
    "field_evttime_date" : { "und" : [
        {
          "value" : "2015-08-22 11:15:00",
          "value2" : "2015-08-22 12:00:00",
          "timezone" : "Asia\\/Kolkata",
          "offset" : "19800",
          "offset2" : "19800",
          "timezone_db" : "Asia\\/Kolkata",
          "date_type" : "datetime"
        }
      ]
    },
    "og_group_ref" : { "und" : [ { "target_id" : "1" } ] }
  }');
  $items['5'] = entity_import('cod_event_time', '{
    "date_label" : "08\\/22\\/2015 - 12:15-08\\/22\\/2015 - 13:00",
    "evttid" : "5",
    "field_evttime_date" : { "und" : [
        {
          "value" : "2015-08-22 12:15:00",
          "value2" : "2015-08-22 13:00:00",
          "timezone" : "Asia\\/Kolkata",
          "offset" : "19800",
          "offset2" : "19800",
          "timezone_db" : "Asia\\/Kolkata",
          "date_type" : "datetime"
        }
      ]
    },
    "og_group_ref" : { "und" : [ { "target_id" : "1" } ] }
  }');
  $items['6'] = entity_import('cod_event_time', '{
    "date_label" : "08\\/22\\/2015 - 13:00-08\\/22\\/2015 - 14:00",
    "evttid" : "6",
    "field_evttime_date" : { "und" : [
        {
          "value" : "2015-08-22 13:00:00",
          "value2" : "2015-08-22 14:00:00",
          "timezone" : "Asia\\/Kolkata",
          "offset" : "19800",
          "offset2" : "19800",
          "timezone_db" : "Asia\\/Kolkata",
          "date_type" : "datetime"
        }
      ]
    },
    "og_group_ref" : { "und" : [ { "target_id" : "1" } ] }
  }');
  $items['7'] = entity_import('cod_event_time', '{
    "date_label" : "08\\/22\\/2015 - 14:15-08\\/22\\/2015 - 15:00",
    "evttid" : "7",
    "field_evttime_date" : { "und" : [
        {
          "value" : "2015-08-22 14:15:00",
          "value2" : "2015-08-22 15:00:00",
          "timezone" : "Asia\\/Kolkata",
          "offset" : "19800",
          "offset2" : "19800",
          "timezone_db" : "Asia\\/Kolkata",
          "date_type" : "datetime"
        }
      ]
    },
    "og_group_ref" : { "und" : [ { "target_id" : "1" } ] }
  }');
  $items['8'] = entity_import('cod_event_time', '{
    "date_label" : "08\\/22\\/2015 - 15:15-08\\/22\\/2015 - 16:00",
    "evttid" : "8",
    "field_evttime_date" : { "und" : [
        {
          "value" : "2015-08-22 15:15:00",
          "value2" : "2015-08-22 16:00:00",
          "timezone" : "Asia\\/Kolkata",
          "offset" : "19800",
          "offset2" : "19800",
          "timezone_db" : "Asia\\/Kolkata",
          "date_type" : "datetime"
        }
      ]
    },
    "og_group_ref" : { "und" : [ { "target_id" : "1" } ] }
  }');
  $items['9'] = entity_import('cod_event_time', '{
    "date_label" : "08\\/22\\/2015 - 16:00-08\\/22\\/2015 - 16:15",
    "evttid" : "9",
    "field_evttime_date" : { "und" : [
        {
          "value" : "2015-08-22 16:00:00",
          "value2" : "2015-08-22 16:15:00",
          "timezone" : "Asia\\/Kolkata",
          "offset" : "19800",
          "offset2" : "19800",
          "timezone_db" : "Asia\\/Kolkata",
          "date_type" : "datetime"
        }
      ]
    },
    "og_group_ref" : { "und" : [ { "target_id" : "1" } ] }
  }');
  $items['10'] = entity_import('cod_event_time', '{
    "date_label" : "08\\/22\\/2015 - 16:15-08\\/22\\/2015 - 17:00",
    "evttid" : "10",
    "field_evttime_date" : { "und" : [
        {
          "value" : "2015-08-22 16:15:00",
          "value2" : "2015-08-22 17:00:00",
          "timezone" : "Asia\\/Kolkata",
          "offset" : "19800",
          "offset2" : "19800",
          "timezone_db" : "Asia\\/Kolkata",
          "date_type" : "datetime"
        }
      ]
    },
    "og_group_ref" : { "und" : [ { "target_id" : "1" } ] }
  }');
  $items['11'] = entity_import('cod_event_time', '{
    "date_label" : "08\\/22\\/2015 - 17:15-08\\/22\\/2015 - 18:00",
    "evttid" : "11",
    "field_evttime_date" : { "und" : [
        {
          "value" : "2015-08-22 17:15:00",
          "value2" : "2015-08-22 18:00:00",
          "timezone" : "Asia\\/Kolkata",
          "offset" : "19800",
          "offset2" : "19800",
          "timezone_db" : "Asia\\/Kolkata",
          "date_type" : "datetime"
        }
      ]
    },
    "og_group_ref" : { "und" : [ { "target_id" : "1" } ] }
  }');
  return $items;
}
