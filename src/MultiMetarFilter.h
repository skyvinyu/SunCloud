#ifndef MULTIMETARFILTER_H
#define MULTIMETARFILTER_H


#include "IMetarFilter.h"

namespace altran {
namespace suncloud {

class MultiMetarFilter : public IMetarFilter
{
public:
    MultiMetarFilter();
    virtual ~MultiMetarFilter();
    virtual bool filter(const Metar& metar);

};


}
}


#endif // MULTIMETARFILTER_H
