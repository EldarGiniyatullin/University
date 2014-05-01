#include "ubercalculator.h"
#include "ui_ubercalculator.h"

UberCalculator::UberCalculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UberCalculator)
{
    ui->setupUi(this);

    numericButtons = new QSignalMapper(this);
    operatorButtons = new QSignalMapper(this);

    /**
     * @brief connecting numeric buttons
     */
    connect(ui->pushButton_numeric0, SIGNAL(pressed()), numericButtons, SLOT(map()));
    numericButtons->setMapping(ui->pushButton_numeric0, 0);
    connect(ui->pushButton_numeric1, SIGNAL(pressed()), numericButtons, SLOT(map()));
    numericButtons->setMapping(ui->pushButton_numeric1, 1);
    connect(ui->pushButton_numeric2, SIGNAL(pressed()), numericButtons, SLOT(map()));
    numericButtons->setMapping(ui->pushButton_numeric2, 2);
    connect(ui->pushButton_numeric3, SIGNAL(pressed()), numericButtons, SLOT(map()));
    numericButtons->setMapping(ui->pushButton_numeric3, 3);
    connect(ui->pushButton_numeric4, SIGNAL(pressed()), numericButtons, SLOT(map()));
    numericButtons->setMapping(ui->pushButton_numeric4, 4);
    connect(ui->pushButton_numeric5, SIGNAL(pressed()), numericButtons, SLOT(map()));
    numericButtons->setMapping(ui->pushButton_numeric5, 5);
    connect(ui->pushButton_numeric6, SIGNAL(pressed()), numericButtons, SLOT(map()));
    numericButtons->setMapping(ui->pushButton_numeric6, 6);
    connect(ui->pushButton_numeric7, SIGNAL(pressed()), numericButtons, SLOT(map()));
    numericButtons->setMapping(ui->pushButton_numeric7, 7);
    connect(ui->pushButton_numeric8, SIGNAL(pressed()), numericButtons, SLOT(map()));
    numericButtons->setMapping(ui->pushButton_numeric8, 8);
    connect(ui->pushButton_numeric9, SIGNAL(pressed()), numericButtons, SLOT(map()));
    numericButtons->setMapping(ui->pushButton_numeric9, 9);


    /**
     * @brief connecting operator buttons
     */
    connect(ui->pushButton_addition, SIGNAL(pressed()), operatorButtons, SLOT(map()));
    operatorButtons->setMapping(ui->pushButton_addition, 0);
    connect(ui->pushButton_subtraction, SIGNAL(pressed()), operatorButtons, SLOT(map()));
    operatorButtons->setMapping(ui->pushButton_subtraction, 1);
    connect(ui->pushButton_multiplication, SIGNAL(pressed()), operatorButtons, SLOT(map()));
    operatorButtons->setMapping(ui->pushButton_multiplication, 2);
    connect(ui->pushButton_division, SIGNAL(pressed()), operatorButtons, SLOT(map()));
    operatorButtons->setMapping(ui->pushButton_division, 3);

    /**
     * @brief connecting SignalMappers and methods
     */
    connect(numericButtons, SIGNAL(mapped(int)), this, SLOT(numericButtonPressed(int)));
    connect(operatorButtons, SIGNAL(mapped(int)), this, SLOT(operatorButtonPressed(int)));

    connect(ui->pushButton_dot, SIGNAL(pressed()), this, SLOT(dotButtonPressed()));
    connect(ui->pushButton_result, SIGNAL(pressed()), this, SLOT(resultButtonPressed()));
    connect(ui->pushButton_deleteLast, SIGNAL(pressed()), this, SLOT(deleteLastSymbol()));
    connect(ui->pushButton_deleteAll, SIGNAL(pressed()), this, SLOT(deleteAll()));
    connect(ui->pushButton_openBreak, SIGNAL(pressed()), this, SLOT(openBreakPressed()));
    connect(ui->pushButton_closeBreak, SIGNAL(pressed()), this, SLOT(closedBreakPressed()));



    /**
      *@brief setting ui->mainWidget as the central
      */
     this->setCentralWidget(ui->mainPanel);

   /**
     *@brief leds the pressing of ui->exitButton to exit the program
     */
     connect(ui->exitButton, SIGNAL(triggered()), this, SLOT(close()));
}

UberCalculator::~UberCalculator()
{
    delete ui;
}

void UberCalculator::resultButtonPressed()
{
    calculator = new StackCalculator();
    calculator->expInString = ui->expressionPanel->text();
    calculator->readExpressionFromString();
    calculator->reversePolishNotation();
    calculator->calculateReversePolishNotation();
    if (calculator->isCorrect)
        ui->expressionPanel->setText(QString::number(calculator->result));
    else
        ui->expressionPanel->setText("0");
    delete calculator;
}

void UberCalculator::dotButtonPressed()
{
    ui->expressionPanel->setText(ui->expressionPanel->text() + ".");
}

void UberCalculator::operatorButtonPressed(int operationNumber)
{
    switch (operationNumber)
    {
    case 0:
        ui->expressionPanel->setText(ui->expressionPanel->text() + "+");
        break;
    case 1:
        ui->expressionPanel->setText(ui->expressionPanel->text() + "-");
        break;
    case 2:
        ui->expressionPanel->setText(ui->expressionPanel->text() + "*");
        break;
    case 3:
        ui->expressionPanel->setText(ui->expressionPanel->text() + "/");
        break;
    default:
        ui->expressionPanel->text() + "+";
        break;
    }
}

void UberCalculator::numericButtonPressed(int pressedNumeric)
{
    ui->expressionPanel->setText(ui->expressionPanel->text() + QString::number(pressedNumeric));
}

void UberCalculator::deleteLastSymbol()
{
    QString tmp = ui->expressionPanel->text();
    tmp.remove(tmp.length() - 1, tmp.length());
    ui->expressionPanel->setText(tmp);
}

void UberCalculator::deleteAll()
{
    ui->expressionPanel->setText("");
}

void UberCalculator::openBreakPressed()
{
    ui->expressionPanel->setText(ui->expressionPanel->text() + "(");
}

void UberCalculator::closedBreakPressed()
{
    ui->expressionPanel->setText(ui->expressionPanel->text() + ")");
}

