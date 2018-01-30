#ifndef BOXCOILLIDABLE_H
#define BOXCOILLIDABLE_H

#include <memory>
#include "Collidable.h"

#include <Box.h>

namespace KGVR {

class BoxCollidable : public Collidable
{
public:
    BoxCollidable(const Point& start, const Point& end, std::unique_ptr<Material> material);
    bool hits(const Ray& ray, float& tmin) const override;
    Vector getNormal(const Point& hitPoint) const;
    Material* getMaterial() const override;
private:
    Box m_box;
    std::unique_ptr<Material> m_material;

    // Collidable interface
public:
};

}

#endif // BOXCOILLIDABLE_H
