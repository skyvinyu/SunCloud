#include "FlightRoute.h"

#include "LogService.h"

#include <boost/date_time/gregorian/gregorian.hpp>

namespace altran {
namespace suncloud {

FlightRoute::FlightRoute()
{
}

FlightRoute::~FlightRoute()
{
}

void FlightRoute::initRoute(const Double4DArray &vertex)
{
    for(const Double4D& p : vertex)
    {
        double x = std::get<0>(p);
        double y = std::get<1>(p);
        double z = std::get<2>(p);
        double speed = std::get<3>(p);

        m_route.push_back(Point4D(x, y, z, speed));

        FWK_DEBUG("Add 4d point " << x << ", " << y << ", " << z << ", " << speed << " to FlightRoute");
    }
    FWK_DEBUG("FlightRout initialized with " << vertex.size() << " vertex");

//    FWK_DEBUG("FlightRout in wkt: " << boost::geometry::dsv(track));
}

void FlightRoute::setStartTime(const std::chrono::time_point<std::chrono::system_clock> &startTime)
{
    m_startTime = startTime;
}


}
}
