#include "RayTracer.h"

namespace KGVR {

RayTracer::RayTracer(int width, int height)
    : m_width(width)
    , m_height(height)
    , m_camera(m_width, m_height)
    , m_triangle(Point(1,-1, 2), Point(-1,-1, 2), Point(0,1, 80))
{
}

void RayTracer::render(float* pixels)
{
    for (int y = 0; y < m_height; y++)
    {
        auto offsetHeight = 4*m_height*y;
        for (int x = 0; x < m_width; x++)
        {
            auto ray = m_camera.getRay(x, y);
            Vector hitpoint;
            auto totalOffset = offsetHeight + 4*x;
            if (m_rayCollider.hits(ray, m_triangle, hitpoint))
            {
                auto shade = (-m_triangle.getNormal()).dot(ray.getDirection());
                pixels[totalOffset] = shade*1.f;
                pixels[totalOffset + 1] = shade*1.f;
                pixels[totalOffset + 2] = shade*1.f;
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
