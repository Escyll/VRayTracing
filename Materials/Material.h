#ifndef MATERIAL_H
#define MATERIAL_H

#include "Color.h"

namespace KGVR {

class Material
{
public:
    virtual Color getColor() const = 0;
};

} // KGVR

#endif // MATERIAL_H
