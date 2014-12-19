#pragma once

#include <QList>
#include <time.h>
#include <iostream>
#include "personalcomputer.h"

using namespace OS;
using std::cin;
using std::cout;

/**
 * @brief The LocalNet class имитирует работу локальной сети с несколькоим компьютерами в ней
 */
class LocalNet
{
public:
    LocalNet(int numberOfPCs);
    ~LocalNet()
    {
    }
    /**
     * @brief check проверяет конкретный компьютер сети на наличие вируса
     */
    void check(PersonalComputer &PC);
    /**
     * @brief connectWithAll соединяет конкретный компьютер с остальными компьютерами сети
     */
    void connectWithAll(PersonalComputer &PC, int number);
    /**
     * @brief work проводит "ходы" сети и выводит информацию о компьютерах
     */
    void work();
    void step();

    friend class TestLocalNet;
private:
    /**
     * @brief listOfPCs список компьютеров сети
     */
    QList<PersonalComputer> listOfPCs;
    unsigned int numberOfPCs;
};








