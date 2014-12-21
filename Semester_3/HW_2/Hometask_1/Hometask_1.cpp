#include <iostream>
#include "operatingsystem.h"
#include "personalcomputer.h"
#include "localnet.h"
#include "testlocalnet.h"

using namespace std;

int main()
{
    TestLocalNet testNet;
    QTest::qExec(&testNet);
    LocalNet net(30);
    return 0;
}
