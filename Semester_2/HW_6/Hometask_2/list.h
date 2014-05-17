#pragma once

/**
 * @brief The List class is abstract class
 */

template <typename T>
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
    virtual void addElement(T number) = 0;
    /**
     * @brief deleteElement deletes a number from list
     * @param number is number to delete
     */
    virtual void deleteElement(T number) = 0;
    virtual void printList() = 0;
    /**
     * @brief numberOfElements contains current number of elements contained in the list
     */
    unsigned int numberOfElements;
};
