#ifndef METARFILEREADER_H
#define METARFILEREADER_H

#include "IMetarReader.h"

namespace altran {
namespace suncloud {

class MetarFileReader : public IMetarReader
{
public:
    MetarFileReader();
    ~MetarFileReader();

    virtual void read(const std::chrono::time_point<std::chrono::system_clock>& requestDate);

};

}
}

#endif // METARFILEREADER_H
