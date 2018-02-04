#ifndef QUATERNION_H
#define QUATERNION_H

namespace KGVR {

class Vector;
class Quaternion
{
public:
    Quaternion(float radians, const Vector& axis);
    Quaternion conjugate() const;
    Vector operator*(const Vector& v) const;
    Quaternion operator*(const Quaternion& q) const;
private:
    Vector xyz() const;
    Quaternion(float x, float y, float z, float w);
    float m_x, m_y, m_z, m_w;
};

} // KGVR

#endif // QUATERNION_H
