#include <iostream>
#include "sharedpointer.h"
#include "testsharedpointer.h"

using namespace std;

int main()
{
    TestSharedPointer testSharedPointer;
    QTest::qExec(&testSharedPointer);

    system("pause");
}

