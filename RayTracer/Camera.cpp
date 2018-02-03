#include "Camera.h"

namespace KGVR {

Camera::Camera(int width, int height)
    : m_width(width)
    , m_height(height)
    , m_dx(1.f / width)
    , m_dy(1.f / height)
    , m_ratio(static_cast<float>(m_width) / m_height)
    , m_lookDirection(0, 0, -1)
    , m_up(0, 1, 0)
    , m_left(Vector::normalize(m_up.cross(m_lookDirection)))
    , m_origin(0, 0, 0)
{
}

Ray Camera::getRay(int x, int y)
{
    Vector topLeft(-2.f, 2.f * m_ratio, 0);
    auto left = topLeft.getX() + 4.f*(static_cast<float>(x) / m_width);
    auto top = topLeft.getY() - (4.f* m_ratio) * (static_cast<float>(m_height - y) / m_height);
    Point pixelCoord(left, top, -2.f);
    return Ray(m_origin, Vector::normalize(pixelCoord - m_origin));
}

void Camera::moveCamera(const Vector& delta)
{
    //m_topLeft = m_topLeft + delta;
}

} // KGVR
