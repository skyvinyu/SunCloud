#ifndef CUSTOMGEOMETRY_H
#define CUSTOMGEOMETRY_H

// Custom Linestring

#include <iostream>
#include <string>
#include <vector>

#include <boost/geometry/geometry.hpp>
#include <boost/geometry/geometries/register/point.hpp>
#include <boost/geometry/geometries/register/linestring.hpp>

// To register the 'geographic' distance function to calculate distance over the earth:
//#include <boost/geometry/extensions/gis/geographic/strategies/andoyer.hpp>
//#include <boost/geometry/extensions/algorithms/parse.hpp>

typedef boost::geometry::cs::geographic<boost::geometry::degree> GeographicDegree;

//namespace altran {
//namespace suncloud {
// Define a 2D point with coordinates in latitude/longitude
struct Point2D
{
    double m_latitude, m_longitude;

    Point2D() {}
    Point2D(double x, double y)
        : m_longitude(x),
          m_latitude(y)
    {}


};

// Define a 4D point with coordinates in latitude/longitude and some additional values
struct Point4D
{
    double m_latitude, m_longitude, m_altitude;
    double m_speed;
    // Date/time, heading, etc could be added

    // The default constructor is required if being used in a vector
    Point4D() {}

    // Define a constructor to create the point in one line. Order of latitude/longitude
    Point4D(double x, double y, double h, double s)
        : m_longitude(x),
          m_latitude(y),
          m_altitude(h),
          m_speed(s)
    {}

//    // Define a constructor to create the point in one line. Order of latitude/longitude
//    // does not matter as long as "E", "N", etc are included
//    Point4D(const std::string& c1, const std::string& c2, double h, double s)
//        : m_altitude(h)
//        , m_speed(s)
//    {
//        boost::geometry::parse(*this, c1, c2);
//    }

};

// Declare a custom linestring which will have the GPS points
struct LineTrack : std::vector<Point4D>
{
    std::string m_owner;
    int m_routeId;

    LineTrack(){}
    LineTrack(int i, const std::string& o)
        : m_owner(o)
        , m_routeId(i)
    {}

};



//int testLineTrackYi()
//{
//    LineTrack track(23, "MichaelJordon");
//    track.push_back(Point4D(52.33, 4.7,  50, 180));
//    track.push_back(Point4D(54.08, 4.5, 110, 170));
//    track.push_back(Point4D(55.7,  5.3,   0, 90));

//    std::cout
//        << "track:  " << track.m_routeId << std::endl
//        << "from:   " << track.m_owner << std::endl;
//        << "as wkt: " << boost::geometry::dsv(track) << std::endl
//        << "length: " << boost::geometry::length(track)/1000.0 << " km" << std::endl;

//    return 0;
//}


//}
//}



// Register this point as being a recognizable point by Boost.Geometry
BOOST_GEOMETRY_REGISTER_POINT_2D(Point4D, double, GeographicDegree, m_longitude, m_latitude)
BOOST_GEOMETRY_REGISTER_POINT_2D(Point2D, double, GeographicDegree, m_longitude, m_latitude)

// Register the track as well, as being a "linestring"
BOOST_GEOMETRY_REGISTER_LINESTRING(LineTrack)


#endif // CUSTOMGEOMETRY_H
