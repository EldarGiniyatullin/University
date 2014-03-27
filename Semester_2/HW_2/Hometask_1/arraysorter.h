#pragma once

template <typename T>

class ArraySorter
{
public:
    virtual void sortArray(T *array, unsigned int arraySize) = 0;
};
