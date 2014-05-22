#pragma once

#include <iostream>
#include "doublylinkedlist.h"

using std::cout;

template <typename T>
class UniqueList : public DoublyLinkedList<T>
{
public:
    UniqueList()
    {
        DoublyLinkedList<T>();
        size = 0;
    }

    ~UniqueList()
    {
    }

    void addValue(T value);

    /**
     * @return true if the list contains the value; otherwise returns false.
     */
    bool doesContain(T value);

    void deleteValue(T value);

    /**
     * @return list size
     */
    unsigned int getSize();

    /**
     * @brief The NoValueInList class is exception class
     */
    class NoValueInList
    {
    public:
        NoValueInList()
        {
            cout << "\nNoValueInList exception is thrown";
        }
    };
    /**
     * @brief The ValueIsAddedYet class is exception class
     */
    class ValueIsAddedYet
    {
    public:
        ValueIsAddedYet()
        {
            cout << "\nValueIsAddedYet exception is thrown";
        }
    };

private:
    unsigned int size;
};



template <typename T>
void UniqueList<T>::addValue(T value)
{
    if (!doesContain(value))
    {
        this->addElement(value);
        size++;
    }
    else
        throw ValueIsAddedYet();
}

template <typename T>
bool UniqueList<T>::doesContain(T value)
{
    return this->doesListContain(value);
}

template <typename T>
void UniqueList<T>::deleteValue(T value)
{
    if (this->doesListContain(value))
    {
        this->deleteElement(value);
        size--;
    }
    else
        throw NoValueInList();
}

template <typename T>
unsigned int UniqueList<T>::getSize()
{
    return size;
}
