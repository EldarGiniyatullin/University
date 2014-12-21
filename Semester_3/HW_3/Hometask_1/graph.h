#pragma once

#include <QVector>

/**
 * @brief The Graph class реализует неориентированный граф с находящимися на нем роботами
 */
class Graph
{
public:
    Graph();
    Graph(unsigned int graphSize);
    ~Graph();
    friend class TestGraph;
    /**
     * @brief connectNodes соединяет графы прямым узлом, если они таковым не соединены, иначе - разрывает прямой узел
     */
    void connectNodes(unsigned int node1, unsigned int node2);
    /**
     * @brief addRobot добавляет робота на граф с номером position
     */
    void addRobot(unsigned int position);
    /**
     * @brief canRobotsBeDestroyed
     * @return true, если такое возможно, в противном случае - false
     */
    bool canRobotsBeDestroyed();
private:
    /**
     * @brief dfs модифицированный вариант обхода в глубину с "перескоками" через один граф
     */
    void dfs(unsigned int node);
    /**
     * @brief initializeMatrix вспомогательная функция конструктора, строит стандартную матрицу смежности и вспомогательные массиывы
     */
    void initializeMatrix();
    unsigned int graphSize;
    /**
     * @brief matrix матрица смежности
     */
    QVector<QVector<bool> > matrix;
    QVector<bool> robots;
    /**
     * @brief visitingArray вспомогательный массив для DFS
     */
    QVector<bool> visitingArray;
    /**
     * @brief aliveArray вспомогательный массив "живых/уничтоженных" роботов
     */
    QVector<bool> aliveArray;
};
