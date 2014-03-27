#pragma once

class Stack
{
public:
    virtual ~Stack()
    {

    }
//    virtual void push(int numberToPush) = 0;
    virtual void push(double numberToPush) = 0;         //how to use template <typename UserType> here
    virtual void push(char symbolToPush) = 0;           // and is it necessary?
    virtual void pop() = 0;
    virtual void printStack() = 0;
};
