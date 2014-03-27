#include "filedisplayer.h"

#include <fstream>

using std::fstream;
using std::ios_base;

//void FileDisplayer::displaySpiral(int **array, unsigned int arraySize)
//{
//    fstream fout("result.txt", ios_base::out);
//    int horizontal = 1;
//    int vertical = -1;
//    int reverse = -1;
//    int printLen = 1;
//    int currRow = arraySize / 2;
//    int currColumn = arraySize / 2;
//    fout << array[currRow][currColumn] << " ";
//    currColumn++;
//    while (printLen != arraySize)
//    {
//        int printed = 0;
//        for(int i = currColumn; printed < printLen; i += horizontal)
//        {
//            printed++;
//            fout << array[currRow][i] << " ";
//            currColumn += horizontal;
//        }
//        currColumn -= horizontal;
//        horizontal *= reverse;
//        currRow += vertical;
//        printed = 0;
//        for (int i = currRow; printed < printLen; i += vertical)
//        {
//            printed++;
//            fout << array[i][currColumn] << " ";
//            currRow += vertical;
//        }
//        currRow -= vertical;
//        vertical *= reverse;
//        currColumn += horizontal;
//        printLen++;
//    }
//    if (arraySize != 1)
//    {
//        for (int i = 1; i < arraySize; i++)
//        {
//            fout << array[arraySize - 1][i] << " ";
//        }
//    }
//    fout.close();
//}

void FileDisplayer::printElement(int number)
{
    fout << number << " ";
}
