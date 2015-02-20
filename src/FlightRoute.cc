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

void FlightRoute::initRoute(const Vertex4DArray &vertex)
{
    for(const Vertex4D& p : vertex)
    {
        double x = std::get<0>(p);
        double y = std::get<1>(p);
        double z = std::get<2>(p);

        Point3D point(x, y, z);

        m_route.push_back(point);

        double speed = std::get<3>(p);
        m_speed.push_back(speed);

        FWK_DEBUG("Add 3d point " << x << ", " << y << ", " << z << " to FlightRoute");
    }
    FWK_DEBUG("FlightRout initialized with " << vertex.size() << " vertex");
}

void FlightRoute::setStartTime(const std::chrono::time_point<std::chrono::system_clock> &startTime)
{
    m_startTime = startTime;
}

Line3D FlightRoute::getRoute() const
{
    return m_route;
}

void FlightRoute::setRoute(const Line3D &route)
{
    m_route = route;
}



}
}
