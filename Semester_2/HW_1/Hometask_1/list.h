#pragma once

class List
{
public:
    List() : numberOfElements(0)
    {

    }
    virtual ~List()
    {

    }
    virtual void addElement(int number) = 0;
    virtual void deleteElement(int number) = 0;
    virtual void printList() = 0;
    int numberOfElements;
};
