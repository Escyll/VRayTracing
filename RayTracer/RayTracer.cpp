#include <Diffuse.h>
#include <TriangleCollidable.h>
#include <algorithm>
#include <memory>

#include "RayTracer.h"
#include "BoxCollidable.h"

namespace KGVR {

RayTracer::RayTracer(int width, int height)
    : m_width(width)
    , m_height(height)
    , m_sampleCount(0)
    , m_camera(m_width, m_height)
    , m_dis(0.f, 1.f)
{
    m_objects.push_back(std::make_unique<BoxCollidable>(Point(1, -3.5, -6), Point(3, -1.5, -4), std::make_unique<Diffuse>(Color(1.f, 0.f, 0.f), Color(8.f, 0.f, 0.f))));
    m_objects.push_back(std::make_unique<BoxCollidable>(Point(-3, -3.5, -6), Point(-1, -1.5, -4), std::make_unique<Diffuse>(Color(0.f, 1.f, 0.f), Color(0.f, 8.f, 0.f))));
    m_objects.push_back(std::make_unique<BoxCollidable>(Point(-1, 0.5, -6), Point(1, 2.5, -4), std::make_unique<Diffuse>(Color(0.f, 0.f, 1.f), Color(0.f, 0.f, 8.f))));
    m_objects.push_back(std::make_unique<TriangleCollidable>(Point(-2, -2.5, -5.5), Point(2, -2.5, -5.5), Point(0, 1.5, -5.5), std::make_unique<Diffuse>(Color(1, 1, 1), Color())));
    std::random_device rd;
    m_gen = std::mt19937(rd());
    m_rng = [this]() { return m_dis(m_gen); };
}

void RayTracer::render(float* pixels)
{
    for (int y = 0; y < m_height; y++)
    {
        auto offsetHeight = 4*m_height*y;
        #pragma omp parallel for
        for (int x = 0; x < m_width; x++)
        {
            auto totalOffset = offsetHeight + 4*x;

            auto ray = m_camera.getRay(x, y);
            auto color = traceRay(ray, 0);
            auto sampleFraction = 1.f / (m_sampleCount + 1);
            pixels[totalOffset] = sampleFraction*(m_sampleCount*pixels[totalOffset] + color.blue);
            pixels[totalOffset + 1] = sampleFraction*(m_sampleCount*pixels[totalOffset + 1] + color.green);
            pixels[totalOffset + 2] = sampleFraction*(m_sampleCount*pixels[totalOffset + 2] + color.red);
        }
    }
    m_sampleCount++;
}

Color RayTracer::traceRay(const Ray& ray, int depth)
{
    if (depth == 6)
        return Color();

    Collidable* hitObject = nullptr;
    float closestT = INFINITY;
    float currentT;
    for (auto& object : m_objects)
    {
        if (object->hits(ray, currentT) && currentT < closestT)
        {
            hitObject = object.get();
            closestT = currentT;
        }
    }
    Color brdf;
    if (hitObject)
    {
        auto material = hitObject->getMaterial();
        auto hitPoint = ray.getOrigin() + ray.getDirection() * closestT;
        auto normal = hitObject->getNormal(hitPoint);
        auto nextDirection = material->getNextDirection(normal, m_rng);
        auto nextRay = Ray(hitPoint + 0.0001f*nextDirection, nextDirection);
        brdf = material->getEmittance() + 2*traceRay(nextRay, depth + 1)*normal.dot(nextDirection)*material->getColor();
    }
    return brdf;
}

void RayTracer::restartSampling()
{
    m_sampleCount = 0;
    m_camera.computeRays();
}

Camera* RayTracer::getCamera()
{
    return &m_camera;
}

} // KGVR
