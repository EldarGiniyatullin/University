#include "runningbitton.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RunningBitton w;
    w.show();

    return a.exec();
}
