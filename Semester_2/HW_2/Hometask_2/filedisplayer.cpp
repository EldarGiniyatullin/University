#include "filedisplayer.h"

#include <fstream>

using std::fstream;
using std::ios_base;

void FileDisplayer::printElement(int number)
{
    fout << number << " ";
}
