#ifndef METARMANAGER_H
#define METARMANAGER_H

#include <vector>
#include <memory>

#include "Metar.h"

namespace altran {
namespace suncloud {

/*
 ** \class <MetarManager> [<MetarManager.cc>] [<MetarManager.h>]
 */
class MetarManager{
public:
    typedef std::vector<std::shared_ptr<Metar> > PMetarArray;
    MetarManager();
    virtual ~MetarManager();

    void parse(std::istream& is);

    PMetarArray getPMetarArray() const { return m_pMetarArray; }

//    template<T>
//    void write(T writer, std::ostream& os) {
//        writer.write(m_pMetarArray, os);
//    }

private:
    PMetarArray m_pMetarArray;

};

}
}

#endif // METARMANAGER_H
