#include "arrayspiraldisplayer.h"

/**
 * @brief displaySpiral includes an algorithm of spiral traversing the array
 * @brief it does not print the elements, only traversing
 * @detailed at first "target" is on the central element, then it spirally traverses all the array
 * @param arraySize is size of array dimension (should be odd)
 */
void ArraySpiralDisplayer::displaySpiral(int **array, unsigned int arraySize)
{
    /**
     * @param horizontal sets the direction of "target"'s horizontal motion
     * @detailed "1" - to the right, "-1" - to the left
     */
    int horizontal = 1;
    /**
     * @param vertical sets the direction of "target"'s horizontal motion
     * @detailed "1" - up, "-1" - down
     */
    int vertical = -1;
    int reverse = -1;
    /**
     * @brief printLen sets current length of spiral's part
     */
    int printLen = 1;
    /**
     * @param currRow and @param currColumn are setting the "target"'s coordinates
     */
    int currRow = arraySize / 2;
    int currColumn = arraySize / 2;
    printElement(array[currRow][currColumn]);
    currColumn++;
    while (printLen != arraySize)
    {
        int printed = 0;
        for(int i = currColumn; printed < printLen; i += horizontal)
        {
            printed++;
            printElement(array[currRow][i]);
            currColumn += horizontal;
        }
        currColumn -= horizontal;
        horizontal *= reverse;
        currRow += vertical;
        printed = 0;
        for (int i = currRow; printed < printLen; i += vertical)
        {
            printed++;
            printElement(array[i][currColumn]);
            currRow += vertical;
        }
        currRow -= vertical;
        vertical *= reverse;
        currColumn += horizontal;
        printLen++;
    }
    if (arraySize != 1)
    {
        for (int i = 1; i < arraySize; i++)
        {
            printElement(array[arraySize - 1][i]);
        }
    }
}
