#include "MetarTest.h"

#include <iostream>
#include <fstream>


namespace altran {
namespace suncloud {
namespace test {


//const char* MetarTest::m_filePath = "C:/Users/Sun-Cloud/Documents/Workspace_Qt/SunCloud/tests/data/metar/metar.csv";
//const char* MetarTest::m_filePath = "../../../tests/data/metar/metar.csv";
const char* MetarTest::m_filePath = "../../../tests/data/metar/france.csv";

void MetarTest::testDecode() {
    std::ifstream file(m_filePath, std::fstream::in);
    std::string line;

    while(std::getline(file, line)) {
        parseLine(line);
    }

    file.close();
}

void MetarTest::parseLine(std::string& line) {
    // Reference
    boost::char_separator<char> sep(",");
    boost::tokenizer<boost::char_separator<char> > tokens( line, sep);

    boost::tokenizer<boost::char_separator<char> >::iterator ite_tok = tokens.begin();

    // Metar parse
    Metar metar;
    metar.decode(line);

//    std::cout << "METAR PARSED:" << std::endl << metar << std::endl << std::endl;

//    std::cout << "ROW TOKEN:" << std::endl;
//    for(; ite_tok != tokens.end(); ite_tok++) {
//        std::string str = ite_tok->data();
//        std::cout << str << std::endl;
//    }

    ite_tok = tokens.begin();
    // raw_text,station_id,observation_time,latitude,longitude,temp_c,dewpoint_c,wind_dir_degrees,wind_speed_kt,wind_gust_kt,visibility_statute_mi,altim_in_hg,sea_level_pressure_mb,corrected,auto,auto_station,maintenance_indicator_on,no_signal,lightning_sensor_off,freezing_rain_sensor_off,present_weather_sensor_off,wx_string,sky_cover,cloud_base_ft_agl,sky_cover,cloud_base_ft_agl,sky_cover,cloud_base_ft_agl,sky_cover,cloud_base_ft_agl,flight_category,three_hr_pressure_tendency_mb,maxT_c,minT_c,maxT24hr_c,minT24hr_c,precip_in,pcp3hr_in,pcp6hr_in,pcp24hr_in,snow_in,vert_vis_ft,metar_type,elevation_m

    // station_id
    ite_tok++;
    QCOMPARE(std::string(metar.stnid), std::string(ite_tok->data()));

    // observation_time
    ite_tok++;

    // latitude
    ite_tok++;

    // longitude
    ite_tok++;
    // temp_c
    ite_tok++;
    // dewpoint_c
    ite_tok++;

    // 7th field: wind_dir_degrees
    ite_tok++;
    if(metar.winData.windDir != MAXINT) {
        QCOMPARE(metar.winData.windDir, boost::lexical_cast<int>(ite_tok->data()));
    }

    // 8th field: wind_speed_kt
    ite_tok++;
    if(metar.winData.windSpeed != MAXINT) {
        QCOMPARE(metar.winData.windSpeed, boost::lexical_cast<int>(ite_tok->data()));
    }

}

}
}
}
