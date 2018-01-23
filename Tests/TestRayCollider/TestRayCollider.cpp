#include "RayCollider.h"
#include "Ray.h"
#include "Triangle.h"
#include "Vector.h"
#include "Point.h"

#include "TestRayCollider.h"

namespace KGVR {

void TestRayCollider::testHitsTriangle()
{
    RayCollider rayCollider;
    Ray ray(Point(0, 0, 0), Vector(0, 0, 1));
    Triangle triangle(Point(1,-1, 2), Point(-1,-1, 2), Point(0,1, 2));
    Vector hitPoint;
    QVERIFY(rayCollider.hits(ray, triangle, hitPoint));
    auto expected = Vector(0, 0, 2);
    QCOMPARE(hitPoint.getX(), expected.getX());
    QCOMPARE(hitPoint.getY(), expected.getY());
    QCOMPARE(hitPoint.getZ(), expected.getZ());
}

}

QTEST_APPLESS_MAIN(KGVR::TestRayCollider)
