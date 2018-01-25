#ifndef RAYTRACER_H
#define RAYTRACER_H

#include <Box.h>
#include <memory>

#include "RayCollider.h"
#include "Camera.h"
#include "Triangle.h"

namespace KGVR {

class RayTracer
{

public:
    RayTracer(int width, int height);
    void render(float* pixels);
private:
    int m_width;
    int m_height;
    Camera m_camera;
    Triangle m_triangle;
    Box m_box;
    RayCollider m_rayCollider;
};

} // KGVR

#endif // RAYTRACER_H
