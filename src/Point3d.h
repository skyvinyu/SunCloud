#ifndef POINT3D_H
#define POINT3D_H

#include <vector>
#include "Point2d.h"

namespace fwk {
namespace geo {

class Point3d
{
public:
    Point3d();
    Point3d(double x, double y, double z);
    Point3d(const Point2d& point2d, double z);
    Point3d(const Point3d& point3d);
    ~Point3d();

    const double& getX() const {return m_point2d.getX();}
    const double& getY() const {return m_point2d.getY();}
    const double& getZ() const {return m_z;}
    double& getX() {return m_point2d.getX();}
    double& getY() {return m_point2d.getY();}
    double& getZ() {return m_z;}
    void setX(double x) {m_point2d.setX(x);}
    void setY(double y) {m_point2d.setY(y);}
    void setZ(double z) {m_z = z;}


private:
    Point2d m_point2d;
    double  m_z;
};

typedef std::vector<Point3d> Point3dArray;


}
}

#endif // POINT3D_H
