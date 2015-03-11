#include "TimePointToAndFromString.h"

#include <ctime>
#include <boost/lexical_cast.hpp>


namespace altran {
namespace suncloud {

TimePointToAndFromString::TimePointToAndFromString()
{

}

TimePointToAndFromString::~TimePointToAndFromString()
{

}


std::chrono::system_clock::time_point TimePointToAndFromString::timePointFromString(const std::string& str)
{
    using namespace std;
    using namespace std::chrono;

    int yyyy, mm, dd, HH;

    char scanf_format[] = "%4d_%2d_%2d_%2d";

    sscanf(str.c_str(), scanf_format, &yyyy, &mm, &dd, &HH);

    tm ttm = tm();
    ttm.tm_year = yyyy - 1900; // Year since 1900
    ttm.tm_mon = mm - 1; // Month since January
    ttm.tm_mday = dd; // Day of the month [1-31]
    ttm.tm_hour = HH; // Hour of the day [00-23]

    time_t ttime_t = mktime(&ttm);

    system_clock::time_point time_point_result = std::chrono::system_clock::from_time_t(ttime_t);

    return time_point_result;
}

std::string TimePointToAndFromString::timePointTo6HourDateString(std::chrono::system_clock::time_point &tp)
{
    auto ttime_t = std::chrono::system_clock::to_time_t(tp);
    auto tp_sec = std::chrono::system_clock::from_time_t(ttime_t);

    std::tm * ttm = std::localtime(&ttime_t);

    char date_time_format[] = "%Y_%m_%d_";

    char time_str[] = "yyyy_mm_dd_";

    std::strftime(time_str, strlen(time_str), date_time_format, ttm);

    std::string result(time_str);

    int hours = ttm->tm_hour;
    char hours_char[3];
    std::sprintf(hours_char, "%2d", hours);

    result += hours_char;

    return result;

}


}
}
