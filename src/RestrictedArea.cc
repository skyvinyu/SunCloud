#include "RestrictedArea.h"

namespace altran {
namespace suncloud {

RestrictedArea::RestrictedArea()
{

}

RestrictedArea::~RestrictedArea()
{

}

void RestrictedArea::initArea(const std::vector< std::tuple<double, double> >& vertex2d) {
    for(const std::tuple<double, double> p : vertex2d) {
        double x = std::get<0>(p);
        double y = std::get<1>(p);
        Point2D point(x, y);
        boost::geometry::append(m_area, point);
    }
}

}
}
