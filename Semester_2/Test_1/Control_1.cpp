#include <iostream>
#include "priorityqueue.h"

using namespace std;

int main()
{
    PriorityQueue<int> *queue = new PriorityQueue<int>;
    queue->printQueue();
    queue->enqueue(5, 3);
    queue->enqueue(2, 1);
    queue->enqueue(7, 6);
    queue->printQueue();
    cout << "\n";
    /**
      * @brief the fourth iteration should throw the exception,
      * but i didn't write it
    for (int i = 0; i < 4; i++)
    {
        cout << queue->dequeue() << ", ";
    }
    queue->printQueue();
    delete queue;
}

