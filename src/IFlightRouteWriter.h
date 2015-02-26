#ifndef IFLIGHTROUTEWRITER_H
#define IFLIGHTROUTEWRITER_H


#include <iostream>
#include <string>

#include <boost/shared_ptr.hpp>

namespace altran {
namespace suncloud {

class IFlightRouteWriter
{
public:
    virtual ~IFlightRouteWriter() = 0;

    virtual void write(std::ostream& os) = 0;
};

typedef boost::shared_ptr<IFlightRouteWriter> PIFlightRouteWriter;

}
}

#endif // IFLIGHTROUTEWRITER_H
