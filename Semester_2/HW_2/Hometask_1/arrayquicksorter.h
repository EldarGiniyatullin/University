#pragma once

#include "arraysorter.h"

template <typename T>

class ArrayQuickSorter : public ArraySorter<T>
{
public:
    void swap(T &first, T &second)  //xor method does not work with double-arguments
    {
        if (first != second)
        {
            T temp = first;
            first = second;
            second = temp;
//            first = first ^ second;
//            second = first ^ second;
//            first = first ^ second;
        }
    }
    void quickSort(T *array, unsigned int first, unsigned int last)
    {
        T x = array[first + (last - first) / 2];
        int i = first;
        int j = last;
        while(i <= j)
        {
            while(array[i] < x)
            {
                i++;
            }
            while(array[j] > x)
            {
                j--;
            }
            if(i <= j)
            {
                swap(array[i], array[j]);
                i++;
                j--;
            }
        }
        if (first < j)
            quickSort(array, first, j);
        if (i < last)
            quickSort(array, i, last);
    }
    void sortArray(T *array, unsigned int arraySize)
    {
        quickSort(array, 0, arraySize - 1);
    }
};
