#include "ubercalculator.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UberCalculator w;
    w.show();

    return a.exec();
}
