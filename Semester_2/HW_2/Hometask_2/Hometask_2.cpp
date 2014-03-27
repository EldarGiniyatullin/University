#include <iostream>
#include "arraysoft.h"
#include "consoledisplayer.h"
#include "filedisplayer.h"
#include "arrayspiraldisplayer.h"

using namespace std;

int main()
{
    int **array = randomArray(5);
    arrayPrinter(array, 5);
    ArraySpiralDisplayer *a = new ConsoleDisplayer;
    ArraySpiralDisplayer *b = new FileDisplayer("text.txt");
    a->displaySpiral(array, 5);
    b->displaySpiral(array, 5);
    ArraySpiralDisplayer *c = new FileDisplayer();
    c->displaySpiral(array, 5);
    delete a;
    delete b;
    delete c;
    deleteArray(array, 5);
}


