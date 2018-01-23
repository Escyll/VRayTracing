#include "Point.h"
#include "Vector.h"

#include "TestVector.h"

namespace KGVR {

void TestVector::testVector()
{
    auto input = Vector();
    QVERIFY(input.getX() == 0.0);
    QVERIFY(input.getY() == 0.0);
    QVERIFY(input.getZ() == 0.0);
}

void TestVector::testVectorAddVector()
{
    auto input1 = Vector(1, 2, 3);
    auto input2 = Vector(4, 5, 6);
    auto expected = Vector(5, 7, 9);
    auto actual = input1 + input2;
    QCOMPARE(actual.getX(), expected.getX());
    QCOMPARE(actual.getY(), expected.getY());
    QCOMPARE(actual.getZ(), expected.getZ());
}

void TestVector::testDotProduct()
{
    auto input1 = Vector(1, 2, 3);
    auto input2 = Vector(3, 4, 5);
    auto expected = 26;
    auto actual = input1.dot(input2);
    QCOMPARE(actual, expected);
}

void TestVector::testCrossProduct()
{
    auto input1 = Vector(-1, 7, 4);
    auto input2 = Vector(-5, 8, 4);
    auto expected = Vector(-4, -16, 27);
    auto actual = input1.cross(input2);
    QCOMPARE(actual.getX(), expected.getX());
    QCOMPARE(actual.getY(), expected.getY());
    QCOMPARE(actual.getZ(), expected.getZ());
}

void TestVector::testDoubleTimesVector()
{
    auto input = Vector(1, 2, 3);
    auto expected = Vector(0.5, 1, 1.5);
    auto actual = 0.5 * input;
    QCOMPARE(actual.getX(), expected.getX());
    QCOMPARE(actual.getY(), expected.getY());
    QCOMPARE(actual.getZ(), expected.getZ());
}

void TestVector::testVectorTimesDouble()
{
    auto input = Vector(1, 2, 3);
    auto expected = Vector(0.5, 1, 1.5);
    auto actual = input * 0.5;
    QCOMPARE(actual.getX(), expected.getX());
    QCOMPARE(actual.getY(), expected.getY());
    QCOMPARE(actual.getZ(), expected.getZ());
}

void TestVector::testVectorDevidedByDouble()
{
    auto input = Vector(1, 2, 3);
    auto expected = Vector(0.5, 1, 1.5);
    auto actual = input / 2;
    QCOMPARE(actual.getX(), expected.getX());
    QCOMPARE(actual.getY(), expected.getY());
    QCOMPARE(actual.getZ(), expected.getZ());
}

void TestVector::testTimesAssign()
{
    auto input = Vector(1, 2, 3);
    auto expected = Vector(0.5, 1, 1.5);
    input *= 0.5;
    auto actual = input;
    QCOMPARE(actual.getX(), expected.getX());
    QCOMPARE(actual.getY(), expected.getY());
    QCOMPARE(actual.getZ(), expected.getZ());
}

void TestVector::testDevideAssign()
{
    auto input = Vector(1, 2, 3);
    auto expected = Vector(0.5, 1, 1.5);
    input /= 2;
    auto actual = input;
    QCOMPARE(actual.getX(), expected.getX());
    QCOMPARE(actual.getY(), expected.getY());
    QCOMPARE(actual.getZ(), expected.getZ());
}

void TestVector::testNormalize()
{
    auto input = Vector(3, 2, -1);
    auto expected = Vector(3.0 / sqrt(14.0), sqrt(2.0 / 7.0), -1.0 / sqrt(14.0));
    input.normalize();
    auto actual = input;
    QCOMPARE(actual.getX(), expected.getX());
    QCOMPARE(actual.getY(), expected.getY());
    QCOMPARE(actual.getZ(), expected.getZ());
}

void TestVector::testLength()
{
    auto input = Vector(1, 2, 3);
    auto expected = sqrt(14);
    auto actual = input.length();
    QCOMPARE(actual, expected);
}

void TestVector::testLengthSquared()
{
    auto input = Vector(1, 2, 3);
    auto expected = 14;
    auto actual = input.lengthSquared();
    QCOMPARE(actual, expected);
}

void TestVector::testVectorXYZ()
{
    auto input = Vector(1, 2, 3);
    QVERIFY(input.getX() == 1.0);
    QVERIFY(input.getY() == 2.0);
    QVERIFY(input.getZ() == 3.0);
}

}

QTEST_APPLESS_MAIN(KGVR::TestVector)
