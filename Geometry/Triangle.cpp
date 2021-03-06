#include "Triangle.h"
#include "Point.h"

namespace KGVR {

Triangle::Triangle(const Point& v0, const Point& v1, const Point& v2)
    : m_v0(v0)
    , m_v1(v1)
    , m_v2(v2)
    , m_normal( Vector::normalize(Vector::cross(v1 - v0, v2 - v0)) )
{
}

Point Triangle::getV0() const
{
    return m_v0;
}

Point Triangle::getV1() const
{
    return m_v1;
}

Point Triangle::getV2() const
{
    return m_v2;
}

Vector Triangle::getNormal() const
{
    return m_normal;
}

} // KGVR
