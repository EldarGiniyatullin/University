#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include <iostream>
#include "bag.h"

using std::ifstream;
using std::ios_base;

class TestBag : public QObject
{
    Q_OBJECT

public:
    explicit TestBag(QObject *parent = 0) : QObject(parent) {}

private:
    Bag<int> *testSet;
    Bag<int> *testSet1;
    Bag<int> *testSet2;

private slots:
    void init()
    {
        testSet = new Bag<int>;
        testSet1 = new Bag<int>;
    }

    void testEmptySet()
    {
        QVERIFY(testSet->getSize() == 0);
    }

    void testValueNumber()
    {
        QVERIFY(testSet->valueNumber(5) == 0);
    }
    void testValueNumber1()
    {
        testSet->addValue(5);
        testSet->addValue(5);
        QVERIFY(testSet->valueNumber(5) == 2);
        testSet->deleteValue(5);
        testSet->deleteValue(5);
    }

    void testDeleteFromSet1()
    {
        testSet->addValue(5);
        testSet->deleteValue(5);
        QVERIFY(testSet->getSize() == 0);
    }

    void testNotEmptySizeSet()
    {
        testSet->addValue(5);
        QVERIFY(testSet->getSize() == 1);
        testSet->deleteValue(5);
    }

    void testDeleteFromSet2()
    {
        testSet->addValue(5);
        testSet->addValue(6);
        testSet->deleteValue(5);
        QVERIFY(testSet->getSize() == 1);
        testSet->deleteValue(6);
    }

    void testDeleteFromSet3()
    {
        testSet->addValue(6);
        testSet->addValue(6);
        testSet->deleteValue(6);
        QVERIFY(testSet->getSize() == 1);
        testSet->deleteValue(6);
    }

    void testAddToSet()
    {
        testSet->addValue(5);
        QVERIFY(testSet->doesBagContain(5));
        testSet->deleteValue(5);
    }

    void testNotAddedValue()
    {
        testSet->addValue(5);
        testSet->addValue(6);
        QVERIFY(!testSet->doesBagContain(7));
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
        bool tmp = testSet2->doesBagContain(3) && testSet2->doesBagContain(4) && (!testSet2->doesBagContain(1)) &&
                (!testSet2->doesBagContain(2)) && (!testSet2->doesBagContain(5)) && (!testSet2->doesBagContain(6));
        QVERIFY(tmp && (testSet2->getSize() == 2));
        delete testSet;
        delete testSet1;
        delete testSet2;
        testSet = new Bag<int>;
        testSet1 = new Bag<int>;
    }

    void testOperatorUnion1()
    {
        testSet->addValue(1);
        testSet->addValue(2);
        testSet1->addValue(3);
        testSet1->addValue(4);
        testSet2 = *testSet + *testSet1;
        bool tmp = testSet2->doesBagContain(3) && testSet2->doesBagContain(4) && testSet2->doesBagContain(1) && testSet2->doesBagContain(2);
        QVERIFY(tmp && (testSet2->getSize() == 4));
        delete testSet;
        delete testSet1;
        delete testSet2;
        testSet = new Bag<int>;
        testSet1 = new Bag<int>;
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
        bool tmp = testSet2->doesBagContain(3) && testSet2->doesBagContain(4) && testSet2->doesBagContain(1) && testSet2->doesBagContain(2)
                && testSet2->doesBagContain(5);
        QVERIFY(tmp && (testSet2->getSize() == 6));
    }

    void cleanup()
    {
        delete testSet;
        delete testSet1;
        delete testSet2;
    }
};
