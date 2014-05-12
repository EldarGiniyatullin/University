#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "stackcalculator.h"

class CalculatorTest : public QObject
{
    Q_OBJECT

public:
    explicit CalculatorTest(QObject *parent = 0) : QObject(parent) {}

private:
    StackCalculator *calculator;

private slots:
    void initTestCase()
    {
        calculator = new StackCalculator;
    }

    void testEmptyCorrectness()
    {
        QVERIFY(calculator->isExpressionCorrect());
    }

    void testCalculator()
    {
        calculator->originalExpression->addElement(2.5);
        calculator->originalExpression->addElement('*');
        calculator->originalExpression->addElement('(');
        calculator->originalExpression->addElement(0.4);
        calculator->originalExpression->addElement('/');
        calculator->originalExpression->addElement(-0.1);
        calculator->originalExpression->addElement(')');
        calculator->reversePolishNotation();
        calculator->calculateReversePolishNotation();
        QVERIFY(calculator->result == -10);
    }

    void cleanupTestCase()
    {
        delete calculator;
    }
};
