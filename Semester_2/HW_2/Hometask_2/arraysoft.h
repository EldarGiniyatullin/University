/**
 *
 * @brief this header file includes the functional for working with arrays
 *
 */

#pragma once

#include <iostream>
#include <stdlib.h>
#include <time.h>

using std::cout;

/**
 * @brief randomArray is function that creates a two-dimensional square array with random natural values from 0 up to 24
 * @param arraySize is size of dimension
 * @return a two-dimensional square array with random natural values from 0 up to 24
 */
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

/**
 * @brief arrayPrinter prints a two-dimensional square array
 * @param array is the array to print
 * @param arraySize is size of array's dimension
 */
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

/**
 * @brief deleteArray deletes a two-dimensional square array
 */
void deleteArray (int **array, unsigned int arraySize)
{
    for (unsigned int i = 0; i < arraySize; i++)
    {
        delete[] array[i];
    }
    delete[] array;
}
