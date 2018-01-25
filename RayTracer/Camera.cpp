#include "Camera.h"

namespace KGVR {

Camera::Camera(int width, int height)
    : m_width(width)
    , m_height(height)
    , m_direction(0, 0, 1)
    , m_topLeft(-2.f, 2.f * width / height, 0)
{
}

Ray Camera::getRay(int x, int y)
{
    auto left = m_topLeft.getX() + 4.f*(static_cast<float>(x) / m_width);
    auto top = m_topLeft.getY() - (4.f* m_width / m_height) * (static_cast<float>(m_height - y) / m_height);
    Point pixelCoord(left, top, 0.f);
    Point origin(0.f, 0.f, -2.f);
    return Ray(origin, Vector::normalize(pixelCoord - origin));
}

void Camera::moveCamera(const Vector& delta)
{
    m_topLeft = m_topLeft + delta;
}

} // KGVR
