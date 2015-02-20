#ifndef METARTEST_H
#define METARTEST_H

#include "AutoTest.h"

#ifndef Q_MOC_RUN
#include "Metar.h"
#include <boost/tokenizer.hpp>
#include <boost/lexical_cast.hpp>
#endif

namespace altran {
namespace suncloud {
namespace test {

class MetarTest : public QObject {
    Q_OBJECT

private slots:
//    void initTestCase();
//    void test1();
//    void test2();
//    void cleanupTestCase();

    void testDecode();

private:

    void parseLine(std::string& line);
    static const char* m_filePath;

};

DECLARE_TEST(MetarTest)

}
}
}

#endif // METARTEST_H
