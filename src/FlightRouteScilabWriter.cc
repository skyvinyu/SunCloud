#include "FlightRouteScilabWriter.h"


namespace altran {
namespace suncloud {

FlightRouteScilabWriter::FlightRouteScilabWriter()
{

}

FlightRouteScilabWriter::~FlightRouteScilabWriter()
{

}


void FlightRouteScilabWriter::write(std::ostream& os) {
    // Flush start time
    flushStartTime(os);
    // Flush point vertex
    flushPoints(os);
}

//std::ostream& operator<<(std::ostream& os, FlightRoute& flightRoute) {
//    flightRoute.flushStartTime(os);
//    flightRoute.flushPoints(os);
//    return os;
//}

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

