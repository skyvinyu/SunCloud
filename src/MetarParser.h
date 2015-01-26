#ifndef METARPARSER_H
#define METARPARSER_H

#include <vector>
#include <memory>

#include "Metar.h"

namespace altran {
namespace suncloud {

/*
 ** \class <MetarParser> [<MetarParser.cc>] [<MetarParser.h>]
 */
class MetarParser{
public:
    typedef std::vector<std::shared_ptr<Metar> > PMetarArray;
    MetarParser();
    virtual ~MetarParser();

    void parse(std::istream& os);

    PMetarArray getPMetarArray() const { return m_pMetarArray; }

private:
    PMetarArray m_pMetarArray;

};

}
}

#endif // METARPARSER_H
