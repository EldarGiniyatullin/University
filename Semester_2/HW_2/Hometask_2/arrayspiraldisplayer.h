#pragma once

class ArraySpiralDisplayer
{
public:
    void displaySpiral(int **array, unsigned int arraySize);
    virtual void printElement(int number) = 0;
    ArraySpiralDisplayer()
    {
    }
    virtual ~ArraySpiralDisplayer()
    {
    }
};
