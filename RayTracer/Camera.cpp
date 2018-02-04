#define _USE_MATH_DEFINES
#include <cmath>

#include "Camera.h"

namespace KGVR {

Camera::Camera(int width, int height)
    : m_width(width)
    , m_height(height)
    , m_ratio(static_cast<float>(m_width) / m_height)
    , m_fov(60)
    , m_orientation(0, Vector(0, 0, -1))
    , m_position(0, 0, 4)
{
    m_pixelCoords.reserve(m_width*m_height);
}

float toRadians(float degree)
{
    return static_cast<float>(M_PI) * degree / 180.f;
}

void Camera::computeRays()
{
    auto viewPortWidth =  2.f * std::tan(0.5f * toRadians(m_fov));
    auto viewPortHeight = viewPortWidth / m_ratio;
    auto viewPortTopLeft = m_position + getForward()
            + 0.5f*viewPortWidth*getLeft()
            + 0.5f*viewPortHeight*getUp();
    auto viewPortTopRight = viewPortTopLeft - viewPortWidth*getLeft();
    auto viewPortBottomLeft = viewPortTopLeft  - viewPortHeight*getUp();

    auto leftToRight = viewPortTopRight - viewPortTopLeft;
    auto topToBottom = viewPortBottomLeft - viewPortTopLeft;
    auto topLeftPixel = viewPortTopLeft + (leftToRight / (viewPortWidth*2*m_width)) + (topToBottom / (viewPortHeight*2*m_height));
    for (int y = 0; y < m_height; y++)
    {
        int offset = y*m_width;
        for (int x = 0; x < m_width; x++)
        {
            m_pixelCoords[offset + x] = topLeftPixel + ((static_cast<float>(x) / m_width) * leftToRight)
                                                     + (static_cast<float>(m_height - y - 1) / m_height) * topToBottom;
        }
    }
}

Ray Camera::getRay(int x, int y)
{
    return Ray(m_position, m_pixelCoords[y*m_width + x] - m_position);
}

void Camera::moveForward(float distance)
{
    m_position += getForward() * distance;
}

void Camera::moveBackward(float distance)
{
    moveForward(-distance);
}

void Camera::moveUp(float distance)
{
    m_position += Vector(0, 1, 0) * distance;
}

void Camera::moveDown(float distance)
{
    moveUp(-distance);
}

void Camera::strafeLeft(float distance)
{
    m_position += getLeft() * distance;
}

void Camera::strafeRight(float distance)
{
    strafeLeft(-distance);
}

void Camera::pitch(float radians)
{
    rotate(radians, Vector(1, 0, 0));
}

void Camera::yaw(float radians)
{
    rotate(radians, Vector(0, 1, 0));
}

void Camera::roll(float radians)
{
    rotate(radians, Vector(0, 0, 1));
}

void Camera::turn(float radians)
{
    rotate(Quaternion(radians, m_orientation * Vector(0, 1, 0)));
}

void Camera::rotate(float radians, const Vector& axis)
{
    rotate(Quaternion(radians, axis));
}

void Camera::rotate(const Quaternion& rotation)
{
    m_orientation = rotation * m_orientation;
}

Vector Camera::getForward() const
{
    return m_orientation.conjugate() * Vector(0, 0, -1);
}

Vector Camera::getLeft() const
{
    return m_orientation.conjugate() * Vector(-1, 0, 0);
}

Vector Camera::getUp() const
{
    return m_orientation.conjugate() * Vector(0, 1, 0);
}

} // KGVR
