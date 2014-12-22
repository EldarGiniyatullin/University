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
    for (int i = 0; i < net.getNetSize() - 1; i++)
    {
        net.connectPCs(i, i + 1);
        if (i % 2 == 0)
            net.infect(i);
    }
    while (true)
    {
        int tmp;
        cout << "\n";
        net.step();
        net.printStatus();
        cout << "Again? (1/0) ";
        cin >> tmp;
        if (!tmp)
            break;
    }
    return 0;
}
