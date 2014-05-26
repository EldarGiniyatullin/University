#include <iostream>
#include "vector.h"
#include "testvector.h"

using namespace std;

int main()
{
    TestVector testVector;
    QTest::qExec(&testVector);

    int array[] = {9, 8, 7, 6};
    Vector<int, 4> a(array);
    for (int i = 0; i < 4; i++)
        cout << a.getDimensionValue(i) << " ";
    cout << "\n";
    Vector<int, 4> b(1);
    for (int i = 0; i < 4; i++)
        cout << a.getDimensionValue(i);
    cout << "\n";
    Vector<int, 4> c = a + b;
    for (int i = 0; i < 4; i++)
        cout << a.getDimensionValue(i);
    cout << "\n";
    int d = a * b;
    cout << d << "\n";
}

