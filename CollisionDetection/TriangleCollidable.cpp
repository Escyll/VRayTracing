#include "TriangleCollidable.h"

namespace KGVR {

TriangleCollidable::TriangleCollidable(const Point& v0, const Point& v1, const Point& v2, std::unique_ptr<Material> material)
    : m_triangle(v0, v1, v2)
    , m_material(std::move(material))
{
}

bool TriangleCollidable::hits(const Ray& ray, float& tresult) const
{
    const double EPSILON = 0.0000001;
    Point v0 = m_triangle.getV0();
    Point v1 = m_triangle.getV1();
    Point v2 = m_triangle.getV2();
    Vector edge1;
    Vector edge2;
    Vector h;
    Vector s;
    Vector q;
    double a,f,u,v;
    edge1 = v1 - v0;
    edge2 = v2 - v0;
    h = ray.getDirection().cross(edge2);
    a = edge1.dot(h);
    if (a > -EPSILON && a < EPSILON)
        return false;
    f = 1/a;
    s = ray.getOrigin() - v0;
    u = f * (s.dot(h));
    if (u < 0.0 || u > 1.0)
        return false;
    q = s.cross(edge1);
    v = f * ray.getDirection().dot(q);
    if (v < 0.0 || u + v > 1.0)
        return false;
    // At this stage we can compute t to find out where the intersection point is on the line.
    float t = f * edge2.dot(q);
    if (t > EPSILON) // ray intersection
    {
        tresult = t;
        return true;
    }
    else // This means that there is a line intersection but not a ray intersection.
        return false;
}

Vector TriangleCollidable::getNormal(const Point& hitPoint) const
{
    return m_triangle.getNormal();
}

Material* TriangleCollidable::getMaterial() const
{
    return m_material.get();
}

} // KGVR
