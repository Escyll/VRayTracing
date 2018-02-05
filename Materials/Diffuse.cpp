#define _USE_MATH_DEFINES
#include <cmath>

#include "Diffuse.h"
#include "Vector.h"
#include "Color.h"

namespace KGVR {

Diffuse::Diffuse(const Color& surfaceColor, const Color& emittanceColor)
    : m_surfaceColor(surfaceColor)
    , m_emittanceColor(emittanceColor)
{
}

Color Diffuse::getColor() const
{
    return m_surfaceColor;
}

Vector Diffuse::getNextDirection(const Vector& normal, std::function<float()>& rng) const
{
    auto u1 = rng();
    auto u2 = rng();
    float latitude = std::acos(2*u1 - 1) - (static_cast<float>(M_PI) / 2.f);
    float longitude = 2.f*static_cast<float>(M_PI)*u2;
    auto cosLatitude = std::cos(latitude);
    Vector randomVec(cosLatitude*std::cos(longitude), cosLatitude*std::sin(longitude), std::sin(latitude));
    return randomVec.dot(normal) > 0 ? randomVec : -randomVec;
}

Color Diffuse::getEmittance() const
{
    return m_emittanceColor;
}

} // KGVR
