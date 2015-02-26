#ifndef IINTERPOLATION
#define IINTERPOLATION

#include "CustomGeometry.h"

namespace altran {
namespace suncloud {


class IInterpolation
{
public:

    virtual ~IInterpolation() = 0;

    virtual double interpolate(const Point4D& point) = 0;
};

}
}
#endif // IINTERPOLATION

