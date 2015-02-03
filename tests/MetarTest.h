#ifndef METARTEST_H
#define METARTEST_H

#include <UnitTest++.h>

#include "Metar.h"

namespace altran {
namespace suncloud {
namespace test {

class MetarTest {
public:
    MetarTest();
    virtual ~MetarTest();

    std::string getInputMetarString() {
        std::string str(m_inputMetarString);
        return str;
    }

private:
    static const char* m_inputMetarString;
};

}
}
}

#endif // METARTEST_H
