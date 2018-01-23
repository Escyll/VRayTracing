#ifndef TESTRAYCOLLIDER_H
#define TESTRAYCOLLIDER_H

#include <QtTest>

namespace KGVR {

class TestRayCollider : public QObject
{
    Q_OBJECT

public:
    TestRayCollider() = default;
    ~TestRayCollider() = default;

private slots:
    void testHitsTriangle();
};

} // KGVR

#endif // TESTRAYCOLLIDER_H
