#include "MetarSkyCoverFilter.h"

namespace altran {
namespace suncloud {

MetarSkyCoverFilter::MetarSkyCoverFilter()
{

}

MetarSkyCoverFilter::~MetarSkyCoverFilter()
{

}


bool MetarSkyCoverFilter::filter(const Metar& metar) {
    /**
     * Sky Conditions:
        BKN – Broken cloud layer 5/8ths to 7/8ths
        CB – Cumulonimbus
        CLR – Sky clear at or below 12,000AGL
        FEW – Few cloud layer 0/8ths to 2/8ths
        OVC – Overcast cloud layer 8/8ths coverage
        SCT – Scattered cloud layer 3/8ths to 4/8ths
        SKC – Sky Clear
        TCU – Towering Cumulus
     */


}

}
}
