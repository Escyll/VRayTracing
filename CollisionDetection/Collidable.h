#ifndef COLLIDABLE_H
#define COLLIDABLE_H

#include "Ray.h"
#include "Material.h"

namespace KGVR {

class Collidable {
public:
    virtual ~Collidable() = default;
    virtual bool hits(const Ray& ray, float& tmin) const = 0;
    virtual Vector getNormal(const Point& hitPoint) const = 0;
    virtual Material* getMaterial() const = 0;
};

} // KGVR

#endif // COLLIDABLE_H
