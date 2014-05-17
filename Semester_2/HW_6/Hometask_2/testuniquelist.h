#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include <iostream>
#include "uniquelist.h"

using std::ifstream;
using std::ios_base;

class TestUniqueList : public QObject
{
    Q_OBJECT

public:
    explicit TestUniqueList(QObject *parent = 0) : QObject(parent) {}

private:
    UniqueList<int> *testUniqueList;

private slots:
    void initTestCase()
    {
        testUniqueList = new UniqueList<int>;
    }

    void testEmptySet()
    {
        QVERIFY(testUniqueList->getSize() == 0);
    }

    void testNotEmptySizeSet()
    {
        testUniqueList->addValue(5);
        QVERIFY(testUniqueList->getSize() == 1);
        testUniqueList->deleteValue(5);
    }

    void testDeleteFromSet1()
    {
        testUniqueList->addValue(5);
        testUniqueList->deleteValue(5);
        QVERIFY(testUniqueList->getSize() == 0);
    }

    void testDeleteFromSet2()
    {
        testUniqueList->addValue(5);
        testUniqueList->addValue(6);
        testUniqueList->deleteValue(5);
        QVERIFY(testUniqueList->getSize() == 1);
        testUniqueList->deleteValue(6);
    }

    void testAddToSet()
    {
        testUniqueList->addValue(5);
        QVERIFY(testUniqueList->doesContain(5));
        testUniqueList->deleteValue(5);
    }

    void cleanupTestCase()
    {
        delete testUniqueList;
    }
};

