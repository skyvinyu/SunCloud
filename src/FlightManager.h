#ifndef FLIGHTMANAGER_H
#define FLIGHTMANAGER_H

#include "FlightRoute.h"
#include <iostream>

namespace altran {
namespace suncloud {

class FlightManager
{
public:
    FlightManager();
    ~FlightManager();

    void updateFlightRoute(std::ostream& os);
private:
    FlightRoute m_flightRoute;
};

}
}

#endif // FLIGHTMANAGER_H
