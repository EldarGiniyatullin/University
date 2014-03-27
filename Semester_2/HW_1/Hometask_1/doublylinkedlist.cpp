#include <iostream>
#include "doublylinkedlist.h"

using std::cout;

DoublyLinkedList::~DoublyLinkedList()
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

DoublyLinkedList::Element *DoublyLinkedList::createElement()
{
    Element *newEl = new Element;
    newEl->next = NULL;
    newEl->previous = ending;
    if (!ending)
    {
        head = newEl;
        ending = newEl;
    }
    else
    {
        ending->next = newEl;
        ending = newEl;
    }
    numberOfElements++;
    return newEl;
}

void DoublyLinkedList::addElement(int number)
{
    Element *newEl = createElement();
    newEl->number = number;
}

void DoublyLinkedList::deleteElement(int number)
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
        if (!*tmp)
            ending = ending->previous;
        if (!head)
            ending = nullptr;
        delete elementToDelete;
        numberOfElements--;
    }
}

void DoublyLinkedList::printList()
{
    cout << "\n";
    Element *tmp = head;
    while (tmp)
    {
        cout << tmp->number;
        tmp = tmp->next;
    }
}
