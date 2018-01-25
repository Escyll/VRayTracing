#ifndef POINT_H
#define POINT_H

namespace KGVR {

class Vector;
class Point
{
public:
    Point();
    Point(float x, float y, float z);

    Point operator+(const Vector& rhs);
    Vector operator-(const Point& rhs);
    friend Vector operator-(const Point& lhs, const Point& rhs);

    friend class Vector;
    float getX() const;
    float getY() const;
    float getZ() const;

private:
    float m_x;
    float m_y;
    float m_z;
};

} // KGVR

#endif // POINT_H
