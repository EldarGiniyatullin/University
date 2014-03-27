#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "simplecalculator.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->comboBox->addItem("+", 0);
    ui->comboBox->addItem("-", 1);
    ui->comboBox->addItem("*", 2);
    ui->comboBox->addItem("/", 3);

    this->setCentralWidget(ui->horizontalWidget);

    connect(ui->spinBox, SIGNAL(valueChanged(int)), this, SLOT(lineEditOutput()));
    connect(ui->comboBox, SIGNAL(activated(int)), this, SLOT(lineEditOutput()));
    connect(ui->spinBox_2, SIGNAL(valueChanged(int)), this, SLOT(lineEditOutput()));
    connect(ui->action, SIGNAL(triggered()), this, SLOT(close()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::convertToQString(int numberToConvert)
{
    QString tmp = QString::number(numberToConvert);
    return tmp;
}

void MainWindow::lineEditOutput()
{
    if (ui->spinBox_2->value() == 0 && ui->comboBox->currentIndex() == 3)
        ui->lineEdit->setText("N/A");
    else
        ui->lineEdit->setText(convertToQString(SimpleCalculator::calculate(ui->spinBox->value(), ui->comboBox->currentIndex(), ui->spinBox_2->value())));
}
