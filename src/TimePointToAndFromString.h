#ifndef TIMEPOINTTOANDFROMSTRING_H
#define TIMEPOINTTOANDFROMSTRING_H

#include <chrono>
#include <string>

namespace altran {
namespace suncloud {

class TimePointToAndFromString
{
public:
    TimePointToAndFromString();
    ~TimePointToAndFromString();

    static std::chrono::system_clock::time_point TimePointToAndFromString::timePointFromString(const std::string &str);
    static std::string TimePointToAndFromString::timePointTo6HourDateString(std::chrono::system_clock::time_point &tp);

};

}
}

#endif // TIMEPOINTTOANDFROMSTRING_H
