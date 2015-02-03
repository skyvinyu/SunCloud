#include "FlightRoute.h"

#include "LogService.h"

namespace altran {
namespace suncloud {

FlightRoute::FlightRoute()
{
}

FlightRoute::~FlightRoute()
{
}

void FlightRoute::initRoute(const std::vector<std::tuple<double, double, double, double> > &vertex)
{
    for(const std::tuple<double, double, double, double>& p : vertex)
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

//std::ostream& FlightRoute::operator<<(std::ostream& os, const FlightRoute& flightRoute) {
//    return os;
//}

}
}
