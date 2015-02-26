#include "MetarHandler.h"

#include <iostream>
#include <string>
#include <exception>

#define CHAR_STRING_MAX_SIZE 1024

namespace altran {
namespace suncloud {

MetarHandler::MetarHandler() {
}

MetarHandler::~MetarHandler() {
}

void MetarHandler::parse(std::istream& is) {
    //std::string str = os.str();
    //char *inputMetar = str.c_str();
    int ret = 0;
    std::string line;

    while( std::getline(is, line).eof() ) {
        std::shared_ptr<Metar> pMetar(new Metar);
        //std::unique_ptr<Metar> pMetar = std::make_unique<Metar>();
        std::cout << "INPUT METAR REPORT:" << std::endl << line;

        pMetar->decode(line);

        std::cout << "FINAL DECODED PRODUCT: " << std::endl;
        std::cout << *pMetar << std::endl;

        m_pMetarArray.push_back(pMetar);
    }
}


}
}
