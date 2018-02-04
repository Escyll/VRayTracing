#include "Ray.h"

namespace KGVR {

Ray::Ray(const Point& origin, const Vector& direction)
    : m_origin(origin)
    , m_direction(direction)
	, m_inverseDirection(1.f / direction.getX(), 1.f / direction.getY(), 1.f / direction.getZ())
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

Vector Ray::getInverseDirection() const
{
	return m_inverseDirection;
}

} // KGVR
