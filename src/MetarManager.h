#ifndef METARMANAGER_H
#define METARMANAGER_H

#include "CustomGeometryIndexer.h"

#include <map>

namespace altran {
namespace suncloud {

/*
 ** \class <MetarManager> [<MetarManager.cc>] [<MetarManager.h>]
 */
class MetarManager{
public:

    MetarManager();
    virtual ~MetarManager();

    void getIndexerByDate();

private:

    std::map<std::string, CustomGeometryIndexer> m_geometryIndexer;
};

}
}

#endif // METARMANAGER_H
