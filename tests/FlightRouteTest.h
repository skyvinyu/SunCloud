#ifndef FLIGHTROUTETEST_H
#define FLIGHTROUTETEST_H

#include "AutoTest.h"

#ifndef Q_MOC_RUN
#include "FlightRoute.h"
#endif

namespace altran {
namespace suncloud {
namespace test {

class FlightRouteTest : public QObject
{
    Q_OBJECT

    template <typename Point3D>
    class PointChecker
    {
    public :
        PointChecker(FlightRoute::Vertex3DArray& ref) :
            m_ref(ref)
        {}

        void operator()(Point3D& p)
        {
            double x = boost::geometry::get<0>(p);
            double y = boost::geometry::get<1>(p);
            double z = boost::geometry::get<2>(p);

            FlightRoute::Vertex3D point3d(x, y, z);
            m_ref.push_back(point3d);
        }
    private :
        FlightRoute::Vertex3DArray m_ref;

    };


private slots:
    void testInitRoute();

    FlightRoute::Vertex4D makeDouble4DTuple(double d1, double d2, double d3, double d4);
    FlightRoute::Vertex4DArray fillDefaultVertex();
    void checkPoints(FlightRoute::Vertex4DArray& vertex, FlightRoute::Vertex3DArray& points);

};

DECLARE_TEST(FlightRouteTest)

}
}
}

#endif // FLIGHTROUTETEST_H
