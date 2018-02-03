#ifndef CAMERA_H
#define CAMERA_H

#include <Ray.h>

namespace KGVR {

class Camera
{
public:
    Camera(int width, int height);
    Ray getRay(int x, int y);
    void moveCamera(const Vector& delta);
private:
    int m_width, m_height;
    float m_dx, m_dy, m_ratio;
    Vector m_lookDirection, m_up, m_left;
    Point m_origin;
};

} // KGVR

#endif // CAMERA_H
