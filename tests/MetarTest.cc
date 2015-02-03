#include "MetarTest.h"

namespace altran {
namespace suncloud {
namespace test {

// Init input Metar string for TU
const char* MetarTest::m_inputMetarString = ""\
        "" \
        "";


TEST(MetarTestCase) {
    altran::suncloud::Metar metar;
    //CHECK(metar.addition(3,4) == 7);
    MetarTest metarTest;
    metar.decode(metarTest.getInputMetarString());
}

}
}
}
