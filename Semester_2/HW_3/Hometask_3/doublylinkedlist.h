#pragma once

#include "list.h"

/**
 * @brief The DoublyLinkedList class is implementation of list based on doubly linked list
 * @detailed The DoublyLinkedList class contains only int-values
 */
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
    /**
     * @brief printList prints list content to console
     */
    void printList();
protected:
    struct Element
    {
        /**
         * @brief isSymbol is true, if current element of list stores a char-variable, false - if double-variable
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
        /**
         * @brief previous is pointer to previous element
         */
        Element *previous;
    };
    /**
     * @brief ending is pointer to list's last element
     */
    Element *ending;
public:
    /**
     * @brief head is pointer to list's first element
     */
    Element *head;
private:
    /**
     * @brief createElement is service method that creates an empty exemplar of list's element
     * @detailed it needed for the addElement() function
     * @return an empty exemplar of list's element
     */
    Element *createElement();
};
