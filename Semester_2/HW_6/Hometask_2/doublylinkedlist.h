#pragma once

#include <iostream>
#include "list.h"

/**
 * @brief The DoublyLinkedList class is implementation of list based on doubly linked list
 * @detailed The DoublyLinkedList class contains only int-values
 */
template <typename T>
class DoublyLinkedList : public List<T>
{
public:
    DoublyLinkedList() : head(nullptr), ending(nullptr) {}
    ~DoublyLinkedList();
    void addElement(T number);
    void deleteElement(T number);
    bool doesListContain(T value);
    /**
     * @brief printList prints list content to console
     */
    void printList();
    /**
     * @brief The Element struct contains a list element
     */
private:
    struct Element
    {
        /**
         * @brief number is the element's value
         */
        T value;
        /**
         * @brief next is pointer to next element
         */
        Element *next;
        /**
         * @brief previous is pointer to previous element
         */
        Element *previous;
    };
protected:
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
private:
    Element *createElement()
    {
        Element *newEl = new Element;
        newEl->next = nullptr;
        newEl->previous = ending;
        if (!ending)
        {
            head = newEl;
            ending = newEl;
        }
        else
        {
            ending->next = newEl;
            ending = newEl;
        }
        List<T>::numberOfElements++;
        return newEl;
    }
};

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    Element *tmp = head;
    while (head)
    {
        head = head->next;
        delete tmp;
        tmp = head;
    }
    List<T>::numberOfElements = 0;
}

template <typename T>
void DoublyLinkedList<T>::addElement(T number)
{
    Element *newEl = createElement();
    newEl->value = number;
}

template <typename T>
void DoublyLinkedList<T>::deleteElement(T number)
{
    Element **tmp = &head;
    while ((*tmp) && (*tmp)->value != number)
        tmp = &((*tmp)->next);
    if (*tmp)
    {
        Element *elementToDelete = *tmp;
        *tmp = (*tmp)->next;
        if (!*tmp)
            ending = ending->previous;
        if (!head)
            ending = nullptr;
        delete elementToDelete;
        List<T>::numberOfElements--;
    }
}

template <typename T>
bool DoublyLinkedList<T>::doesListContain(T value)
{
    Element *tmp = head;
    while (tmp)
    {
        if (tmp->value == value)
            break;
        tmp = tmp->next;
    }
    return (tmp ? true : false);
}

template <typename T>
void DoublyLinkedList<T>::printList()
{
    std::cout << "\n";
    Element *tmp = head;
    while (tmp)
    {
        std::cout << tmp->value;
        tmp = tmp->next;
    }
}

