#ifndef RAY_H
#define RAY_H

#include "Point.h"
#include "Vector.h"

namespace KGVR {

class Ray
{
public:
    Ray() = delete;
    Ray(const Point& origin, const Vector& direction);

    Point getOrigin() const;
    Vector getDirection() const;

private:
    Point m_origin;
    Vector m_direction;
};

} // KGVR

#endif // RAY_H
