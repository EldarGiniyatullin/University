#pragma once

#include <fstream>
#include <iostream>
#include "arrayspiraldisplayer.h"

using std::fstream;
using std::ios_base;
using std::cout;
/**
 * @brief The ConsoleDisplayer class is heir class of ArraySpiralDisplayer
 * @detailed this class prints a result of ArraySpiralDisplayer's work to console
 */
class FileDisplayer : public ArraySpiralDisplayer
{
private:
    /**
     * @param fileName contains the default name of output file
     */
    const char* fileName = "result.txt";
    /**
     * @param fout is an output file
     */
    fstream fout;
public:
    /**
     * @brief this constructor uses the default file (look fileName)
     */
    FileDisplayer()
    {
        fout.open(fileName, ios_base::out | ios_base::trunc);
    }
    /**
     * @brief this constructor uses the other file
     * @param userFile sets the user's name of output file
     */
    FileDisplayer(const char* userFile)
    {
        fout.open(userFile, ios_base::out | ios_base::trunc);
    }
    ~FileDisplayer()
    {
        FileDisplayer::fout.close();
    }
    /**
     * @brief printElement prints a number to output file
     * @param number is the number to print
     */
    void printElement(int number);
};
