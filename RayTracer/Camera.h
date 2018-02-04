#ifndef CAMERA_H
#define CAMERA_H

#include <vector>

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
    void moveBackward(float distance);
    void moveUp(float distance);
    void moveDown(float distance);
    void strafeLeft(float distance);
    void strafeRight(float distance);
    void pitch(float radians);
    void yaw(float radians);
    void roll(float radians);
    void turn(float radians);
    void computeRays();

private:
    int m_width, m_height;
    float m_ratio, m_fov;
    Quaternion m_orientation;
    Point m_position;
    std::vector<Point> m_pixelCoords;

    void rotate(float radians, const Vector& axis);
    void rotate(const Quaternion& rotation);

    Vector getForward() const;
    Vector getLeft() const;
    Vector getUp() const;
};

} // KGVR

#endif // CAMERA_H
