#ifndef KGVR_VECTOR_H
#define KGVR_VECTOR_H

namespace KGVR {

class Point;
class Vector
{
public:
    Vector();
    Vector(double x, double y, double z);
    Vector& operator=(const Point& rhs);
    Vector operator+(const Vector& rhs) const;
    Vector operator-(const Vector& rhs) const;
    Vector operator-() const;
    Vector operator*(double rhs) const;
    double dot(const Vector& rhs) const;
    Vector cross(const Vector& rhs) const;
    static Vector cross(const Vector &a, const Vector &b);

    Vector& operator*=(double rhs);
    friend Vector operator*(double lhs, const Vector& rhs);
    Vector operator/(double rhs) const;
    Vector& operator/=(double rhs);

    void normalize();
    static Vector normalize(const Vector&);

    double length() const;
    double lengthSquared() const;

    friend class Point;
    double getX() const;
    double getY() const;
    double getZ() const;

private:
    double m_x;
    double m_y;
    double m_z;
};

} // KGVR

#endif // KGVR_VECTOR_H
