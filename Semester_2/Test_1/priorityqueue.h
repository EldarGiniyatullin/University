#pragma once

#include <iostream>
#include "myerror.h"

using std::cout;

template <typename UserType>

/**
 * @brief The PriorityQueue class is template class realizing priority queue
 */
class PriorityQueue
{
public:
    /**
     * @brief PriorityQueue creates the empty priority queue
     */
    PriorityQueue() : size(0), head(nullptr)
    {
    }
    ~PriorityQueue()
    {
        Element *tmp = head;
        while (head)
        {
            head->next = head;
            delete tmp;
            tmp = head;
        }
    }
    /**
     * @brief enqueue adds a value to priority queue
     * @param priority is key of new value. The more this parameter, the more key
     */
    void enqueue(UserType valueToAdd, unsigned int priority)
    {
        Element **tmp = &head;
        while (*tmp && (*tmp)->key > priority)
        {
            tmp = &((*tmp)->next);
        }
        Element *newEl = new Element;
        newEl->key = priority;
        newEl->value = valueToAdd;
        newEl->next = *tmp;
        *tmp = newEl;
        size++;
    }
    /**
     * @brief dequeue returns the member of queue which has
     * the highest priority and deletes it from queue
     * @return the member's value
     */
    UserType dequeue()
    {
        Element *tmp = head;
        UserType valueToReturn = head->value;
        head = head->next;
        delete tmp;
        size--;
        return valueToReturn;
     }
    /**
     * @brief printQueue prints queue data to console
     */
    void printQueue()
    {
        Element *tmp = head;
        cout << "Data:\n";
        while (tmp)
        {
            cout << tmp->value << "(" << tmp->key << ")" << ", ";
            tmp = tmp->next;
        }
    }
protected:
    unsigned int size;
    struct Element
    {
        UserType value;
        unsigned int key;
        Element *next;
    };
    /**
     * @brief head is pointer to first element of queue
     */
    Element *head;
};
