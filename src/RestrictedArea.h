#ifndef RESTRICTEDAREA_H
#define RESTRICTEDAREA_H

#include <chrono>
#include <vector>
#include <tuple>

#include "Geometry.h"

namespace altran {
namespace suncloud {

class RestrictedArea
{
public:
    RestrictedArea();
    ~RestrictedArea();

    void initArea(const std::vector< std::tuple<double, double> >& vertex2d);

    void setMaxZ(double maxZ){
        m_maxZ = maxZ;
    }
    void setMinZ(double minZ){
        m_minZ = minZ;
    }


private:
    Polygon2D   m_area;
    double      m_minZ;
    double      m_maxZ;
};


typedef std::vector<RestrictedArea> RestrictedAreaArray;


}
}

#endif // RESTRICTEDAREA_H
