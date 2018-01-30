#ifndef TRIANGLECOLLIDABLE_H
#define TRIANGLECOLLIDABLE_H

#include "Collidable.h"

#include <Material.h>
#include <Point.h>
#include <Triangle.h>
#include <memory>


namespace KGVR {

class TriangleCollidable : public Collidable
{
public:
    TriangleCollidable(const Point& v0, const Point& v1, const Point& v2, std::unique_ptr<Material> material);
    bool hits(const Ray& ray, float& tresult) const;
    Vector getNormal(const Point& hitPoint) const;
    Material* getMaterial() const;
private:
    Triangle m_triangle;
    std::unique_ptr<Material> m_material;

};

} // KGVR

#endif // TRIANGLECOLLIDABLE_H
