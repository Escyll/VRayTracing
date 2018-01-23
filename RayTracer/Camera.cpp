#include "Camera.h"

namespace KGVR {

Camera::Camera(int width, int height)
    : m_width(width)
    , m_height(height)
    , m_direction(0, 0, 1)
    , m_topLeft(-2, 2, 0)
{
}

Ray Camera::getRay(int x, int y)
{
    auto left = m_topLeft.getX() + 4.0*(static_cast<double>(x) / m_width);
    auto top = m_topLeft.getY() - 4.0*(static_cast<double>(m_height - y) / m_height);
    Point origin(left, top, 0);
    return Ray(origin, m_direction);
}

void Camera::moveCamera(const Vector& delta)
{
    m_topLeft = m_topLeft + delta;
}

} // KGVR
