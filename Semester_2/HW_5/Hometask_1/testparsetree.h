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
        bool test = false;
        try
        {
            testTree->calculate();
        }
        catch (ParseTree::NoParsedExpression &)
        {
            test = true;
        }
        QVERIFY(test);
    }

    void testNotEmptyTree()
    {
        fin.open("testparsetree1.txt", ios_base::in);
        testTree->parseExpression(fin);
        bool empty = false;
        bool error = false;
        try
        {
            double value = testTree->calculate();
        }
        catch (ParseTree::NoParsedExpression &)
        {
            empty = true;
        }
        catch (Division::DivisionByZero &)
        {
            error = true;
        }
        QVERIFY(!empty && error);
        testTree->clearTree();
        fin.close();
    }

    void testClearTree()
    {
        fin.open("testparsetree3.txt", ios_base::in);
        testTree->parseExpression(fin);
        testTree->clearTree();
        bool empty = false;
        try
        {
            double value = testTree->calculate();
        }
        catch (ParseTree::NoParsedExpression &)
        {
            empty = true;
        }
        QVERIFY(empty);
        fin.close();
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
        catch (ParseTree::NoParsedExpression &)
        {
            empty = true;
        }
        catch (Division::DivisionByZero &)
        {
            error = true;
        }
        QVERIFY(!empty && !error && (value == 322));
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
