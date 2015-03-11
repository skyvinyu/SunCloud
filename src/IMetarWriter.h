#ifndef IMETARWRITER
#define IMETARWRITER

#include <iostream>
#include <string>

namespace altran {
namespace suncloud {

class IMetarWriter {
public:
    virtual ~IMetarWriter() {}

    virtual void write(std::ostream& os) = 0;
};


}
}

#endif // IMETARWRITER

