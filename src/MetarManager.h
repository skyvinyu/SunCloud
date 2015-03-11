#ifndef METARMANAGER_H
#define METARMANAGER_H

#include "MetarHandler.h"
#include "MetarFileReader.h"

#include <chrono>
#include <map>
#include <string>

#define HOURS_INTERVAL_MODULO 6

namespace altran {
namespace suncloud {

/*
 ** \class <MetarManager> [<MetarManager.cc>] [<MetarManager.h>]
 */
class MetarManager{
public:

    MetarManager();
    MetarManager(const std::string& rootPath);
    virtual ~MetarManager();

    PMetarHandler getMetarHandler(const std::chrono::time_point<std::chrono::system_clock>& requestTime);
    static std::string getStampFromDate(const std::chrono::time_point<std::chrono::system_clock>& requestDate);

private:

    MetarFileReader m_reader;
    std::map<std::string, PMetarHandler> m_handlers;
};

}
}

#endif // METARMANAGER_H
