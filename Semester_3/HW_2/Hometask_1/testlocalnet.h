#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include <iostream>
#include <QList>
#include "localnet.h"

class TestLocalNet : public QObject
{
    Q_OBJECT

public:
    explicit TestLocalNet(QObject *parent = 0) : QObject(parent) {}

private:
    LocalNet *testNet;

private slots:
    void init()
    {
        testNet = new LocalNet(18);
    }

    void testNumberOfPCs()
    {
        QVERIFY(testNet->numberOfPCs == 18 && testNet->listOfPCs.size() == 18);
    }

    void testIsAnyPCInfected()
    {
        bool isInfected = false;
        for (int i = 0; i < testNet->numberOfPCs; i++)
        {
            if (testNet->listOfPCs[i].isInfected())
            {
                isInfected = true;
                break;
            }
        }
        QVERIFY(isInfected == true);
    }

    void cleanup()
    {
        delete testNet;
    }
};
