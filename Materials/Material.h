#ifndef MATERIAL_H
#define MATERIAL_H

#include <functional>

namespace KGVR {

class Vector;
class Color;
class Material
{
public:
    virtual Color getColor() const = 0;
    virtual Vector getNextDirection(const Vector& normal, std::function<float()>& rng) const = 0;
    virtual Color getEmittance() const = 0;
};

} // KGVR

#endif // MATERIAL_H
