#include <iostream>
#include "operatingsystem.h"
#include "personalcomputer.h"
#include "localnet.h"
#include "testlocalnet.h"

using namespace std;
using namespace OS;

int main()
{
    TestLocalNet testNet;
    QTest::qExec(&testNet);
    LocalNet net(30);
    net.work();
    return 0;
}
