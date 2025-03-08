#ifndef NREL_H
#define NREL_H

#include <curl/curl.h>
#include <json-c/json.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *get_curl_memory();

struct IO
{
    const char *json_file; // Immutable: Defined as const
    FILE *stream;
};

struct LIBCURL
{
    CURL *curl;
    CURLcode code;
};

struct STACK
{
    char item[20];
    int ptr;
    int size;
}; 

struct LIST
{
    char *station_locator_url;
    int total_results;
    char *access_code;
    char *access_days_time;
    char *access_detail_code;
    char *cards_accepted;
    char *date_last_confirmed;
    char *expected_date;
    char *fuel_type_code;
    char *groups_with_access_code;
    int id;
    char *maximum_vehicle_class;
    char *open_date;
    char *owner_type_code;
    char *restricted_access;
    char *status_code;
    char *funding_sources;
    char *facility_type;
    char *station_name;
    char *station_phone;
    char *updated_at;
    char *geocode_status;
    int latitude;
    int longitude;
    char *city;
    char *country;
    char *intersection_directions;
    char *plus4;
    char *state;
    char *street_address;
    char *zip;
    char *bd_blends;
    char *cng_dispenser_num;
    char *cng_fill_type_code;
    char *cng_has_rng;
    char *cng_psi;
    char *cng_renewable_source;
    char *cng_total_compression;
    char *cng_total_storage;
    char *cng_vehicle_class;
    char *e85_blender_pump;
    char *e85_other_ethanol_blends;
    int ev_dc_fast_num;
    char *ev_level1_evse_num;
    int ev_level2_evse_num;
    char *ev_network;
    char *ev_network_web;
    char *ev_other_evse;
    char *ev_pricing;
    char *ev_renewable_source;
    char *ev_workplace_charging;
    char *hy_is_retail;
    char *hy_pressures;
    char *hy_standards;
    char *hy_status_link;
    char *lng_has_rng;
    char *lng_renewable_source;
    char *lng_vehicle_class;
    char *lpg_nozzle_types;
    char *lpg_primary;
    char *ng_fill_type_code;
    char *ng_psi;
    char *ng_vehicle_class;
    char *rd_blended_with_biodiesel;
    char *rd_blends;
    char *rd_blends_fr;
    char *rd_max_biodiesel_level;
    char *nps_unit_name;
    char *access_days_time_fr;
    char *intersection_directions_fr;
    char *bd_blends_fr;
    char *groups_with_access_code_fr;
    char *ev_pricing_fr;
};

struct QUEUE
{
    int ptr;
    int size;
    int age;
    char *station_locator_url;
    int total_results;
    char *access_code;
    char *access_days_time;
    char *access_detail_code;
    char *cards_accepted;
    char *date_last_confirmed;
    char *expected_date;
    char *fuel_type_code;
    char *groups_with_access_code;
    int id;
    char *maximum_vehicle_class;
    char *open_date;
    char *owner_type_code;
    char *restricted_access;
    char *status_code;
    char *funding_sources;
    char *facility_type;
    char *station_name;
    char *station_phone;
    char *updated_at;
    char *geocode_status;
    int latitude;
    int longitude;
    char *city;
    char *country;
    char *intersection_directions;
    char *plus4;
    char *state;
    char *street_address;
    char *zip;
    char *bd_blends;
    char *cng_dispenser_num;
    char *cng_fill_type_code;
    char *cng_has_rng;
    char *cng_psi;
    char *cng_renewable_source;
    char *cng_total_compression;
    char *cng_total_storage;
    char *cng_vehicle_class;
    char *e85_blender_pump;
    char *e85_other_ethanol_blends;
    int ev_dc_fast_num;
    char *ev_level1_evse_num;
    int ev_level2_evse_num;
    char *ev_network;
    char *ev_network_web;
    char *ev_other_evse;
    char *ev_pricing;
    char *ev_renewable_source;
    char *ev_workplace_charging;
    char *hy_is_retail;
    char *hy_pressures;
    char *hy_standards;
    char *hy_status_link;
    char *lng_has_rng;
    char *lng_renewable_source;
    char *lng_vehicle_class;
    char *lpg_nozzle_types;
    char *lpg_primary;
    char *ng_fill_type_code;
    char *ng_psi;
    char *ng_vehicle_class;
    char *rd_blended_with_biodiesel;
    char *rd_blends;
    char *rd_blends_fr;
    char *rd_max_biodiesel_level;
    char *nps_unit_name;
    char *access_days_time_fr;
    char *intersection_directions_fr;
    char *bd_blends_fr;
    char *groups_with_access_code_fr;
    char *ev_pricing_fr;
};

typedef struct LIST *list_t;
typedef struct QUEUE *queue_t;
typedef struct STACK *stack_t;

#endif