#include <iostream>
#include "vector.h"
#include "testvector.h"

using namespace std;

int main()
{
    TestVector testVector;
    QTest::qExec(&testVector);

    Vector<int, 4> a(5, 4, 3, 2);
    cout << a.getDimensionValue(0) << a.getDimensionValue(1) << a.getDimensionValue(2) << a.getDimensionValue(3) << "\n";
    Vector<int, 4> b(1);
    cout << b.getDimensionValue(0) << b.getDimensionValue(1) << b.getDimensionValue(2) << b.getDimensionValue(3) << "\n";
    Vector<int, 4> c = a + b;
    cout << c.getDimensionValue(0) << c.getDimensionValue(1) << c.getDimensionValue(2) << c.getDimensionValue(3) << "\n";
    int d = a * b;
    cout << d << "\n";
}

