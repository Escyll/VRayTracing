#ifndef CAMERA_H
#define CAMERA_H

#include <Quaternion.h>
#include <Ray.h>

namespace KGVR {

class Camera
{
public:
    Camera(int width, int height);
    Ray getRay(int x, int y);

    // Movements
    void moveForward(float distance);
    void moveBackwards(float distance);
    void strafeLeft(float distance);
    void strafeRight(float distance);
    void pitch(float radians);
    void yaw(float radians);
    void roll(float radians);
    void turn(float radians);

private:
    int m_width, m_height;
    float m_dx, m_dy, m_ratio, m_fov;
    Vector m_lookDirection, m_up, m_left;

    void rotate(float radians, const Vector& axis);
    void rotate(const Quaternion& rotation);

    Vector getForward() const;
    Vector getLeft() const;
    Vector getUp() const;

    Quaternion m_orientation;
    Point m_position;
};

} // KGVR

#endif // CAMERA_H
