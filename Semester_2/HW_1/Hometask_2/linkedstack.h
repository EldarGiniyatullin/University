#pragma once

#include "stack.h"

class LinkedStack : public Stack
{
public:
    LinkedStack() : head(nullptr)
    {

    }
    ~LinkedStack();
    void push(double numberToPush);
    void push(char symbolToPush);
    void printStack();
    void pop();
    bool isEmpty();
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
    };
public:
    Element *head;
protected:
    Element *popElement();
private:
    Element *createElement();
};
