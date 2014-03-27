#include <iostream>
#include "arraysoft.h"
#include "arraysorter.h"
#include "arrayheapsorter.h"

using namespace std;

int main()
{
    int **array = randomArray(7);
    arrayPrinter(array, 7);
    cout << "\n";
    ArraySorter<int> *a = new ArrayHeapSorter<int>;
    a->sortArray(array, 7);
    arrayPrinter(array, 7);
    deleteArray(array, 7);
    delete a;
}
