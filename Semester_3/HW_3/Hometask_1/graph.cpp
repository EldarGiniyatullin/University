#include "graph.h"
#include <iostream>

using std::cout;
using std::cin;

Graph::Graph()
{
    cout << "Enter size if graph\n";
    cin >> graphSize;
    initializeMatrix();
    unsigned int node1, node2;
    int someElse;
    while (true)
    {
        cout << "\nConnect nodes (enter two numbers) (re-entry deletes nodes)\n";
        cin >> node1 >> node2;
        connectNodes(node1, node2);
        cout << "\nConnect/disconnect some else? (1/0) ";
        cin >> someElse;
        if (!someElse)
            break;
    }
    while(true)
    {
        cout << "\nAdd robot to position (enter one number) (re-entry deletes robot)\n";
        cin >> someElse;
        addRobot(someElse);
        cout << "\nAdd/delete any robot else? (1/0) ";
        cin >> someElse;
        if (!someElse)
            return;
    }
}

Graph::Graph(unsigned int size) : graphSize(size)
{
    initializeMatrix();
}

Graph::~Graph()
{

}

void Graph::connectNodes(unsigned int node1, unsigned int node2)
{
    if (node1 != node2 &&  node1 < graphSize  && node2 < graphSize)
    {
        matrix[node1][node2] = !matrix[node1][node2];
        matrix[node2][node1] = !matrix[node2][node1];
    }
    return;
}

void Graph::addRobot(unsigned int position)
{
    if (position < graphSize)
        robots[position] = !robots[position];
}

bool Graph::canRobotsBeDestroyed()
{
    for (unsigned int i = 0; i < graphSize; i++)
    {
        if (robots[i] && aliveArray[i])
            dfs(i);
        visitingArray = QVector<bool>(graphSize, false);
    }
    bool canThey = true;
    for (unsigned int i = 0; i < graphSize; i++)
    {
        if (robots[i] && aliveArray[i])
        {
            canThey = false;
            break;
        }
    }
    visitingArray = QVector<bool>(graphSize, false);
    aliveArray = QVector<bool>(graphSize, true);
    return canThey;
}

void Graph::dfs(unsigned int node)
{
    visitingArray[node] = true;
    for (unsigned int i = node; i < graphSize; i++)
    {
        if (matrix[node][i] && !visitingArray[i])
        {
            for (unsigned int j = i + 1; j < graphSize; j++)
            {
                if (matrix[i][j])
                {
                    if (robots[j])
                    {
                        aliveArray[node] = false;
                        aliveArray[j] = false;
                    }
                    dfs(j);
                }
            }
        }
    }
    return;
}

void Graph::initializeMatrix()
{
    matrix = QVector<QVector<bool> > (graphSize);
    for (unsigned int i = 0; i < graphSize; i++)
    {
        matrix[i] = QVector<bool>(graphSize, false);
    }
    for (unsigned int i = 0; i < graphSize; i++)
    {
        matrix[i][i] = true;
    }
    robots = QVector<bool>(graphSize, false);
    visitingArray = QVector<bool>(graphSize, false);
    aliveArray = QVector<bool>(graphSize, true);
}
