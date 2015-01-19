#ifndef METARPARSER_H
#define METARPARSER_H

#ifdef __cplusplus
extern "C" {
#endif
    #include "metar_structs.h"
#ifdef __cplusplus
}
#endif

#include <vector>
#include <memory>

namespace altran {
namespace suncloud {

/*
 ** \class <MetarParser> [<MetarParser.cc>] [<MetarParser.h>]
 */
class MetarParser{
public:
    typedef std::vector<std::unique_ptr<Decoded_METAR> > PMetarArray;
    MetarParser();
    virtual ~MetarParser();

    void parse(std::ostream& os);

    PMetarArray getPMetarArray() const { return m_pMetarArray; }

private:
    PMetarArray m_pMetarArray;

};

}
}

#endif // METARPARSER_H
