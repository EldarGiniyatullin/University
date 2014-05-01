#ifndef UBERCALCULATOR_H
#define UBERCALCULATOR_H

#include <QMainWindow>
#include <QSignalMapper>
#include <QPushButton>
#include "stackcalculator.h"

namespace Ui {
class UberCalculator;
}

class UberCalculator : public QMainWindow
{
    Q_OBJECT

public:
    explicit UberCalculator(QWidget *parent = 0);
    ~UberCalculator();

private slots:
    void resultButtonPressed();
    void dotButtonPressed();
    void operatorButtonPressed(int operationNumber);
    void numericButtonPressed(int pressedNumeric);
    void deleteLastSymbol();
    void deleteAll();
    void openBreakPressed();
    void closedBreakPressed();

private:
    Ui::UberCalculator *ui;
    QSignalMapper *numericButtons;
    QSignalMapper *operatorButtons;
    StackCalculator *calculator;
};

#endif // UBERCALCULATOR_H
