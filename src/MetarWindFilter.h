#ifndef METARWINDFILTER_H
#define METARWINDFILTER_H

#include "IMetarFilter.h"

namespace altran {
namespace suncloud {

class MetarWindFilter : public IMetarFilter
{
public:
    MetarWindFilter();
    virtual ~MetarWindFilter();


    virtual bool filter(const Metar& metar);

};


}
}

#endif // METARWINDFILTER_H
