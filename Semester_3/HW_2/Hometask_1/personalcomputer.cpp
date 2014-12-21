#include "personalcomputer.h"




void PersonalComputer::changeOS(OperatingSystem OS)
{
    currentOS = OS;
    isPCInfected = false;
}



QString PersonalComputer::getCurrentOSName()
{
    return currentOS.getOSName();
}

void PersonalComputer::infectPC()
{
    this->isPCInfected = true;
}
