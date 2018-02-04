#ifndef DIFFUSE_H
#define DIFFUSE_H

#include "Material.h"
#include "Color.h"

namespace KGVR {

class Diffuse : public Material
{
public:
    Diffuse(const Color& surfaceColor, const Color& emittanceColor);
    Color getColor() const;
    Vector getNextDirection(const Vector& normal, std::function<float()>& rng) const;
    Color getEmittance() const;
private:
    Color m_surfaceColor;
    Color m_emittanceColor;
};

} // KGVR

#endif // DIFFUSE_H
