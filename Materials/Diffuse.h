#ifndef DIFFUSE_H
#define DIFFUSE_H

#include "Material.h"

namespace KGVR {

class Diffuse : public Material
{
public:
    Diffuse(const Color&);
    Color getColor() const;
private:
    Color m_color;
};

} // KGVR

#endif // DIFFUSE_H
