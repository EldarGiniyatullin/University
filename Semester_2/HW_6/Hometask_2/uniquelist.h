#pragma once

#include <iostream>
#include "doublylinkedlist.h"

using std::cout;

template <typename T>
class UniqueList
{
public:
    UniqueList()
    {
        data = new DoublyLinkedList<T>;
        size = 0;
    }

    ~UniqueList()
    {
        delete data;
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

    DoublyLinkedList<T> *data;
};



template <typename T>
void UniqueList<T>::addValue(T value)
{
    if (!doesContain(value))
    {
        data->addElement(value);
        size++;
    }
    else
        throw ValueIsAddedYet();
}

template <typename T>
bool UniqueList<T>::doesContain(T value)
{
    return data->doesListContain(value);
}

template <typename T>
void UniqueList<T>::deleteValue(T value)
{
    if (doesContain(value))
    {
        data->deleteElement(value);
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
