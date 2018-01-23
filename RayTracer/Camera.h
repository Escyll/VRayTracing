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
    int m_width;
    int m_height;
    Vector m_direction;
    Point m_topLeft;
};

} // KGVR

#endif // CAMERA_H
