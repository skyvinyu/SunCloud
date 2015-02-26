#ifndef IMETARWRITER
#define IMETARWRITER

#include <iostream>
#include <string>

#include <boost/shared_ptr.hpp>

namespace altran {
namespace suncloud {

class IMetarWriter {
public:
    virtual ~IMetarWriter() {}

    virtual void write(std::ostream& os) = 0;
};

typedef boost::shared_ptr<IMetarWriter> PIMetarWriter;

}
}

#endif // IMETARWRITER

