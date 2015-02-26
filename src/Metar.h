#ifndef METAR_CPP_H
#define METAR_CPP_H

#include <iostream>
#include <string>

extern "C" {
#include "metar_structs.h"
#include "metar.h"

typedef struct decoded_METAR Decoded_METAR;

void sprint_metar (char * string, Decoded_METAR *Mptr);
void prtDMETR (Decoded_METAR *Mptr);
}

namespace altran {
namespace suncloud {


/**
 * @brief The Metar class, derive a C++ class Metar from the C struct Decoded_METAR from mdsplib
 */
class Metar : public Decoded_METAR {
public:
    Metar();
    //virtual ~Metar();

    void decode(const std::string& input);

    friend std::ostream& operator<<(std::ostream& os, const Metar& metar){
//        char cStr[1024*32];
//        sprint_metar(cStr, &((Decoded_METAR)metar));

        char string[5000];
        sprint_metar(string, &((Decoded_METAR)metar));
        os << string;
        return os;
    }

    int addition(int a, int b) {
        return a+b;
    }

private:

};


}
}

/**
    raw_text
    station_id
    observation_time
    latitude
    longitude
    temp_c
    dewpoint_c
    wind_dir_degrees
    wind_speed_kt
    wind_gust_kt
    visibility_statute_mi
    altim_in_hg
    sea_level_pressure_mb
    corrected
    auto
    auto_station
    maintenance_indicator_on
    no_signal
    lightning_sensor_off
    freezing_rain_sensor_off
    present_weather_sensor_off
    wx_string
    sky_cover
    cloud_base_ft_agl
    sky_cover
    cloud_base_ft_agl
    sky_cover
    cloud_base_ft_agl
    sky_cover
    cloud_base_ft_agl
    flight_category
    three_hr_pressure_tendency_mb
    maxT_c
    minT_c
    maxT24hr_c
    minT24hr_c
    precip_in
    pcp3hr_in
    pcp6hr_in
    pcp24hr_in
    snow_in
    vert_vis_ft
    metar_type
    elevation_m
  */

#endif // METAR_CPP_H
