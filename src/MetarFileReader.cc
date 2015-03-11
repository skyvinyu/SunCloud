#include "MetarFileReader.h"

#include "MetarManager.h"

namespace altran {
namespace suncloud {

MetarFileReader::MetarFileReader(const std::string& rootPath) :
        m_rootPath(rootPath) {

}

MetarFileReader::~MetarFileReader()
{

}

void MetarFileReader::read(const std::chrono::time_point<std::chrono::system_clock>& requestDate){
    std::string stamp = getStampFromDate(requestDate);

}


}
}
