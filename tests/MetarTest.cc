#include "MetarTest.h"

namespace altran {
namespace suncloud {
namespace test {

TEST(MyMath) {
    altran::suncloud::Metar metar;
    CHECK(metar.addition(3,4) == 7);
}

}
}
}
