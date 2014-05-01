#pragma once

#include <iostream>
#include "arrayspiraldisplayer.h"

/**
 * @brief The ConsoleDisplayer class is heir class of ArraySpiralDisplayer
 * @detailed this class prints a result of ArraySpiralDisplayer's work to console
 */
class ConsoleDisplayer : public ArraySpiralDisplayer
{
public:
    void printElement(int number);
};
