#include "ubercalculator.h"
#include "teststackcalculator.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    TestCalcuator testCalcuator;
    QTest::qExec(&testCalcuator);

    QApplication a(argc, argv);
    UberCalculator w;
    w.show();

    return a.exec();
}
