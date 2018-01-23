#ifndef RAYCOLLIDER_H
#define RAYCOLLIDER_H

namespace KGVR {

class Ray;
class Triangle;
class Vector;
class RayCollider
{

public:
    RayCollider() = default;
    bool hits(const Ray& ray, const Triangle& triangle, Vector& hitPoint) const;
};

}

#endif // RAYCOLLIDER_H
