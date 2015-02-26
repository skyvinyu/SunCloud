#ifndef METARSKYCOVERFILTER_H
#define METARSKYCOVERFILTER_H

#include "IMetarFilter.h"

namespace altran {
namespace suncloud {


class MetarSkyCoverFilter : public IMetarFilter
{
public:
    MetarSkyCoverFilter();
    virtual ~MetarSkyCoverFilter();

    virtual bool filter(const Metar& metar);
};

}
}

#endif // METARSKYCOVERFILTER_H
