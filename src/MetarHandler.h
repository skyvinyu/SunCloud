#ifndef METARHANDLER_H
#define METARHANDLER_H


class MetarHandler
{
public:
    MetarHandler();
    ~MetarHandler();
};

#include <vector>
#include <memory>

#include "Metar.h"

namespace altran {
namespace suncloud {


class MetarHandler{
public:
    typedef std::vector<std::shared_ptr<Metar> > PMetarArray;

    MetarHandler();
    virtual ~MetarHandler();

    void parse(std::istream& is);

    PMetarArray getPMetarArray() const { return m_pMetarArray; }

private:
    PMetarArray m_pMetarArray;

};

}
}

#endif // METARHANDLER_H
