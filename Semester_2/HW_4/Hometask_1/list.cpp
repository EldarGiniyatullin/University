#include "list.h"
#include <iostream>

using namespace std;

void List::printList()
{
    cout << "\n";
    if (first == nullptr)
    {
        cout << "No elements in the list";
    }
    else
    {
        ListElement *curr = first;
        while (curr)
        {
            cout << curr->value << "\n";
            curr = curr->next;
        }
    }
}

List::List()
{
    first = nullptr;
}

void List::addValueList(int value)
{
    ListElement *newEl = new ListElement;
    newEl->value = value;
    newEl->next = first;
    first = newEl;
}

List::~List()
{
    ListElement *tmp = first;
    while (first)
    {
        first = first->next;
        delete tmp;
        tmp = first;
    }
}
