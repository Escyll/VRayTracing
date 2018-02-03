#include "BoxCollidable.h"
#include <utility>

namespace KGVR {

BoxCollidable::BoxCollidable(const Point& start, const Point& end, std::unique_ptr<Material> material)
    : m_box(start, end)
    , m_material(std::move(material))
{
}

bool BoxCollidable::hits(const Ray& ray, float& tresult) const
{
    auto& min = m_box.getStart();
    auto& max = m_box.getEnd();
    float dirx = ray.getDirection().getX();
    const float epsilon = 0.00000001f;
    if (std::abs(dirx) < epsilon ) dirx = epsilon;

    float diry = ray.getDirection().getY();
    if (std::abs(diry) < epsilon ) diry = epsilon;

    float dirz = ray.getDirection().getZ();
    if (std::abs(dirz) < epsilon ) dirz = epsilon;

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

    tresult = tmin;
    return true;
}


Vector BoxCollidable::getNormal(const Point& hitPoint) const
{
    return m_box.getNormal(hitPoint);
}

Material* BoxCollidable::getMaterial() const
{
    return m_material.get();
}

}
