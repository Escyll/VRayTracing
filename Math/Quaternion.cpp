#include <cmath>

#include "Quaternion.h"
#include "Vector.h"

namespace KGVR {

Quaternion::Quaternion(float x, float y, float z, float w)
    : m_x(x)
    , m_y(y)
    , m_z(z)
    , m_w(w)
{
}

Quaternion::Quaternion(float radians, const Vector& axis)
{
    m_w = std::cos(radians / 2.f);
    m_x = std::sin(radians / 2.f) * axis.getX();
    m_y = std::sin(radians / 2.f) * axis.getY();
    m_z = std::sin(radians / 2.f) * axis.getZ();
}

Quaternion Quaternion::conjugate() const
{
    return Quaternion(-m_x, -m_y, -m_z, m_w);
}

Vector Quaternion::operator*(const Vector& v) const
{
    auto t = 2.0 * xyz().cross(v);
    return v + m_w * t + xyz().cross(t);
}

Quaternion Quaternion::operator*(const Quaternion& r) const
{
    return Quaternion( r.m_w*m_x + r.m_x*m_w - r.m_y*m_z + r.m_z*m_y,
                       r.m_w*m_y + r.m_x*m_z + r.m_y*m_w - r.m_z*m_x,
                       r.m_w*m_z - r.m_x*m_y + r.m_y*m_x + r.m_z*m_w,
                       r.m_w*m_w - r.m_x*m_x - r.m_y*m_y - r.m_z*m_z);
}

Vector Quaternion::xyz() const
{
    return Vector(m_x, m_y, m_z);
}

} // KGVR
