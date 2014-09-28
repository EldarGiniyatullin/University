#include <iostream>
#include "operatingsystem.h"
#include "personalcomputer.h"
#include "localnet.h"

using namespace std;

using namespace OS;

OperatingSystem listOfOS[] = {windows7, windows8, linux, mac};

int main()
{
    LocalNet net(30, listOfOS, 4);
    net.work();
    system("pause");
    return 0;
}
