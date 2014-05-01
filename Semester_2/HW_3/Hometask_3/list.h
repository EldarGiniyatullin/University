#pragma once

/**
 * @brief The List class - the interface class
 * @detailed The List class includes standart functional using in list and declared as virtual
 */
class List
{
public:
    List() : numberOfElements(0)
    {
    }
    virtual ~List()
    {
    }
    /**
     * @brief addElement adds a number to the list
     * @param number is number to add
     */
    virtual void addElement(double number) = 0;
    /**
     * @brief deleteElement deletes a number from list
     * @param number is number to delete
     */
    virtual void deleteElement(int number) = 0;
    virtual void printList() = 0;
    /**
     * @brief numberOfElements contains current number of elements contained in the list
     */
    int numberOfElements;
};
