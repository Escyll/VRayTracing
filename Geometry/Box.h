#ifndef BOX_H
#define BOX_H

#include "Vector.h"
#include "Point.h"

namespace KGVR {

class Box
{
public:
    Box(const Point& start, const Point& end);
    Point getStart() const;
    Point getEnd() const;
    Vector getNormal(const Point&) const;

private:
    Point m_start;
    Point m_end;
};

} // KGVR

#endif // BOX_H
