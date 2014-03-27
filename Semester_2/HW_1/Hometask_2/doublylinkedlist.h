#pragma once

#include "list.h"

class DoublyLinkedList : public List
{
public:
    DoublyLinkedList() : List(), head(nullptr), ending(nullptr)
    {

    }
    ~DoublyLinkedList();
    void addElement(double number);
    void addElement(char symbol);
    void deleteElement(int number);
    void printList();
protected:
    struct Element
    {
        bool isSymbol;
        union
        {
            double number;
            char symbol;
        }Data;
        Element *next;
        Element *previous;
    };
    Element *ending;
public:
    Element *head;
private:
    Element *createElement();
};
