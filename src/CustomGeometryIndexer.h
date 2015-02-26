#ifndef GEOMETRYINDEXER_H
#define GEOMETRYINDEXER_H

#include "Constant.h"
#include "CustomGeometry.h"

#include <boost/geometry/index/rtree.hpp>

/**
 *  @brief A boost geometry index wrapper. \
 *         This template class add TGeometry to index(insert) and query TGeometry from the TIndexAlgo type Rtree
 *
 */
template <class TGeometry, class TIndexAlgo>
class CustomGeometryIndexer
{

public:
    CustomGeometryIndexer() {}
    ~CustomGeometryIndexer() {}

    void insert(const TGeometry& geometry) {
        m_rtree.insert(geometry);
    }

    void nearestQueryFromPoint(const Point2D& point, std::vector<TGeometry>& result, int resultNb){
        m_rtree.query(boost::geometry::index::nearest(point, resultNb), std::back_inserter(result));
    }

    // find values intersecting some area defined by a box
    //    box query_box(point(0, 0), point(5, 5));
    void intersectQueryFromBox(const boost::geometry::model::box& queryBox, std::vector<TGeometry>& result) {
        m_rtree.query(boost::geometry::index::intersects(queryBox), std::back_inserter(result));
    }

private:
    boost::geometry::index::rtree< TGeometry, TIndexAlgo<DEFAULT_RTREE_NODE_NUMBER> > m_rtree;
};


#endif // GEOMETRYINDEXER_H
