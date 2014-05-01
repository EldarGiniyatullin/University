#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "simplecalculator.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

  /**
    *@brief creating the operations and matching them with numbers
    *@detailed this list of operands is potentially extendable, but the editor should accordingly correct the function SimpleCalculator::calculate()
    */
    ui->operatorsBox->addItem("+", 0);
    ui->operatorsBox->addItem("-", 1);
    ui->operatorsBox->addItem("*", 2);
    ui->operatorsBox->addItem("/", 3);

  /**
    *@brief setting ui->mainWidget as the central
    */
    this->setCentralWidget(ui->mainWidget);

  /**
    *@brief the signals that need for momental changing of the result situated in ui->lineEdit
    *@param ui->slotForFirstNumber the slot where user chooses the first operand
    *@param ui->slotForSecondNumber the slot where user chooses the second operand
    */
    connect(ui->slotForFirstNumber, SIGNAL(valueChanged(int)), this, SLOT(lineEditOutput()));
    connect(ui->operatorsBox, SIGNAL(activated(int)), this, SLOT(lineEditOutput()));
    connect(ui->slotForSecondNumber, SIGNAL(valueChanged(int)), this, SLOT(lineEditOutput()));

   /**
    *@brief leds the pressing of ui->exitButton to exit the program
    */
    connect(ui->exitButton, SIGNAL(triggered()), this, SLOT(close()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief function displays the result of binary operation on ui->slotForResult
 * @throw program puts "N/A" (not allowed) if there is a division by zero
 */
void MainWindow::lineEditOutput()
{
    if (ui->slotForSecondNumber->value() == 0 && ui->operatorsBox->currentIndex() == 3)
        ui->slotForResult->setText("N/A");
    else
        ui->slotForResult->setText(QString::number(SimpleCalculator::calculate(ui->slotForFirstNumber->value(), ui->operatorsBox->currentIndex(), ui->slotForSecondNumber->value())));
}
