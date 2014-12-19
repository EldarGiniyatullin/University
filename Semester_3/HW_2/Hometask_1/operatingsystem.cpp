#include "operatingsystem.h"


OS::OperatingSystem::OperatingSystem(QString name, unsigned int chance)
{
    this->osName = name;
    this->chanceToCatchVirus = chance;
}

unsigned int OS::OperatingSystem::getOSChanceToCatchVirus()
{
    return chanceToCatchVirus;
}

QString OS::OperatingSystem::getOSName()
{
    return osName;
}
