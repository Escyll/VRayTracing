#ifndef TST_TESTPOINT_H
#define TST_TESTPOINT_H

#include <QtTest>

namespace KGVR {

class TestPoint : public QObject
{
    Q_OBJECT

public:
    TestPoint() = default;
    ~TestPoint() = default;

private slots:
    void testPointXYZ();
    void testPoint();
    void testPointAddVector();
};


} // KGVR

#endif // TST_TESTPOINT_H
