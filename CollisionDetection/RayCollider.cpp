#include <utility>

#include "Ray.h"
#include "Triangle.h"

#include "RayCollider.h"

#include <Box.h>

namespace KGVR {

bool RayCollider::hits(const Ray& ray, const Triangle& triangle, Vector& hitPoint) const
{
    const double EPSILON = 0.0000001;
    Point v0 = triangle.getV0();
    Point v1 = triangle.getV1();
    Point v2 = triangle.getV2();
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
        hitPoint = ray.getOrigin() + ray.getDirection() * t;
        return true;
    }
    else // This means that there is a line intersection but not a ray intersection.
        return false;
}

bool RayCollider::hits(const Ray& ray, const Box& box, Vector& hitPoint) const
{
    auto& min = box.getStart();
    auto& max = box.getEnd();
    float dirx = ray.getDirection().getX();
    if (std::abs(dirx) < 0.00000001 ) dirx = 0.0000001;

    float diry = ray.getDirection().getY();
    if (std::abs(diry) < 0.00000001 ) diry = 0.0000001;

    float dirz = ray.getDirection().getZ();
    if (std::abs(dirz) < 0.00000001 ) dirz = 0.0000001;

    float tmin = (min.getX() - ray.getOrigin().getX()) / dirx;
    float tmax = (max.getX() - ray.getOrigin().getX()) / dirx;

    if (tmin > tmax)
        std::swap(tmin, tmax);

    float tymin = (min.getY() - ray.getOrigin().getY()) / diry;
    float tymax = (max.getY() - ray.getOrigin().getY()) / diry;

    if (tymin > tymax)
        std::swap(tymin, tymax);

    if ((tmin > tymax) || (tymin > tmax))
        return false;

    if (tymin > tmin)
        tmin = tymin;

    if (tymax < tmax)
        tmax = tymax;

    float tzmin = (min.getZ() - ray.getOrigin().getZ()) / dirz;
    float tzmax = (max.getZ() - ray.getOrigin().getZ()) / dirz;

    if (tzmin > tzmax)
        std::swap(tzmin, tzmax);

    if ((tmin > tzmax) || (tzmin > tmax))
        return false;

    if (tzmin > tmin)
        tmin = tzmin;

    if (tzmax < tmax)
        tmax = tzmax;

    hitPoint = ray.getOrigin() + ray.getDirection() * tmin;

    return true;
}

}
