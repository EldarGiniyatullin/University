#pragma once

#include <QtTest/QTest>
#include <QtCore/QObject>
#include "arrayheapsorter.h"
#include "arrayquicksorter.h"

class TestSorters : public QObject
{
    Q_OBJECT

public:
    explicit TestSorters(QObject *parent = 0) : QObject(parent) {}

private:
    double *array;
    double *controlArray;
    ArrayHeapSorter<double> *heapSorter;
    ArrayQuickSorter<double> *quickSorter;
    void serviceFunction()
    {
        array = new double[5];
        array[0] = -1;
        for (int i = 1; i < 5; i++)
        {
            array[i] = array[i - 1] * (-2.5);
        }
    }
    bool areEqual()
    {
        bool tmp = true;
        for (int i = 0; i < 5; i++)
        {
            if (array[i] != controlArray[i])
            {
                tmp = false;
                break;
            }
        }
        return tmp;
    }

private slots:
    void initTestCase()
    {
        heapSorter = new ArrayHeapSorter<double>;
        quickSorter = new ArrayQuickSorter<double>;
        controlArray = new double[5];
        controlArray[0] = -39.0625;
        controlArray[1] = -6.25;
        controlArray[2] = -1;
        controlArray[3] = 2.5;
        controlArray[4] = 15.625;
    }

    void testHeapSorter()
    {
        serviceFunction();
        heapSorter->sortArray(array, 5);
        QVERIFY(areEqual());
        delete[] array;
    }

    void testQuickSorter()
    {
        serviceFunction();
        quickSorter->sortArray(array, 5);
        QVERIFY(areEqual());
        delete[] array;
    }

    void cleanupTestCase()
    {
        delete[] controlArray;
        delete[] array;
        delete quickSorter;
        delete heapSorter;
    }
};

