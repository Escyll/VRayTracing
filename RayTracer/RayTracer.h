#ifndef RAYTRACER_H
#define RAYTRACER_H

#include <Box.h>
#include <memory>
#include <vector>
#include <functional>
#include <random>

#include "Camera.h"
#include "Triangle.h"
#include "Collidable.h"

namespace KGVR {

class RayTracer
{

public:
    RayTracer(int width, int height);
    void render(float* pixels);
    void restartSampling();
    Camera* getCamera();
private:
    int m_width;
    int m_height;
    int m_sampleCount;
    Camera m_camera;
    std::vector<std::unique_ptr<Collidable>> m_objects;
    std::mt19937 m_gen;
    std::uniform_real_distribution<float> m_dis;
    std::function<float()> m_rng;

    Color traceRay(const Ray& ray, int depth);
};

} // KGVR

#endif // RAYTRACER_H
