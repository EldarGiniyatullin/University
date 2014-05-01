#pragma once

template <typename T>

/**
 * @brief The ArraySorter class is template interface class for sorting two-dimensional square arrays
 */
class ArraySorter
{
public:
    virtual void sortArray(T **array, unsigned int arraySize) = 0;
};
