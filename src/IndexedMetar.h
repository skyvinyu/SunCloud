#ifndef INDEXEDMETAR_H
#define INDEXEDMETAR_H

#include "CustomGeometryIndexer.h"
#include "Metar.h"
#include "MetarHandler.h"

namespace altran {
namespace suncloud {

class IndexedMetar
{
    typedef std::pair< Point2D, std::shared_ptr<Metar> > MetarIndexHandle;
public:

    IndexedMetar();
    ~IndexedMetar();

    void index(MetarHandler& handle);

private:

    CustomGeometryIndexer<MetarIndexHandle, boost::geometry::index::quadratic > m_index;

};

}
}

#endif // INDEXEDMETAR_H
