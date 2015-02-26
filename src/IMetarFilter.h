#ifndef IMETARFILTER_H
#define IMETARFILTER_H

#include "Metar.h"
#include "Constant.h"

namespace altran {
namespace suncloud {

class IMetarFilter
{
public:
    virtual ~IMetarFilter() {}

    virtual bool filter(const Metar& metar) = 0;
};

}
}

#endif // IMETARFILTER_H
