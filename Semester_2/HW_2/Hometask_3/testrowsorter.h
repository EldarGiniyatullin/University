#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "arrayheapsorter.h"

class TestRowSorter : public QObject
{
    Q_OBJECT

public:
    explicit TestRowSorter(QObject *parent = 0) : QObject(parent) {}

private:
    ArrayHeapSorter<int> *testSorter;
    int **controlArray;

private slots:
    void initTestCase()
    {
        testSorter = new ArrayHeapSorter<int>;
        controlArray = new int*[5];
        for (int i = 0; i < 5; i++)
        {
            controlArray[i] = new int[5];
            for (int j = 0; j < 5; j++)
            {
                controlArray[i][j] = 40 - 10 * i + j;
            }
        }
    }

    void testResult()
    {
        bool tmp = true;
        testSorter->sortArray(controlArray, 5);
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (controlArray[i][j] !=  10 * i + j)
                {
                    tmp = false;
                    break;
                }
            }
        }
        QVERIFY(tmp);
    }

    void cleanupTestCase()
    {
        delete testSorter;
        for (int i = 0; i < 5; i++)
            delete controlArray[i];
        delete[] controlArray;
    }
};
