#include <cmath>

#include "Vector.h"
#include "Point.h"

namespace KGVR {

Vector::Vector()
    : m_x(0)
    , m_y(0)
    , m_z(0)
{
}

Vector::Vector(double x, double y, double z)
    : m_x(x)
    , m_y(y)
    , m_z(z)
{
}

Vector& Vector::operator =(const Point& rhs)
{
    m_x = rhs.m_x;
    m_y = rhs.m_y;
    m_z = rhs.m_z;
    return *this;
}

void Vector::normalize()
{
    this->operator/=(length());
}

Vector Vector::normalize(const Vector& v)
{
    Vector result = v;
    result.normalize();
    return result;
}

Vector Vector::operator+(const Vector& rhs) const
{
    return Vector(m_x + rhs.m_x, m_y + rhs.m_y, m_z + rhs.m_z);
}

Vector Vector::operator-(const Vector& rhs) const
{
    return Vector(m_x - rhs.m_x, m_y - rhs.m_y, m_z - rhs.m_z);
}

Vector Vector::operator-() const
{
    return Vector(-m_x, -m_y, -m_z);
}

Vector Vector::operator*(double rhs) const
{
    return Vector(rhs * m_x, rhs * m_y, rhs * m_z);
}

double Vector::dot(const Vector& rhs) const
{
    return m_x * rhs.m_x + m_y * rhs.m_y + m_z * rhs.m_z;
}

Vector Vector::cross(const Vector& rhs) const
{
    return Vector(m_y*rhs.m_z - rhs.m_y*m_z, m_z*rhs.m_x - rhs.m_z*m_x, m_x*rhs.m_y - rhs.m_x*m_y);
}

Vector Vector::cross(const Vector& a, const Vector& b)
{
    return a.cross(b);
}

Vector& Vector::operator*=(double rhs)
{
    m_x *= rhs;
    m_y *= rhs;
    m_z *= rhs;
    return *this;
}

Vector& Vector::operator/=(double rhs)
{
    m_x /= rhs;
    m_y /= rhs;
    m_z /= rhs;
    return *this;
}

Vector Vector::operator/(double rhs) const
{
    return Vector(m_x / rhs, m_y / rhs, m_z / rhs);
}

Vector operator*(double lhs, const Vector& rhs)
{
    return rhs * lhs;
}

double Vector::length() const
{
    return std::sqrt(lengthSquared());
}

double Vector::lengthSquared() const
{
    return m_x * m_x + m_y * m_y + m_z * m_z;
}

double Vector::getX() const
{
    return m_x;
}

double Vector::getY() const
{
    return m_y;
}

double Vector::getZ() const
{
    return m_z;
}

} // KGVR
