#include "Diffuse.h"

namespace KGVR {

Diffuse::Diffuse(const Color& color)
    : m_color(color)
{
}

Color Diffuse::getColor() const
{
    return m_color;
}

}
