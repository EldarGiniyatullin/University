#pragma once

#include <time.h>
#include <cstdlib>
#include "operatingsystem.h"


/**
 * @brief The PersonalComputer class имитирует ПК
 */
class PersonalComputer
{
public:
    PersonalComputer() : isPCInfected(false), currentOS(OperatingSystem("Windows7\0", 90)) {}
    PersonalComputer(OperatingSystem OS) : isPCInfected(false), currentOS(OS) {}
    ~PersonalComputer() {}
//------------------------------------------------------------
    /**
     * @brief changeOS меняет ОС, при этом уничтожая имеющиеся вирусы
     */
    void changeOS(OperatingSystem OS);
    QString getCurrentOSName();
    OperatingSystem getOS()
    {
        return this->currentOS;
    }
    bool isInfected()
    {
        return isPCInfected;
    }
    /**
     * @brief infectPC абсолютно заражает компьютер
     */
    void infectPC();

//-----------------------------------------------------------
    bool isPCInfected;
private:
    OperatingSystem currentOS;
};
