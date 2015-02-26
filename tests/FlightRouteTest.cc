#include "FlightRouteTest.h"

namespace altran {
namespace suncloud {
namespace test {

FlightRoute::Double4D FlightRouteTest::makeDouble4DTuple(double d1, double d2, double d3, double d4) {
    FlightRoute::Double4D point(d1, d2, d3, d4);
    return point;
}

FlightRoute::Double4DArray FlightRouteTest::fillDefaultVertex() {
    FlightRoute::Double4DArray vertex;
    vertex.push_back(makeDouble4DTuple(1.2, 4.1, 30.0, 20));
    vertex.push_back(makeDouble4DTuple(1.5, 3.1, 25.0, 22));
    vertex.push_back(makeDouble4DTuple(1.2, 3.2, 30.0, 23));
    vertex.push_back(makeDouble4DTuple(3.2, 4.8, 30.0, 24));
    vertex.push_back(makeDouble4DTuple(4.2, 4.9, 30.0, 25));
    vertex.push_back(makeDouble4DTuple(5.2, 5.1, 32.0, 27));
    vertex.push_back(makeDouble4DTuple(4.6, 6.3, 35.0, 29));
    vertex.push_back(makeDouble4DTuple(5.7, 7.9, 39.0, 28));
    vertex.push_back(makeDouble4DTuple(6.9, 9.3, 38.0, 26));
    vertex.push_back(makeDouble4DTuple(7.2, 10.1, 32.0, 24));
    vertex.push_back(makeDouble4DTuple(7.4, 12.3, 31.0, 20));
    vertex.push_back(makeDouble4DTuple(8.2, 16.1, 30.0, 15));
    vertex.push_back(makeDouble4DTuple(9.0, 19.3, 27.0, 6));
    return vertex;
}

void FlightRouteTest::checkPoints(FlightRoute::Double4DArray& refVertex, LineTrack& toTestVertex)
{
    QCOMPARE(refVertex.size(), toTestVertex.size());
    for(int i = 0; i < refVertex.size(); ++i) {
        double x1 = std::get<0>(refVertex[i]);
        double x2 = toTestVertex[i].m_longitude;
        QCOMPARE(x1, x2);

        double y1 = std::get<1>(refVertex[i]);
        double y2 = toTestVertex[i].m_latitude;
        QCOMPARE(y1, y2);

        double z1 = std::get<2>(refVertex[i]);
        double z2 = toTestVertex[i].m_altitude;
        QCOMPARE(z1, z2);

        double s1 = std::get<3>(refVertex[i]);
        double s2 = toTestVertex[i].m_speed;
        QCOMPARE(s1, s2);
    }
}

void FlightRouteTest::testInitRoute()
{
    FlightRoute flightRoute;

    FlightRoute::Double4DArray refVertex = fillDefaultVertex();

    flightRoute.initRoute(refVertex);

    LineTrack line = flightRoute.getRoute();

    checkPoints(refVertex, line);
}


}
}
}
