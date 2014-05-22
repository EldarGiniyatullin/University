#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "set.h"
#include <iostream>

using std::ifstream;
using std::ios_base;

class TestSet : public QObject
{
    Q_OBJECT

public:
    explicit TestSet(QObject *parent = 0) : QObject(parent) {}

private:
    Set<int> *testSet;
    Set<int> *testSet1;
    Set<int> *testSet2;

private slots:
    void init()
    {
        testSet = new Set<int>;
        testSet1 = new Set<int>;
    }

    void testEmptySet()
    {
        QVERIFY(testSet->getSize() == 0);
    }

    void testNotEmptySizeSet()
    {
        testSet->addValue(5);
        QVERIFY(testSet->getSize() == 1);
    }

    void testDeleteFromSet1()
    {
        testSet->addValue(5);
        testSet->deleteValue(5);
        QVERIFY(testSet->getSize() == 0);
    }

    void testDeleteFromSet2()
    {
        testSet->addValue(5);
        testSet->addValue(6);
        testSet->deleteValue(5);
        QVERIFY(testSet->getSize() == 1);
        testSet->deleteValue(6);
    }

    void testAddToSet()
    {
        testSet->addValue(5);
        QVERIFY(testSet->doesSetContain(5));
        testSet->deleteValue(5);
    }

    void testNotAddedValue()
    {
        testSet->addValue(5);
        testSet->addValue(6);
        QVERIFY(!testSet->doesSetContain(7));
        testSet->deleteValue(5);
        testSet->deleteValue(6);
    }

    void testOperatorIntersection()
    {
        testSet->addValue(1);
        testSet->addValue(2);
        testSet->addValue(3);
        testSet->addValue(4);
        testSet1->addValue(3);
        testSet1->addValue(4);
        testSet1->addValue(5);
        testSet1->addValue(6);
        testSet2 = *testSet * *testSet1;
        bool tmp = testSet2->doesSetContain(3) && testSet2->doesSetContain(4) && (!testSet2->doesSetContain(1)) &&
                (!testSet2->doesSetContain(2)) && (!testSet2->doesSetContain(5)) && (!testSet2->doesSetContain(6));
        QVERIFY(tmp && (testSet2->getSize() == 2));
        delete testSet;
        delete testSet1;
        delete testSet2;
        testSet = new Set<int>;
        testSet1 = new Set<int>;
    }

    void testOperatorUnion1()
    {
        testSet->addValue(1);
        testSet->addValue(2);
        testSet1->addValue(3);
        testSet1->addValue(4);
        testSet2 = *testSet + *testSet1;
        bool tmp = testSet2->doesSetContain(3) && testSet2->doesSetContain(4) && testSet2->doesSetContain(1) && testSet2->doesSetContain(2);
        QVERIFY(tmp && (testSet2->getSize() == 4));
        delete testSet;
        delete testSet1;
        delete testSet2;
        testSet = new Set<int>;
        testSet1 = new Set<int>;
    }

    void testOperatorUnion2()
    {
        testSet->addValue(1);
        testSet->addValue(2);
        testSet->addValue(3);
        testSet1->addValue(3);
        testSet1->addValue(4);
        testSet1->addValue(5);
        testSet2 = *testSet + *testSet1;
        bool tmp = testSet2->doesSetContain(3) && testSet2->doesSetContain(4) && testSet2->doesSetContain(1) && testSet2->doesSetContain(2)
                && testSet2->doesSetContain(5);
        QVERIFY(tmp && (testSet2->getSize() == 5));
        delete testSet;
        delete testSet1;
        delete testSet2;
        testSet = new Set<int>;
        testSet1 = new Set<int>;
    }

    void cleanup()
    {
        delete testSet;
        delete testSet1;
    }
};
