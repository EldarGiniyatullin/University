#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include <QVector>
#include "graph.h"


class TestGraph : public QObject
{
    Q_OBJECT

public:
    explicit TestGraph(QObject *parent = 0) : QObject(parent) {}

private:
    Graph *testGraph;
    Graph *testLittleGraph;

private slots:
    void init()
    {
        testGraph = new Graph(10);
        testLittleGraph = new Graph(3);
    }

    /**
     * @brief checkEmptyMatrix проверка корректности построения графа
     */
    void checkEmptyMatrix()
    {
        bool flag = true;
        for (int i = 0; i < testGraph->graphSize; i++)
            for (int j = 0; j < testGraph->graphSize; j++)
            {
                if (!((i == j && testGraph->matrix[i][j]) || (i != j && !(testGraph->matrix[i][j]))))

                {
                    flag = false;
                    break;
                }
            }
        QVERIFY(flag);
    }

    void checkConstructor()
    {
        QVector<bool> testArrayFalse(testGraph->graphSize, false);
        QVector<bool> testArrayTrue(testGraph->graphSize, true);
        QVERIFY(testGraph->aliveArray == testArrayTrue && testGraph->robots == testArrayFalse && testGraph->visitingArray == testArrayFalse);
    }

    void checkSituationAllDestroyingAllDisconnected()
    {
        for (int i = 0; i < testGraph->graphSize; i++)
        {
            testGraph->addRobot(i);
        }
        QVERIFY(!(testGraph->canRobotsBeDestroyed()));
    }

    void checkSituationAllDestroyingAllConnected()
    {
        for (int i = 0; i < testGraph->graphSize; i++)
        {
            testGraph->addRobot(i);
        }
        for (int i = 0; i < testGraph->graphSize - 1; i++)
        {
            testGraph->connectNodes(i, i + 1);
        }
        QVERIFY(testGraph->canRobotsBeDestroyed());
    }

    void checkSituationDividedGraph()
    {
        for (int i = 0; i < testGraph->graphSize; i++)
        {
            testGraph->addRobot(i);
        }
        for (int i = 0; i < testGraph->graphSize - 1; i++)
        {
            testGraph->connectNodes(i, i + 1);
        }
        testGraph->connectNodes(5, 6);
        QVERIFY(testGraph->canRobotsBeDestroyed());
    }


    /**
     * @brief checkSituationPairsCannotBeDestroyed проверяет ситуацию, когда в графе находится пара соединенных только друг с другом графа с роботами
     */
    void checkSituationPairsCannotBeDestroyed()
    {
        for (int i = 0; i < testGraph->graphSize; i++)
        {
            testGraph->addRobot(i);
        }
        for (int i = 0; i < testGraph->graphSize - 1; i++)
        {
            testGraph->connectNodes(i, i + 1);
        }
        testGraph->connectNodes(7, 8);
        QVERIFY(!(testGraph->canRobotsBeDestroyed()));
    }

    void checkSituationSingleRobot()
    {
        testGraph->addRobot(2);
        QVERIFY(!(testGraph->canRobotsBeDestroyed()));
    }

    /**
     * @brief checkSituationLittleGraph проверяет ситуацию (R)-(R)-(R)
     */
    void checkSituationLittleGraph()
    {
        for (int i = 0; i < testLittleGraph->graphSize; i++)
        {
            testGraph->addRobot(i);
        }
        QVERIFY(!(testGraph->canRobotsBeDestroyed()));
    }

    void cleanup()
    {
        delete testGraph;
        delete testLittleGraph;
    }
};
