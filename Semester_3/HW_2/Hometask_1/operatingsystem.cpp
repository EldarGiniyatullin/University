#include "operatingsystem.h"


OperatingSystem::OperatingSystem(QString name, unsigned int chance)
{
    this->osName = name;
    this->chanceToCatchVirus = chance;
}

unsigned int OperatingSystem::getOSChanceToCatchVirus()
{
    return chanceToCatchVirus;
}

QString OperatingSystem::getOSName()
{
    return osName;
}
