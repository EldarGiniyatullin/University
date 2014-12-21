#pragma once


#include <QString>

/**
 * @brief The OperatingSystem class имитирует операционную систему
 */
class OperatingSystem
{
public:
    OperatingSystem(QString name, unsigned int chance);
    unsigned int getOSChanceToCatchVirus();
    QString getOSName();
    bool operator==(const OperatingSystem &b)
    {
        return (this->chanceToCatchVirus == b.chanceToCatchVirus && this->osName == b.osName ? true : false);
    }
protected:
    unsigned int chanceToCatchVirus;
    QString osName;
};


