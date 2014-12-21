#include <iostream>
#include "graph.h"
#include "testgraph.h"

using namespace std;

int main()
{
    TestGraph testGraph;
    QTest::qExec(&testGraph);
    Graph robotsGraph = Graph();
    cout << "\nRobots " << (robotsGraph.canRobotsBeDestroyed() ? "can " : "cannot ") << "be destroyed";
}

