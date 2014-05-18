#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "vector.h"


class TestVector : public QObject
{
    Q_OBJECT

public:
    explicit TestVector(QObject *parent = 0) : QObject(parent) {}

private slots:

    void testVector1()
    {
        Vector<int, 3> a (5, 6, 7);
        QVERIFY(a.getDimensionValue(0) == 5 && a.getDimensionValue(1) == 6 && a.getDimensionValue(2) == 7);
    }

    void testVector2()
    {
        Vector<int, 3> b (1);
        QVERIFY(b.getDimensionValue(0) == 1 && b.getDimensionValue(1) == 1 && b.getDimensionValue(2) == 1);
    }

    void testNullVector()
    {
        Vector<int, 3> c (0, 0, 0);
        QVERIFY(c.isNullVector());
    }

    void testNullVector1()
    {
        Vector<int, 3> d (1, 0, 0);
        QVERIFY(!d.isNullVector());
    }

    void testSum()
    {
        Vector<int, 3> a (5, 7, -9);
        Vector<int, 3> b (8);
        Vector<int, 3> c = a + b;
        QVERIFY(c.getDimensionValue(0) == 13 && c.getDimensionValue(1) == 15 && c.getDimensionValue(2) == -1);
    }

    void testScalarProduct()
    {
        Vector<int, 3> a (5, 7, -9);
        Vector<int, 3> b (8);
        QVERIFY(a * b == 24);
    }

    void testScalarProductNullVector()
    {
        Vector<int, 4> a (5, 7, -9, 1);
        Vector<int, 4> b (0);
        QVERIFY(a * b == 0);
    }
};


