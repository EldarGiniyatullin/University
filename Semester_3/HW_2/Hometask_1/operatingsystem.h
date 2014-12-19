#pragma once


#include <QString>


namespace OS
{
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

const OperatingSystem windows7("Windows7\0", 90);

const OperatingSystem windows8("Windows8\0", 95);

const OperatingSystem linux("Linux\0", 80);

const OperatingSystem mac("MacOS\0", 85);

const OperatingSystem osList[] = {windows7, windows8, linux, mac};

const unsigned int osListSize = 4;
}


