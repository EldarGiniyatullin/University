#pragma once

namespace OS
{
class OperatingSystem
{
public:
    OperatingSystem(char* name, unsigned int chance)
    {
        this->osName = name;
        this->chanceToCatchVirus = chance;
    }
    unsigned int getOSChanceToCatchVirus()
    {
        return chanceToCatchVirus;
    }
    char* getOSName()
    {
        return osName;
    }
protected:
    unsigned int chanceToCatchVirus;
    char* osName;
};

const OperatingSystem windows7("Windows7\0", 90);

const OperatingSystem windows8("Windows8\0", 95);

const OperatingSystem linux("Linux\0", 80);

const OperatingSystem mac("MacOS\0", 85);

const OperatingSystem osList[] = {windows7, windows8, linux, mac};

const unsigned int osListSize = 4;
}


