#pragma once

#include <iostream>
#include <stdlib.h>
#include <time.h>

using std::cout;

int **randomArray(unsigned int arraySize)
{
    srand(time(NULL));
    int **array = new int*[arraySize];
    for (unsigned int i = 0; i < arraySize; i++)
    {
        array[i] = new int[arraySize];
    }
    for (unsigned int i = 0; i < arraySize; i++)
    {
        for (unsigned int j = 0; j < arraySize; j++)
            array[i][j] = rand() % 25;
    }
    return array;
}

void arrayPrinter(int **array, unsigned int arraySize)
{
    for (unsigned int i = 0; i < arraySize; i++)
    {
        for (unsigned int j = 0; j < arraySize; j++)
        {
            cout << array[i][j] << " ";
        }
        cout << "\n";
    }
}
void deleteArray (int **array, unsigned int arraySize)
{
    for (unsigned int i = 0; i < arraySize; i++)
    {
        delete[] array[i];
    }
    delete[] array;
}
