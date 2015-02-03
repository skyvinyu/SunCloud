#ifndef FWK_GEOMETRY
#define FWK_GEOMETRY

#include <vector>

#include <boost/geometry.hpp>
#include <boost/variant.hpp>

namespace altran {
namespace suncloud {


typedef boost::geometry::cs::spherical_equatorial<boost::geometry::degree > SphericalDegree;

// 2D geometries
typedef boost::geometry::model::point<double, 2, SphericalDegree> Point2D;
typedef boost::geometry::model::box<Point2D> Box2D;
typedef boost::geometry::model::polygon<Point2D, false, false> Polygon2D;
typedef boost::geometry::model::ring<Point2D, false, false> Ring2D;
typedef boost::geometry::model::linestring<Point2D> Line2D;
typedef boost::variant<Point2D, Line2D, Polygon2D, Ring2D> Geometry2D;

typedef std::map<unsigned, Geometry2D> Geometry2DMap;
typedef std::pair<Box2D, Geometry2DMap::iterator> Geometry2DValue;

// 3D geometries, only point and line for the moment
typedef boost::geometry::model::point<double, 3, SphericalDegree> Point3D;
typedef boost::geometry::model::linestring<Point3D> Line3D;
typedef boost::variant<Point3D, Line3D> Geometry3D;

typedef std::map<unsigned, Geometry3D> Geometry3DMap;


}
}

#endif // FWK_GEOMETRY

