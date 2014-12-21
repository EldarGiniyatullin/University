#pragma once

#include <QVector>
#include <QList>
#include <ctime>
#include <iostream>
#include "personalcomputer.h"

using std::cin;
using std::cout;

/**
 * @brief The Infector class содержит функцию, в которой заражаемость ПК зависит от его вероятности заражения
 */
class Infector
{
public:
    Infector()
    {

    }
    virtual void tryToInfectPC(PersonalComputer &pcToInfect)
    {
        srand(time(0));
        pcToInfect.isPCInfected = (((rand() * 71) % 100) < pcToInfect.getOS().getOSChanceToCatchVirus());
    }
};

/**
 * @brief The TotalInfector class содержит функцию, которая однозначно заражает ПК
 */
class TotalInfector : public Infector
{
public:
    TotalInfector()
    {

    }
    virtual void tryToInfectPC(PersonalComputer &pcToInfect)
    {
        pcToInfect.isPCInfected = true;
    }
};

/**
 * @brief The ChanceInfector class содержит функцию, которая заражает ПК в случае, если ее вероятноть заражения выше наперед заданного значения
 */
class ChanceInfector : public Infector
{
public:
    ChanceInfector() : infectValue(55)
    {
    }
    ChanceInfector(int value) : infectValue(value)
    {
    }
    virtual void tryToInfectPC(PersonalComputer &pcToInfect)
    {
        pcToInfect.isPCInfected = (pcToInfect.getOS().getOSChanceToCatchVirus() < infectValue ? false : true);
    }
private:
    int infectValue;
};


/**
 * @brief The LocalNet class имитирует работу локальной сети
 */
class LocalNet
{
public:
    LocalNet();
    LocalNet(unsigned int numberOfPCs, Infector *infector = new Infector());
    ~LocalNet()
    {

    }
    /**
     * @brief connectPCs связывает два ПК в графе смежности
     */
    void connectPCs(unsigned int pc1, unsigned int pc2);
    void infect(unsigned int pcNumber);
    void printStatus();
    /**
     * @brief tryToInfectPC пытается заразить ПК. Результат зависит от конкретного объекта infectFunction
     */
    void tryToInfectPC(PersonalComputer &pc);
    /**
     * @brief step - "ход" в локальной сети
     */
    void step();
    friend class TestLocalNet;
private:
    void netConnection(PersonalComputer &pc1, PersonalComputer &pc2);
    void initializeMatrix();
    unsigned int netSize;
    QVector<QVector<bool> > matrix;
    QVector<PersonalComputer> listOfPCs;
    QVector<bool> areJustInfected;
    Infector *infectFunction;
    QList<OperatingSystem> listOfOS;
};
