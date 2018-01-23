#include "Point.h"
#include "Vector.h"

#include "TestPoint.h"

namespace KGVR {

void TestPoint::testPoint()
{
    auto input = Point();
    QVERIFY(input.getX() == 0.0);
    QVERIFY(input.getY() == 0.0);
    QVERIFY(input.getZ() == 0.0);
}

void TestPoint::testPointAddVector()
{
    auto input1 = Point(1, 2, 3);
    auto input2 = Vector(4, 5, 6);
    Point expected = Point(5, 7, 9);
    Point actual = input1 + input2;
    QCOMPARE(actual.getX(), expected.getX());
    QCOMPARE(actual.getY(), expected.getY());
    QCOMPARE(actual.getZ(), expected.getZ());
}

void TestPoint::testPointXYZ()
{
    auto input = Point(1, 2, 3);
    QVERIFY(input.getX() == 1.0);
    QVERIFY(input.getY() == 2.0);
    QVERIFY(input.getZ() == 3.0);
}

}

QTEST_APPLESS_MAIN(KGVR::TestPoint)
