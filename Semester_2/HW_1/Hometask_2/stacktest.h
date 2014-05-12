#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "linkedstack.h"
#include "arraystack.h"

class StackTest : public QObject
{
    Q_OBJECT

public:
    explicit StackTest(QObject *parent = 0) : QObject(parent) {}

private:
    LinkedStack *linkedStack;
    ArrayStack *arrayStack;

private slots:
    void initTestCase()
    {
        linkedStack = new LinkedStack();
        arrayStack = new ArrayStack(2);
    }

    void testEmptyLStack()
    {
        QVERIFY(linkedStack->isEmpty());
    }

    void testPopEmptyLStack()
    {
        linkedStack->pop();
        QVERIFY(linkedStack->isEmpty());
    }

    void testPushDLList()
    {
        linkedStack->push(1.0);
        QVERIFY(!linkedStack->isEmpty());
        linkedStack->pop();
    }

    void testFullAList()
    {
        arrayStack->push(1.0);
        arrayStack->push(2.0);
        QVERIFY(arrayStack->isStackFull());
    }

    void cleanupTestCase()
    {
        delete arrayStack;
        delete linkedStack;
    }
};

