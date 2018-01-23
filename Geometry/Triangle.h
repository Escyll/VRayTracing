#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Point.h"

namespace KGVR {

class Triangle
{
public:
    Triangle() = delete;
    Triangle(const Point& v0, const Point& v1, const Point& v2);
    Point getV0() const;
    Point getV1() const;
    Point getV2() const;

private:
    Point m_v0;
    Point m_v1;
    Point m_v2;
};

} // KGVR

#endif // TRIANGLE_H
