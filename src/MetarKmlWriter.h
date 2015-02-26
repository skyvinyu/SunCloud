#ifndef KMLMETARWRITER_H
#define KMLMETARWRITER_H

#include "IMetarWriter.h"

namespace altran {
namespace suncloud {


class MetarKmlWriter : public IMetarWriter
{
public:
    MetarKmlWriter();
    ~MetarKmlWriter();

    virtual void write(std::ostream& os);

};

}
}

#endif // KMLMETARWRITER_H
