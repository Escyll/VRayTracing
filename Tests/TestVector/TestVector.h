#ifndef TST_TESTVECTOR_H
#define TST_TESTVECTOR_H

#include <QtTest>

namespace KGVR {

class TestVector : public QObject
{
    Q_OBJECT

public:
    TestVector() = default;
    ~TestVector() = default;

private slots:
    void testVectorXYZ();
    void testVector();
    void testVectorAddVector();
    void testDotProduct();
    void testCrossProduct();
    void testDoubleTimesVector();
    void testVectorTimesDouble();
    void testVectorDevidedByDouble();
    void testTimesAssign();
    void testDevideAssign();
    void testNormalize();
    void testLength();
    void testLengthSquared();
};

} // KGVR

#endif // TST_TESTVECTOR_H
