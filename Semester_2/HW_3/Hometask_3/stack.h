#pragma once

/**
 * @brief The Stack class is the abstract class
 * @detailed The Stack class includes standart functional using in stack and declared as virtual
 */
class Stack
{
public:
    virtual ~Stack()
    {
    }
    /**
     * @brief push puts a new double value in stack
     * @param numberToPush is double value to put in stack
     */
    virtual void push(double numberToPush) = 0;
    /**
     * @brief push puts a new symbol in stack
     * @param symbolToPush is symbol to put in stack
     */
    virtual void push(char symbolToPush) = 0;
    /**
     * @brief pop pulls out the last added element
     */
    virtual void pop() = 0;
    /**
     * @brief printStack prints the stack data
     */
    virtual void printStack() = 0;
};
