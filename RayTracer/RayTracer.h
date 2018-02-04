#ifndef RAYTRACER_H
#define RAYTRACER_H

#include <Box.h>
#include <memory>
#include <vector>

#include "Camera.h"
#include "Triangle.h"
#include "Collidable.h"

namespace KGVR {

class RayTracer
{

public:
    RayTracer(int width, int height);
    void render(float* pixels);
    Camera* getCamera();
private:
    int m_width;
    int m_height;
    Camera m_camera;
    std::vector<std::unique_ptr<Collidable>> m_objects;
};

} // KGVR

#endif // RAYTRACER_H
