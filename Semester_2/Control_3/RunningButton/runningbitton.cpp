#include "runningbitton.h"
#include "ui_runningbitton.h"

RunningBitton::RunningBitton(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RunningBitton)
{
    ui->setupUi(this);

    value1 = 500;
    value2 = 500;
    srand(time(NULL));
    theButton = new QPushButton(this);
    theButton->resize(50, 50);
    theButton->move(rand() % value1, rand() % value1);
    theButton->show();

    theButton->installEventFilter(this);


//    connect(theButton, SIGNAL(QEvent::Enter), this, SLOT(run()));
    connect(ui->exitButton, SIGNAL(triggered()), this, SLOT(close()));
}

RunningBitton::~RunningBitton()
{
    delete theButton;
    delete ui;
}

void RunningBitton::run()
{
    srand(time(NULL));
    theButton->move((theButton->x() + rand() * 50) % value1, (theButton->y() + rand() * 50) % value2);
    theButton->setText("ha!");
    QTimer::singleShot(300, this, SLOT(emptyText()));
}

void RunningBitton::emptyText()
{
    theButton->setText("");
}


bool RunningBitton::eventFilter(QObject *object, QEvent *event)
{
    if (object == theButton)
    {
        if (event->type() == QEvent::Enter || event->type() == QEvent::Leave || event->type() == QEvent::HoverMove)
        {
//            while(!((QMouseEvent::x() < theButton->x() || ui->QMouseEvent::x() > (theButton->x() + 50))  && (ui->QMouseEvent::y() < theButton->y() || ui->QMouseEvent::y() > (theButton->y() + 50))))
            run();
            return true;
        }
    }
    return QMainWindow::eventFilter(object, event);
}
