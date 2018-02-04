#ifndef COLOR_H
#define COLOR_H

namespace KGVR {

class Color
{
public:
    Color();
    Color(float red, float green, float blue);
    Color(float red, float green, float blue, float alpha);
    Color operator*(float rhs) const;
    Color operator*(const Color rhs) const;
    friend Color operator*(float lhs, const Color& rhs);
    Color operator+(const Color& rhs) const;

    float red, green, blue, alpha;
};

} // KGVR

#endif // COLOR_H
