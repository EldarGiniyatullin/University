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
    void addElement(int number);
    void deleteElement(int number);
    /**
     * @brief printList prints list content to console
     */
    void printList();
private:
    /**
     * @brief The Element struct contains a list element
     */
    struct Element
    {
        /**
         * @brief number is the element's value
         */
        int number;
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
     * @brief head is pointer to list's first element
     */
    Element *head;
    /**
     * @brief ending is pointer to list's last element
     */
    Element *ending;
    /**
     * @brief createElement is service method that creates an empty exemplar of list's element
     * @detailed it needed for the addElement() function
     * @return an empty exemplar of list's element
     */
    Element *createElement();
};
