#ifndef FLIGHTROUTE_H
#define FLIGHTROUTE_H

#include <chrono>
#include <vector>
#include <tuple>

#include "CustomGeometry.h"

#include "IFlightRouteWriter.h"

namespace altran {
namespace suncloud {

class FlightRoute
{
    friend class IFlightRouteWriter;

public:

    typedef std::tuple<double, double, double> Double3D;
    typedef std::vector<Double3D > Double3DArray;

    typedef std::tuple<double, double, double, double> Double4D;
    typedef std::vector<Double4D > Double4DArray;

    FlightRoute();
    virtual ~FlightRoute();

    /**
     * @brief initRoute Initilize flight route coordinate, altitude and speed
     * @param vertex4d The vertex for the flight route, the four field tuple is x, y, z, speed
     */
    void initRoute(const Double4DArray& vertex4d);

    /**
     * @brief setStartTime Set flight start time
     * @param startTime The time to start the flight
     */
    void setStartTime(const std::chrono::time_point<std::chrono::system_clock> &startTime);

//    /**
//     * @brief operator << Flush content to stream
//     * @param os    Output stream
//     * @param flightRoute   Flight route
//     * @return Output stream
//     */
//    friend std::ostream& operator<<(std::ostream& os, const FlightRoute& flightRoute);

//protected:

//    template<class Writer>
//    void write(std::ostream& os);

    LineTrack getRoute() const{
        return m_route;
    }
    void setRoute(const LineTrack &route){
        m_route = route;
    }

private:

    LineTrack m_route;

    std::chrono::time_point<std::chrono::system_clock> m_startTime;


};


}
}

#endif // FLIGHTROUTE_H
