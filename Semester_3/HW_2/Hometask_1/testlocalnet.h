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
    Infector *simpleInfector;
    Infector *totalInfector;
    Infector *valueInfector;

private slots:
    void init()
    {
        simpleInfector = new Infector();
        totalInfector = new TotalInfector();
        valueInfector = new ChanceInfector(55);
        testNet = new LocalNet(6, totalInfector);
        testNet->infect(0);
        testNet->connectPCs(0, 1);
        testNet->connectPCs(0, 2);
        testNet->connectPCs(1, 3);
        testNet->connectPCs(1, 4);
        testNet->connectPCs(2, 5);
    }

    /**
     * @brief testFirstInfection  - те ли ПК контактируют с зараженным
     */
    void testFirstInfection()
    {
        testNet->step();
        QVERIFY(testNet->listOfPCs[1].isInfected() && testNet->listOfPCs[2].isInfected());
    }

    /**
     * @brief testFirstInfectionInfectedPC тест переустановки давно зараженного ПК
     */
    void testFirstInfectionInfectedPC()
    {
        testNet->step();
        QVERIFY(!testNet->listOfPCs[0].isInfected());
    }

    /**
     * @brief testFirstInfectionJustInfected отмечаются ли зараженные на последнем ходу ПК как таковые
     */
    void testFirstInfectionJustInfected()
    {
        testNet->step();
        QVERIFY(!testNet->areJustInfected[0] && testNet->areJustInfected[1] && testNet->areJustInfected[2]);
    }

    /**
     * @brief testFirstInfectionNotInfected не появляется ли лишних соединений
     */
    void testFirstInfectionNotInfected()
    {
        testNet->step();
        QVERIFY(!testNet->listOfPCs[3].isInfected() && !testNet->listOfPCs[4].isInfected() && !testNet->listOfPCs[5].isInfected());
    }

    /**
     * @brief testSecondInfectionWave "передаваемость" вируса
     */
    void testSecondInfectionWave()
    {
        testNet->step();
        testNet->step();
        QVERIFY(testNet->areJustInfected[3] && testNet->areJustInfected[4] && testNet->areJustInfected[5]);
    }

    /**
     * @brief testFirstWaveAfterSecondWave становятся ли активными зараженные на прошлом ходу ПК
     */
    void testFirstWaveAfterSecondWave()
    {
        testNet->step();
        testNet->step();
        QVERIFY(!testNet->areJustInfected[1] && !testNet->areJustInfected[2]);
    }

    /**
     * @brief zeroPCInfectedAgain участвует ли в связях ПК с переустановленной на последнем ходу ОС
     */
    void zeroPCInfectedAgain()
    {
        testNet->step();
        testNet->step();
        QVERIFY(testNet->areJustInfected[0] && testNet->listOfPCs[0].isInfected());
    }

    /**
     * @brief osChanging меняется ли ОС у давно зараженного ПК
     */
    void osChanging()
    {
        OperatingSystem zeroOS = testNet->listOfPCs[0].getOS();
        testNet->step();
        QVERIFY(!(zeroOS == testNet->listOfPCs[0].getOS()));
    }

    /**
     * @brief testInfectionConstantChance зависимость заражения ПК от вероятности заражения его ОС
     */
    void testInfectionConstantChance()
    {
        testNet->infectFunction = valueInfector;
        for (int i = 1; i < 5; i++)
            testNet->listOfPCs[i].changeOS(testNet->listOfOS[i - 1]);
        testNet->infect(0);
        testNet->connectPCs(0, 3);
        testNet->connectPCs(0, 4);
        testNet->step();
        QVERIFY(testNet->listOfPCs[1].isInfected()  && testNet->listOfPCs[2].isInfected() && !testNet->listOfPCs[3].isInfected() && !testNet->listOfPCs[4].isInfected());
    }

    void cleanup()
    {
        delete testNet;
        delete simpleInfector;
        delete totalInfector;
        delete valueInfector;
    }
};
