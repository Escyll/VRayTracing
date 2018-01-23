#include "Ray.h"

namespace KGVR {

Ray::Ray(const Point& origin, const Vector& direction)
    : m_origin(origin)
    , m_direction(direction)
{
}

Point Ray::getOrigin() const
{
    return m_origin;
}

Vector Ray::getDirection() const
{
    return m_direction;
}

} // KGVR
