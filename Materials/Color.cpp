#include "Color.h"

namespace KGVR {

Color::Color()
    : Color(0, 0, 0)
{
}

Color::Color(float red, float green, float blue)
    : Color(red, green, blue, 0)
{
}

Color::Color(float red, float green, float blue, float alpha)
    : red(red)
    , green(green)
    , blue(blue)
    , alpha(alpha)
{
}

Color Color::operator*(float rhs) const
{
    return Color(rhs*red, rhs*green, rhs*blue, rhs*alpha);
}

Color Color::operator*(const Color rhs) const
{
    return Color(red*rhs.red, green*rhs.green, blue*rhs.blue, alpha*rhs.alpha);
}

Color operator*(float lhs, const Color& rhs)
{
    return rhs * lhs;
}

Color Color::operator+(const Color& rhs) const
{
    return Color(red + rhs.red, green + rhs.green, blue + rhs.blue, alpha + rhs.alpha);
}

} // KGVR
