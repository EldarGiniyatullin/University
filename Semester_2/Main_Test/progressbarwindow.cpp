#include "progressbarwindow.h"
#include "ui_progressbarwindow.h"

ProgressBarWindow::ProgressBarWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ProgressBarWindow)
{
    ui->setupUi(this);

    ui->progressBar->setMaximum(100);
    ui->progressBar->setMinimum(0);
    ui->pushButton->show();
    ui->progressBar->show();
    ui->pushButton_2->hide();
    this->setCentralWidget(ui->horizontalLayoutWidget);
    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(startUpRising()));
    connect(ui->pushButton_2, SIGNAL(clicked(bool)), this, SLOT(close()));
}

ProgressBarWindow::~ProgressBarWindow()
{
    delete ui;
}

void ProgressBarWindow::startUpRising()
{
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(upBar()));
    timer->start(30);
}

void ProgressBarWindow::upBar()
{
    ui->progressBar->setValue(ui->progressBar->value() + 1);
    if (ui->progressBar->value() == ui->progressBar->maximum())
    {
        timer->stop();
        ui->pushButton_2->show();
    }
}
