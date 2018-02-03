#include <Diffuse.h>
#include <TriangleCollidable.h>
#include <algorithm>

#include "RayTracer.h"
#include "BoxCollidable.h"

namespace KGVR {

RayTracer::RayTracer(int width, int height)
    : m_width(width)
    , m_height(height)
    , m_camera(m_width, m_height)
{
    m_objects.push_back(std::make_unique<BoxCollidable>(Point(1, -3.5, -6), Point(3, -1.5, -4), std::make_unique<Diffuse>(Color { 1.f, 0.f, 0.f, 0.f}) ));
    m_objects.push_back(std::make_unique<BoxCollidable>(Point(-3, -3.5, -6), Point(-1, -1.5, -4), std::make_unique<Diffuse>(Color { 0.f, 1.f, 0.f, 0.f}) ));
    m_objects.push_back(std::make_unique<BoxCollidable>(Point(-1, 1.5, -6), Point(1, 3.5, -4), std::make_unique<Diffuse>(Color { 0.f, 0.f, 1.f, 0.f}) ));
    m_objects.push_back(std::make_unique<TriangleCollidable>(Point(-2, -2.5, -5), Point(2, -2.5, -5), Point(0, 2.5, -5), std::make_unique<Diffuse>(Color { .3f, 0.f, .3f, 0.f}) ));
}

void RayTracer::render(float* pixels)
{
    for (int y = 0; y < m_height; y++)
    {
        auto offsetHeight = 4*m_height*y;
        for (int x = 0; x < m_width; x++)
        {
            auto ray = m_camera.getRay(x, y);
            auto totalOffset = offsetHeight + 4*x;
            Collidable* closest = nullptr;
            float closestT = INFINITY;
            float currentT;
            for (auto& object : m_objects)
            {
                if (object->hits(ray, currentT) && currentT < closestT)
                {
                    closest = object.get();
                    closestT = currentT;
                }
            }
            if (closest)
            {
                auto hitpoint = ray.getOrigin() + ray.getDirection() * closestT;
                auto normal = closest->getNormal(hitpoint);
                auto shade = std::max(0.f, normal.dot(-ray.getDirection()));
                auto color = closest->getMaterial()->getColor();
                pixels[totalOffset] = shade*color.blue;
                pixels[totalOffset + 1] = shade*color.green;
                pixels[totalOffset + 2] = shade*color.red;
            }
            else
            {
                pixels[totalOffset] = 0.f;
                pixels[totalOffset + 1] = 0.f;
                pixels[totalOffset + 2] = 0.f;
            }
        }
    }

}

} // KGVR
