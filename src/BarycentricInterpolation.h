#ifndef BARYCENTRICINTERPOLATION_H
#define BARYCENTRICINTERPOLATION_H

#include "IInterpolation.h"

namespace altran {
namespace suncloud {


class BarycentricInterpolation : public IInterpolation
{
public:
    BarycentricInterpolation();
    virtual ~BarycentricInterpolation();

    virtual double interpolate(const Point4D& point);

private:
    std::vector<Point4D> m_triangle;

};

}
}

#endif // BARYCENTRICINTERPOLATION_H
