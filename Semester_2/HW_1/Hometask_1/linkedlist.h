#pragma once

#include "list.h"

/**
 * @brief The LinkedList class is implementation of list based on pointers
 * @detailed The LinkedList class contains only int-values
 */
class LinkedList : public List
{
public:
    LinkedList() : List(), head(nullptr)
    {
    }
    ~LinkedList();
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
    };
    /**
     * @brief head is pointer to list's first element
     */
    Element *head;
    /**
     * @brief createElement is service method that creates an empty exemplar of list's element
     * @detailed it needed for the addElement() function
     * @return an empty exemplar of list's element
     */
    Element *createElement();
};
