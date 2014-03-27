#pragma once

#include <iostream>
#include "arrayspiraldisplayer.h"

class ConsoleDisplayer : public ArraySpiralDisplayer
{
public:
//    void displaySpiral(int **array, unsigned int arraySize);
    void printElement(int number);
};
