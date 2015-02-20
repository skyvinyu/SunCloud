#ifndef METAR_CPP_H
#define METAR_CPP_H

#include <iostream>
#include <string>

extern "C" {
#include "metar_structs.h"
#include "metar.h"

typedef struct decoded_METAR Decoded_METAR;

void sprint_metar (char * string, Decoded_METAR *Mptr);
void prtDMETR (Decoded_METAR *Mptr);
}

namespace altran {
namespace suncloud {


/**
 * @brief The Metar class, derive a C++ class Metar from the C struct Decoded_METAR from mdsplib
 */
class Metar : public Decoded_METAR {
public:
    Metar();
    //virtual ~Metar();

    void decode(const std::string& input);

    friend std::ostream& operator<<(std::ostream& os, const Metar& metar){
//        char cStr[1024*32];
//        sprint_metar(cStr, &((Decoded_METAR)metar));

        char string[5000];
        sprint_metar(string, &((Decoded_METAR)metar));
        os << string;
        return os;
    }

    int addition(int a, int b) {
        return a+b;
    }

private:

};


}
}

#endif // METAR_CPP_H
