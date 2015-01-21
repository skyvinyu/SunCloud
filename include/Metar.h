#ifndef METAR_H
#define METAR_H

#include <iostream>
#include <string>

extern "C" {
#include "metar_structs.h"
#include "metar.h"

typedef struct decoded_METAR Decoded_METAR;

void sprint_metar (char * string, Decoded_METAR *Mptr);
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
        char *cStr;
        sprint_metar(cStr, &((Decoded_METAR)metar));
        os << cStr;
        return os;
    }

private:

};


}
}

#endif // METAR_H
