#include "personalcomputer.h"




void PersonalComputer::changeOS(OperatingSystem OS)
{
    currentOS = OS;
    isPCInfected = false;
}

void PersonalComputer::connectWithPC(PersonalComputer otherPC)
{
    if (otherPC.isInfected())
        this->tryToInfectPC();
    else if ((!otherPC.isInfected()) && this->isInfected())
        otherPC.tryToInfectPC();
}

QString PersonalComputer::getCurrentOSName()
{
    return currentOS.getOSName();
}

void PersonalComputer::infectPC()
{
    this->isPCInfected = true;
}

void PersonalComputer::tryToInfectPC()
{
    srand(time(0));
    this->isPCInfected = (((rand() * 71) % 100) < this->currentOS.getOSChanceToCatchVirus());
}
