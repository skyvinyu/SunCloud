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


std::ostream& operator<<(std::ostream& os, FlightRoute& flightRoute) {
    // Flush start time
    flightRoute.flushStartTime(os);
    // Flush point vertex
    flightRoute.flushPoints(os);
    return os;
}

void FlightRoute::flushPoints(std::ostream& os) {
//    boost::geometry::for_each_point(m_route, flushPoint<Point3D>(os));
    boost::geometry::for_each_point(m_route, PointWriter<Point3D>(os));
}

void FlightRoute::flushStartTime(std::ostream& os) {
    int daysOfYear = getStartDaysOfYear();
    os << daysOfYear << std::endl
       << getLocalTm().tm_hour << " " << getLocalTm().tm_min << " " << getLocalTm().tm_sec << std::endl;
}

std::tm FlightRoute::getLocalTm() {
    std::time_t t = std::chrono::system_clock::to_time_t(m_startTime);
    std::tm local = *(localtime(&t));
    return local;
}

int FlightRoute::getStartDaysOfYear() {
    return getLocalTm().tm_yday;
}

}
}
