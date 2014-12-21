#include "localnet.h"


LocalNet::LocalNet() : infectFunction(new Infector())
{
    listOfOS << OperatingSystem("Windows7\0", 90) << OperatingSystem("Windows8\0", 70) << OperatingSystem("Linux\0", 50) << OperatingSystem("MacOS\0", 30);
}


LocalNet::LocalNet(unsigned int numberOfPCs, Infector *infector) : netSize(numberOfPCs), infectFunction(infector)
{
    listOfOS << OperatingSystem("Windows7\0", 90) << OperatingSystem("Windows8\0", 70) << OperatingSystem("Linux\0", 50) << OperatingSystem("MacOS\0", 30);
    initializeMatrix();
}

void LocalNet::infect(unsigned int pcNumber)
{
    listOfPCs[pcNumber].infectPC();
}

void LocalNet::printStatus()
{
    cout << "-----------------------------------------------------------\n";
    for (int i = 0; i < netSize; i++)
    {
        cout <<  i  << " - " << listOfPCs[i].getCurrentOSName().toLocal8Bit().constData() << " - " << (listOfPCs[i].isInfected() ? "Infected" : "Not infected") << "\n";
    }
}

void LocalNet::tryToInfectPC(PersonalComputer &pc)
{
    this->infectFunction->tryToInfectPC(pc);
}

void LocalNet::step()
{
    areJustInfected = QVector<bool>(netSize, false);
    for (int i = 0; i < netSize; i++)
    {
        for (int j = i + 1; j < netSize; j++)
        {
            if (matrix[i][j] && !areJustInfected[i] && !areJustInfected[j])
            {
                int notInfected = (listOfPCs[i].isInfected() ? j : i);
                netConnection(listOfPCs[j], listOfPCs[i]);
                if (listOfPCs[notInfected].isInfected())
                    areJustInfected[notInfected] = true;
            }
        }
    }
    for (int i = 0; i < netSize; i++)
    {
        if (!areJustInfected[i] && listOfPCs[i].isInfected())
        {
            listOfPCs[i].changeOS(listOfOS[(listOfOS.indexOf(listOfPCs[i].getOS()) + 1) % listOfOS.size()]);
        }
    }
}

void LocalNet::netConnection(PersonalComputer &pc1, PersonalComputer &pc2)
{
    if (pc2.isInfected())
        tryToInfectPC(pc1);
    else if ((!pc2.isInfected()) && pc1.isInfected())
        tryToInfectPC(pc2);
}

void LocalNet::initializeMatrix()
{
    matrix = QVector<QVector<bool> > (netSize);
    for (unsigned int i = 0; i < netSize; i++)
    {
        matrix[i] = QVector<bool>(netSize, false);
    }
    listOfPCs = QVector<PersonalComputer>(netSize, listOfOS[0]);
    areJustInfected = QVector<bool>(netSize, false);
}



void LocalNet::connectPCs(unsigned int pc1, unsigned int pc2)
{
    if (pc1 != pc2 && pc1 < netSize && pc2 < netSize)
    {
        matrix[pc1][pc2] = true;
        matrix[pc2][pc1] = true;
    }
}
