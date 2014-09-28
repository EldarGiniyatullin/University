#pragma once

#include <QList>
#include <time.h>
#include <iostream>
#include "personalcomputer.h"

using namespace OS;
using std::cin;
using std::cout;

class LocalNet
{
public:
    LocalNet(int numberOfPCs, OperatingSystem listOfOS[], int numberOfOS);
//private:
    void check(PersonalComputer &PC);
    void connectWithAll(PersonalComputer &PC, int number);
    QList<PersonalComputer> listOfPCs;
    void work();
    unsigned int numberOfPCs;
};

LocalNet::LocalNet(int numberOfPCs, OperatingSystem listOfOS[], int numberOfOS)
{
    this->numberOfPCs = numberOfPCs;
    for (int i = 0; i < this->numberOfPCs; i++)
    {
        listOfPCs.append(PersonalComputer(listOfOS[i % numberOfOS]));
        listOfPCs[i].changeNumber(i);
        if (i % numberOfOS == 0)
            listOfPCs[i].infectPC();
    }
}

void LocalNet::check(PersonalComputer &PC)
{
    if (PC.isInfected())
        PC.changeOS(osList[rand() % osListSize]);
}

void LocalNet::connectWithAll(PersonalComputer &PC, int number)
{
    for (int i = number; i < numberOfPCs; i++)
        PC.connectWithPC(listOfPCs[i]);

}

void LocalNet::work()
{
    char tmp = '\0';
    while(true)
    {
        cout << "-----------------------------------------------------------\n";
        for (int i = 0; i < this->numberOfPCs; i++)
        {
            cout <<  listOfPCs[i].getNumber() << " - " << listOfPCs[i].getCurrentOSName() << " - " << (listOfPCs[i].isInfected() ? "Infected" : "Not infected") << "\n";
            check(listOfPCs[i]);
            connectWithAll(listOfPCs[i], i);
        }
        cout << "Next step? Y/N\n";
        cin >> tmp;
        if (tmp == 'N')
            break;
    }

}
