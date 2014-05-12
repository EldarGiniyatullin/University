#include <iostream>
#include "arraysoft.h"
#include "arraysorter.h"
#include "arrayheapsorter.h"
#include "testrowsorter.h"

using namespace std;

/**
 * @brief main sorts a random two-dimensional square array by elements of first row and prints it to console
 */
int main()
{
    TestRowSorter testRowSorter;
    QTest::qExec(&testRowSorter);

    int **array = randomArray(7);
    arrayPrinter(array, 7);
    cout << "\n";
    ArraySorter<int> *a = new ArrayHeapSorter<int>;
    a->sortArray(array, 7);
    arrayPrinter(array, 7);
    deleteArray(array, 7);
    delete a;
}
