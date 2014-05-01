#pragma once

#include "stack.h"

/**
 * @brief The LinkedList class is implementation of stack based on pointers
 * @detailed The LinkedList class contains only int-values
 */
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
    /**
     * @brief isEmpty is method that checks, is list empty
     * @return true, if current list is empty, else - false
     */
    bool isEmpty();
protected:
    /**
     * @brief The Element struct contains a stack element
     */
    struct Element
    {
        /**
         * @brief isSymbol is true, if current element of stack stores a char-variable, false - if double-variable
         */
        bool isSymbol;
        /**
         * @brief The Data union contains the element's value
         */
        union
        {
            double number;
            char symbol;
        }Data;
        /**
         * @brief next is pointer to next element
         */
        Element *next;
    };
public:
    /**
     * @brief head is pointer to list's first element
     */
    Element *head;
protected:
    /**
     * @brief popElement is service method
     * @return the stack's element (not only its value)
     */
    Element *popElement();
private:
    /**
     * @brief createElement is service method that creates an empty exemplar of stack's element
     * @detailed it needed for the push() functions
     * @return an empty exemplar of stack's element
     */
    Element *createElement();
};
