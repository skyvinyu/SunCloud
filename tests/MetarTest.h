#ifndef METARTEST_H
#define METARTEST_H

#include "AutoTest.h"
#include "Metar.h"

namespace altran {
namespace suncloud {
namespace test {

class MetarTest : public QObject {
    Q_OBJECT

//public:
//    MetarTest();
//    virtual ~MetarTest();

//    std::string getInputMetarString() {
//        std::string str(m_inputMetarString);
//        return str;
//    }

//private:
//    static const char* m_inputMetarString;


private slots:
    void initTestCase();
    void test1();
    void test2();
    void cleanupTestCase();

};

DECLARE_TEST(MetarTest)

}
}
}

#endif // METARTEST_H
