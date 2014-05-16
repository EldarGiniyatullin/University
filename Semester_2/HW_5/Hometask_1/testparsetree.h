#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include <fstream>
#include "parsetree.h"

using std::ifstream;
using std::ios_base;

class TestParseTree : public QObject
{
    Q_OBJECT

public:
    explicit TestParseTree(QObject *parent = 0) : QObject(parent) {}

private:
    ParseTree *testTree;
    ifstream fin;

private slots:
    void initTestCase()
    {
        testTree = new ParseTree;
    }

    void testEmptyTree()
    {
        double test = testTree->calculate();
        QVERIFY(test == 0);
    }

    void testVerifyResult()
    {
        fin.open("testparsetree2.txt", ios_base::in);
        testTree->parseExpression(fin);
        bool empty = false;
        bool error = false;
        double value = 0;
        try
        {
            value = testTree->calculate();
        }
        catch (Division::DivisionByZero &)
        {
            error = true;
        }
        QVERIFY(value == 322);
        testTree->clearTree();
        fin.close();
    }

    void testDifferentValues()
    {
        fin.open("testparsetree2.txt", ios_base::in);
        testTree->parseExpression(fin);
        double value1 = testTree->calculate();
        fin.close();
        fin.open("testparsetree3.txt", ios_base::in);
        testTree->parseExpression(fin);
        double value2 = testTree->calculate();
        QVERIFY(value1 != value2);
        testTree->clearTree();
        fin.close();
    }

    void cleanupTestCase()
    {
        delete testTree;
    }
};
