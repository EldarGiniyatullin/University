#include <iostream>
#include <typeinfo>
#include "linkedlist.h"

using std::cout;

LinkedList::~LinkedList()
{
    Element *tmp = head;
    while (head)
    {
        head = head->next;
        delete tmp;
        tmp = head;
    }
    numberOfElements = 0;
}

LinkedList::Element *LinkedList::createElement()
{
    Element *newEl = new Element;
    newEl->next = head;
    head = newEl;
    numberOfElements++;
    return newEl;
}

void LinkedList::addElement(int number)
{
    Element *newEl = createElement();
    newEl->number = number;
}

void LinkedList::deleteElement(int number)
{
    if (numberOfElements < number)
        cout << "\nNumber of elements in list is less than the number";
    else
    {
        Element **tmp = &head;
        for (int i = 1; i < number; i++)
            tmp = &((*tmp)->next);
        Element *elementToDelete = *tmp;
        *tmp = (*tmp)->next;
        delete elementToDelete;
        numberOfElements--;
    }
}

void LinkedList::printList()
{
    cout << "\n";
    Element *tmp = head;
    while (tmp)
    {
        cout << tmp->number;
        tmp = tmp->next;
    }
}
