#pragma once

#include "stack.h"

/**
@brief The ArrayStack class - this realization of stack is based on array
*/
class ArrayStack : public Stack
{
public:
/**
@brief this constructor creates stack accomodating 100 elements
*/
    ArrayStack();
/**
@brief this constructor creates stack with user-added size
@param length is the size of stack that user wants to create
*/
    ArrayStack(unsigned int length);
    ~ArrayStack();
    void push(double numberToPush);
    void push(char symbolToPush);
    void pop();
    void printStack();
    bool isStackFull();

protected:
    struct Element
    {
       /**
        @param isSymbol equals true if current element added as a symbol, false in other way
        */
        bool isSymbol;
        union
        {
            double number;
            char symbol;
        }Data;
    };
    Element *array;
    unsigned int lengthOfStack;
    /**
     @detailed current position of element that will store the new data + 1
     currentPositionOfBottom == 0 means that the stack is empty
     */
    unsigned int currentPositionOfBottom;
};
