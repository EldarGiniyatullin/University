#include <iostream>
#include "linkedstack.h"

using std::cout;

LinkedStack::~LinkedStack()
{
    Element *tmp = head;
    while (head)
    {
        head = head->next;
        delete tmp;
        tmp = head;
    }
}

LinkedStack::Element *LinkedStack::createElement()
{
    Element *newEl = new Element;
    newEl->next = head;
    head = newEl;
    return newEl;
}

void LinkedStack::push(double numberToPush)
{
    Element *newEl = createElement();
    newEl->Data.number = numberToPush;
    newEl->isSymbol = false;
//    cout << "\n" << numberToPush << " added";
}

void LinkedStack::push(char symbolToPush)
{
    Element *newEl = createElement();
    newEl->Data.symbol = symbolToPush;
    newEl->isSymbol = true;
//    cout << "\n" << symbolToPush << " added";
}

LinkedStack::Element *LinkedStack::popElement()
{
    if (head)
    {
        Element *elementToReturn = head;
        head = head->next;
//        cout << "\n" << (elementToReturn->isSymbol ? elementToReturn->Data.symbol : elementToReturn->Data.number) << " has been taken";
        return elementToReturn;
    }
//    else
//        cout << "The stack is empty";
}

void LinkedStack::pop()
{
    if (head)
    {
        Element *tmp = head;
        head = head->next;
//        cout << "\n" << (tmp->isSymbol ? tmp->Data.symbol : tmp->Data.number) << " has been deleted";
        delete tmp;
    }
//    else
//        cout << "The stack is empty";
}

bool LinkedStack::isEmpty()
{
    return (!head);
}

void LinkedStack::printStack()
{
    cout << "\n";
    Element *tmp = head;
    if (!tmp)
        cout << "There is nothing to print";
    else
    {
        cout << "The stack content:";
        while (tmp)
        {
            if (tmp->isSymbol)
                cout << " " << tmp->Data.symbol;
            else
                cout << " " << tmp->Data.number;
            tmp = tmp->next;
        }
    }
}
