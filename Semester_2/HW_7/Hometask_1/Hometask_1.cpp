#include <iostream>
#include "testbag.h"

using namespace std;

int main()
{
    TestBag testBag;
    QTest::qExec(&testBag);

    system("pause");
}

