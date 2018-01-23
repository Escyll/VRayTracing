#include "RayTracer.h"

namespace KGVR {

RayTracer::RayTracer(int width, int height)
    : m_width(width)
    , m_height(height)
    , m_camera(m_width, m_height)
    , m_triangle(Point(1,-1, 2), Point(-1,-1, 2), Point(0,1, 2))
{
}

void RayTracer::render(float* pixels)
{
    m_camera.moveCamera(Vector(0.01, 0.01, 0));
    for (int y = 0; y < m_height; y++)
    {
        int offset = 3*m_height*y;
        for (int x = 0; x < m_width; x++)
        {
            auto ray = m_camera.getRay(x, y);
            Vector hitpoint;
            if ( (x > 0.5*m_width) && (y > 0.5*m_height) )
            {
                hitpoint.normalize();
            }
            if (m_rayCollider.hits(ray, m_triangle, hitpoint))
            {
                pixels[offset + 3*x] = 1.0f;
                pixels[offset + 3*x + 1] = 1.0f;
                pixels[offset + 3*x + 2] = 1.0f;
            }
            else
            {
                pixels[offset + 3*x] = 0.0f;
                pixels[offset + 3*x + 1] = 0.0f;
                pixels[offset + 3*x + 2] = 0.0f;
            }
        }
    }

}

} // KGVR
