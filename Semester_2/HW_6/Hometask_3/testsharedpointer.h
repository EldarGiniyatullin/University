#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "sharedpointer.h"


class TestSharedPointer : public QObject
{
    Q_OBJECT

public:
    explicit TestSharedPointer(QObject *parent = 0) : QObject(parent) {}


private slots:

    void testEmptyPointer()
    {
        SharedPointer<int> a;
        QVERIFY(a.pointer() == nullptr);
    }

    void testPointer()
    {
        SharedPointer<int> b(new int(2014));
        QVERIFY(*(b.pointer()) == 2014);
        QVERIFY(b.count() == 1);
    }

    void testCopiedPointer()
    {
        SharedPointer<int> c(new int(2014));
        SharedPointer<int> d(c);
        QVERIFY(*(c.pointer()) == 2014);
        QVERIFY(*(d.pointer()) == 2014);
        QVERIFY(c.count() == 2);
        QVERIFY(d.count() == 2);
    }

    void testOperatorEqual()
    {
        SharedPointer<int> a(new int(2014));
        SharedPointer<int> b = a;
        QVERIFY(*(a.pointer()) == 2014);
        QVERIFY(*(b.pointer()) == 2014);
        QVERIFY(a.count() == 2);
        QVERIFY(b.count() == 2);
    }

    void testOperatorEqualItself()
    {
        int *testNumber = new int(2014);
        SharedPointer<int> c(testNumber);
        SharedPointer<int> d(testNumber);
        d = c;
        QVERIFY(*(c.pointer()) == 2014);
        QVERIFY(*(d.pointer()) == 2014);
        QVERIFY(c.count() == 1);
        QVERIFY(d.count() == 1);
    }
};


