#include "MetarWindFilter.h"

namespace altran {
namespace suncloud {

MetarWindFilter::MetarWindFilter()
{

}

MetarWindFilter::~MetarWindFilter()
{

}

bool MetarWindFilter::filter(const Metar& metar) {
    //WIND SPEED          : 11
    //WIND UNITS          : KT
    return metar.winData.windSpeed < DANGEROUS_WIND_SPEED_THRESHOULD;
}

}
}
