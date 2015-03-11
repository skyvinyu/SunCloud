#include "IndexedMetar.h"

namespace altran {
namespace suncloud {

IndexedMetar::IndexedMetar()
{

}

IndexedMetar::~IndexedMetar()
{

}


void IndexedMetar::index(MetarHandler& handle) {

    for(std::shared_ptr<Metar>& metar : handle.getPMetarArray()) {
        Point2D point(metar->);
        m_index.insert(point);

    }
}

}
}
