#include "localnet.h"




LocalNet::LocalNet(int numberOfPCs)
{
    this->numberOfPCs = numberOfPCs;
    for (int i = 0; i < this->numberOfPCs; i++)
    {
        listOfPCs.append(PersonalComputer(OS::osList[i % OS::osListSize]));
        if (i % OS::osListSize == 0)
            listOfPCs[i].infectPC();
    }
}


void LocalNet::check(PersonalComputer &PC)
{
    if (PC.isInfected())
        PC.changeOS(osList[(rand() * rand()) % osListSize]);
}


void LocalNet::connectWithAll(PersonalComputer &PC, int number)
{
    for (int i = number; i < listOfPCs.size(); i++)
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
            cout <<  i  << " - " << listOfPCs[i].getCurrentOSName().toLocal8Bit().constData() << " - " << (listOfPCs[i].isInfected() ? "Infected" : "Not infected") << "\n";
        }
        step();
        cout << "Next step? Y/N\n";
        cin >> tmp;
        if (tmp == 'N')
            break;
    }

}

void LocalNet::step()
{
    for (int i = 0; i < this->numberOfPCs; i++)
    {
    check(listOfPCs[i]);
    connectWithAll(listOfPCs[i], i);
    }
}
