#include "include/MetarParser.h"
#include <iostream>

#define CHAR_STRING_MAX_SIZE 1024

namespace altran {
namespace suncloud {

MetarParser::MetarParser() {
}

MetarParser::~MetarParser() {
}

void MetarParser::parse(std::istream& is) const{
    //std::string str = os.str();
    //char *inputMetar = str.c_str();
    int ret = 0;
    std::string line;

    while( std::getline(is, line) != eofbit) {
        std::unique_ptr<Decoded_METAR> pMetar = std::make_unique<Decoded_METAR>( new Decoded_METAR );
        std::cout << "INPUT METAR REPORT:" << std::endl << string[j];

extern "C"{
        ret = DcdMETAR( line.c_str(), pMetar.get() );
}
        if ( ret != 0 ) {
            std::cout << "ERROR: DcdMETAR Return Number: " << ret << std::endl;
            throw(std::exception("DcdMETAR error"));
        }
        std::cout << "FINAL DECODED PRODUCT: " << std::endl;
        prtDMETR( pMetar );

        m_pMetarArray.push_back(pMetar);
    }
}


}
}
