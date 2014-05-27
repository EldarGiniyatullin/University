#include <iostream>
#include "testlist.h"
#include "testhashtable.h"
using namespace std;

int main()
{
    TestList testList;
    TestHashTable testHashTable;
    QTest::qExec(&testList);
    QTest::qExec(&testHashTable);

    return 0;
}

