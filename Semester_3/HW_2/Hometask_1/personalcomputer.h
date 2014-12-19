#pragma once

#include <time.h>
#include <cstdlib>
#include "operatingsystem.h"

using namespace OS;

/**
 * @brief The PersonalComputer class имитирует ПК
 */
class PersonalComputer
{
public:
    PersonalComputer(OperatingSystem OS) : isPCInfected(false), currentOS(OS) {}
    ~PersonalComputer() {}
//------------------------------------------------------------
    /**
     * @brief changeOS меняет ОС, при этом уничтожая имеющиеся вирусы
     */
    void changeOS(OperatingSystem OS);
    void connectWithPC(PersonalComputer otherPC);
    QString getCurrentOSName();

    OperatingSystem getOS()
    {
        return this->currentOS;
    }
    bool isInfected()
    {
        return isPCInfected;
    }
    void infectPC();

//-----------------------------------------------------------
protected:
    bool isPCInfected;
private:
    OperatingSystem currentOS;
    void tryToInfectPC();
};













