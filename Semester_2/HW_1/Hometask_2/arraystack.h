#pragma once

#include "stack.h"

class ArrayStack : public Stack
{
public:
    ArrayStack();
    ArrayStack(unsigned int length);
    ~ArrayStack();
    void push(double numberToPush);
    void push(char symbolToPush);
    void pop();
    void printStack();
protected:
    struct Element
    {
        bool isSymbol;
        union
        {
            double number;
            char symbol;
        }Data;
    };
    Element *array;
    unsigned int lengthOfStack;
    unsigned int currentPositionOfBottom; // current position of element that will store the new data + 1
                                          // currentPositionOfBottom == 0 means that the stack is empty
private:
    bool isStackFull();
};
