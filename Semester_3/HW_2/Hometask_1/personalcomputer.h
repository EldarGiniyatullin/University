#pragma once

#include <time.h>
#include <cstdlib>
#include "operatingsystem.h"

using namespace OS;

class PersonalComputer
{
public:
    PersonalComputer(OperatingSystem OS) : currentOS(OS), isPCInfected(false) {}
    ~PersonalComputer() {}
//------------------------------------------------------------
    void changeOS(OperatingSystem OS)
    {
        currentOS = OS;
        isPCInfected = false;
    }
    void connectWithPC(PersonalComputer otherPC)
    {
        if (otherPC.isInfected())
            this->tryToInfectPC();
        else if ((!otherPC.isInfected()) && this->isInfected())
            otherPC.tryToInfectPC();
    }
    char* getCurrentOSName()
    {
        return currentOS.getOSName();
    }
    bool isInfected()
    {
        return isPCInfected;
    }
    void infectPC()
    {
        this->isPCInfected = true;
    }
    void changeNumber(unsigned int newNumber)
    {
        this->numberOfPC = newNumber;
    }

    unsigned int getNumber()
    {
        return numberOfPC;
    }
//-----------------------------------------------------------
protected:
    bool isPCInfected;
private:
    OperatingSystem currentOS;
    unsigned int numberOfPC;
    void tryToInfectPC()
    {
        srand(time(0));
        this->isPCInfected = (((rand() * 71) % 100) < this->currentOS.getOSChanceToCatchVirus());
    }
};













