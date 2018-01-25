#ifndef RAYCOLLIDER_H
#define RAYCOLLIDER_H

namespace KGVR {

class Ray;
class Triangle;
class Box;
class Vector;
class RayCollider
{

public:
    RayCollider() = default;
    bool hits(const Ray& ray, const Triangle& triangle, Vector& hitPoint) const;
    bool hits(const Ray& ray, const Box& box, Vector& hitPoint) const;
};

}

#endif // RAYCOLLIDER_H
