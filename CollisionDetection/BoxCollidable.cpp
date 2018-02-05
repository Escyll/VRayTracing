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
    auto min = m_box.getStart();
    auto max = m_box.getEnd();
    auto invDir = ray.getInverseDirection();
    float invDirX = invDir.getX();
    float invDirY = invDir.getY();
    float invDirZ = invDir.getZ();
    auto orig = ray.getOrigin();
    float origX = orig.getX();
    float origY = orig.getY();
    float origZ = orig.getZ();

    float tmin = (min.getX() - origX) * invDirX;
    float tmax = (max.getX() - origX) * invDirX;

    if (tmin > tmax)
        std::swap(tmin, tmax);

    float tymin = (min.getY() - origY) * invDirY;
    float tymax = (max.getY() - origY) * invDirY;

    if (tymin > tymax)
        std::swap(tymin, tymax);

    if ((tmin > tymax) || (tymin > tmax))
        return false;

    if (tymin > tmin)
        tmin = tymin;

    if (tymax < tmax)
        tmax = tymax;

    float tzmin = (min.getZ() - origZ) * invDirZ;
    float tzmax = (max.getZ() - origZ) * invDirZ;

    if (tzmin > tzmax)
        std::swap(tzmin, tzmax);

    if ((tmin > tzmax) || (tzmin > tmax))
        return false;

    if (tzmin > tmin)
        tmin = tzmin;

    tresult = tmin;
    return tmin > 0;
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
