#include <cmath>
#include <memory>

#include "Box.h"

namespace KGVR {

Box::Box(const Point& start, const Point& end)
    : m_start(start)
    , m_end(end)
{
}

Point Box::getStart() const
{
    return m_start;
}

Point Box::getEnd() const
{
    return m_end;
}

bool closeEnough(float x1, float x2)
{
    return std::abs(x1 - x2) < 0.000001;
}

Vector Box::getNormal(const Vector& p)
{
    if (closeEnough(p.getX(), m_start.getX()))
        return Vector(-1, 0, 0);
    else if (closeEnough(p.getX(), m_end.getX()))
        return Vector(1, 0, 0);
    else if (closeEnough(p.getY(), m_start.getY()))
        return Vector(0, -1, 0);
    else if (closeEnough(p.getY(), m_end.getY()))
        return Vector(0, 1, 0);
    else if (closeEnough(p.getZ(), m_start.getZ()))
        return Vector(0, 0, -1);
    else if (closeEnough(p.getZ(), m_end.getZ()))
        return Vector(0, 0, 1);
    throw std::exception("Kan niet");
}

} // KGVR
