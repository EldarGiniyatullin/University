#pragma once

#include <fstream>
#include <iostream>
#include "arrayspiraldisplayer.h"

using std::fstream;
using std::ios_base;
using std::cout;

class FileDisplayer : public ArraySpiralDisplayer
{
private:
    const char* fileName = "result.txt";
    fstream fout;
public:
    FileDisplayer()
    {
        fout.open(fileName, ios_base::out | ios_base::trunc);
    }
    FileDisplayer(const char* userFile)
    {
        fout.open(userFile, ios_base::out | ios_base::trunc);
    }
    ~FileDisplayer()
    {
        FileDisplayer::fout.close();
    }
//    void displaySpiral(int **array, unsigned int arraySize);
    void printElement(int number);
};
