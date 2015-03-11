/***
*** ** Created: Thu 22. Jan 14:47:10 2015
**      by: YU Yi
**/

#include "MetarManager.h"


namespace altran {
namespace suncloud {

MetarManager::MetarManager() {
}

MetarManager::MetarManager(const std::string& rootPath) :
    m_reader(rootPath){
}

MetarManager::~MetarManager() {
}

PMetarHandler MetarManager::getMetarHandler(const std::chrono::time_point<std::chrono::system_clock>& requestDate) {
    std::string stamp = getStampFromDate(requestDate);

    std::map<std::string, PMetarHandler >::iterator ite = m_handlers.find(stamp);
    PMetarHandler pMetarHandler;
    if ( ite != m_handlers.end()) {
        pMetarHandler = ite->second;
    } else {
        m_reader.read(requestDate);
    }

    // NULL if not found
    return pMetarHandler;
}

// TODO
std::string MetarManager::getStampFromDate(const std::chrono::time_point<std::chrono::system_clock>& requestDate) {
    char buff[32];

    std::time_t tt = std::chrono::system_clock::to_time_t(requestDate);
    std::tm *timeinfo = localtime (&mtime);

    strftime(buff, sizeof(buff), "%Y_%m_%d_", timeinfo);

    std::string stamp(buff);

    int entire_hour = round ((timeinfo->tm_hour) / HOURS_INTERVAL_MODULO) * HOURS_INTERVAL_MODULO;
    stamp += boost::lexical_cast<std::string>(entire_hour);

    return stamp;
}

}
}
