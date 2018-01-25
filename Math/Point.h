#ifndef POINT_H
#define POINT_H

namespace KGVR {

class Vector;
class Point
{
public:
    Point();
    Point(double x, double y, double z);

    Point operator+(const Vector& rhs);
    Vector operator-(const Point& rhs);
    friend Vector operator-(const Point& lhs, const Point& rhs);

    friend class Vector;
    double getX() const;
    double getY() const;
    double getZ() const;

private:
    double m_x;
    double m_y;
    double m_z;
};

} // KGVR

#endif // POINT_H
