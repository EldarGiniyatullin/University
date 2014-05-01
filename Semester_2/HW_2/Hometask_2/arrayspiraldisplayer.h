#pragma once

/**
 * @brief The ArraySpiralDisplayer class prints two-dimensional array from the central element and does it spirally
 */
class ArraySpiralDisplayer
{
public:
    /**
     * @brief displaySpiral includes an algorithm of spiral traversing the array
     * @brief it does not print the elements, only traversing
     * @param arraySize is size of array dimension (should be odd)
     */
    void displaySpiral(int **array, unsigned int arraySize);
    /**
     * @brief printElement prints a number by different ways
     * @param number is number to print
     */
    virtual void printElement(int number) = 0;
    ArraySpiralDisplayer()
    {
    }
    virtual ~ArraySpiralDisplayer()
    {
    }
};
