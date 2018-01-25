#ifndef KGVR_VECTOR_H
#define KGVR_VECTOR_H

namespace KGVR {

class Point;
class Vector
{
public:
    Vector();
    Vector(float x, float y, float z);
    Vector& operator=(const Point& rhs);
    Vector operator+(const Vector& rhs) const;
    Vector operator-(const Vector& rhs) const;
    Vector operator-() const;
    Vector operator*(float rhs) const;
    float dot(const Vector& rhs) const;
    Vector cross(const Vector& rhs) const;
    static Vector cross(const Vector &a, const Vector &b);

    Vector& operator*=(float rhs);
    friend Vector operator*(float lhs, const Vector& rhs);
    Vector operator/(float rhs) const;
    Vector& operator/=(float rhs);

    void normalize();
    static Vector normalize(const Vector&);

    float length() const;
    float lengthSquared() const;

    friend class Point;
    float getX() const;
    float getY() const;
    float getZ() const;

private:
    float m_x;
    float m_y;
    float m_z;
};

} // KGVR

#endif // KGVR_VECTOR_H
