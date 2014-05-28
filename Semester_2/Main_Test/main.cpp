#include "progressbarwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ProgressBarWindow w;
    w.show();

    return a.exec();
}
