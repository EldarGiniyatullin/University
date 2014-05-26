#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include <iostream>
#include "stackcalculator.h"

class TestCalcuator : public QObject
{
    Q_OBJECT

public:
    explicit TestCalcuator(QObject *parent = 0) : QObject(parent) {}

private:
    StackCalculator *testCalc;

private slots:
    void init()
    {
        testCalc = new StackCalculator;
    }

    void correctEmptyCalc()
    {
        QVERIFY(!testCalc->isExpressionCorrect());
    }

    void correctEmptyExpression()
    {
        testCalc->setExpression("");
        testCalc->readExpressionFromString();
        QVERIFY(!testCalc->isExpressionCorrect());
    }

    void verifyIncorrectExpression1()
    {
        double value = testCalc->calculateExpression("(");
        QVERIFY(!testCalc->isExpressionCorrect());
    }

    void verifyIncorrectExpression2()
    {
        double value = testCalc->calculateExpression("2+()");
        QVERIFY(!testCalc->isExpressionCorrect());
    }

    void verifyIncorrectExpression3()
    {
        double value = testCalc->calculateExpression("2+3()");
        QVERIFY(!testCalc->isExpressionCorrect());
    }

    void verifyIncorrectExpression4()
    {
        double value = testCalc->calculateExpression("(3-2");
        QVERIFY(!testCalc->isExpressionCorrect());
    }

    void verifyIncorrectExpression5()
    {
        double value = testCalc->calculateExpression("(3-2))");
        QVERIFY(!testCalc->isExpressionCorrect());
    }

    void verifyIncorrectExpression6()
    {
        double value = testCalc->calculateExpression("+");
        QVERIFY(!testCalc->isExpressionCorrect());
    }

    void verifyIncorrectExpression7()
    {
        double value = testCalc->calculateExpression("2/(3-3)");
        QVERIFY(!testCalc->isExpressionCorrect());
    }

    void verifyCorrectExpression1()
    {
        double value = testCalc->calculateExpression("(1+1)");
        QVERIFY(testCalc->isExpressionCorrect());
    }

    void verifyCorrectExpression2()
    {
        double value = testCalc->calculateExpression("2+(3/1)");
        QVERIFY(testCalc->isExpressionCorrect());
    }

    void verifyCorrectExpression3()
    {
        double value = testCalc->calculateExpression("2+3*(1+4)");
        QVERIFY(testCalc->isExpressionCorrect());
    }

    void verifyCorrectExpression4()
    {
        double value = testCalc->calculateExpression("1+1+1+1+3.5*(-7.3+-7.5)");
        QVERIFY(testCalc->isExpressionCorrect());
    }

    void verifyCorrectExpression5()
    {
        double value = testCalc->calculateExpression("-7");
        QVERIFY(testCalc->isExpressionCorrect());
    }

    void verifyCorrectExpression6()
    {
        double value = testCalc->calculateExpression("1+(-7)");
        QVERIFY(testCalc->isExpressionCorrect());
    }

    void verifyCorrectExpressionResult1()
    {
        double value = testCalc->calculateExpression("(1+1)");
        QVERIFY(value == 2);
    }

    void verifyCorrectExpressionResult2()
    {
        double value = testCalc->calculateExpression("2+2+(3/1)");
        QVERIFY(value == 7);
    }

    void verifyCorrectExpressionResult3()
    {
        double value = testCalc->calculateExpression("2+2+3*(1+4)");
        QVERIFY(value == 19);
    }

    void verifyCorrectExpressionResult4()
    {
        double value = testCalc->calculateExpression("-7");
        QVERIFY(value == -7);
    }

    void verifyCorrectExpressionResult5()
    {
        double value = testCalc->calculateExpression("1+(-7)");
        QVERIFY(value == -6);
    }

    void cleanup()
    {
        delete testCalc;
    }
};
