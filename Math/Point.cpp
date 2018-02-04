#include "Point.h"
#include "Vector.h"

namespace KGVR {

Point::Point()
    : m_x(0)
    , m_y(0)
    , m_z(0)
{   
}

Point::Point(float x, float y, float z)
    : m_x(x)
    , m_y(y)
    , m_z(z)
{
}

Point Point::operator+(const Vector& rhs)
{
    return Point(m_x + rhs.m_x, m_y + rhs.m_y, m_z + rhs.m_z);
}

Point Point::operator-(const Vector& rhs)
{
    return *this + -rhs;
}

Vector Point::operator-(const Point& rhs)
{
    return Vector(m_x - rhs.m_x, m_y - rhs.m_y, m_z - rhs.m_z);
}

Point& Point::operator+=(const Vector& rhs)
{
    m_x += rhs.m_x;
    m_y += rhs.m_y;
    m_z += rhs.m_z;
    return *this;
}

Vector operator-(const Point& lhs, const Point& rhs)
{
    return Vector(lhs.m_x - rhs.m_x, lhs.m_y - rhs.m_y, lhs.m_z - rhs.m_z);
}

float Point::getX() const
{
    return m_x;
}

float Point::getY() const
{
    return m_y;
}

float Point::getZ() const
{
    return m_z;
}

} // KGVR
