#include "tictactoe.h"
#include "ui_tictactoe.h"

TicTacToe::TicTacToe(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TicTacToe), fieldSize(3), isX(true), signalMapper(new QSignalMapper(this)), freeButtons(fieldSize), sizeSqr(9)
{
    ui->setupUi(this);

    buildLayout();

    connect(ui->sizeSpinBox, SIGNAL(valueChanged(int)), this, SLOT(refreshButtons(int)));
}

TicTacToe::~TicTacToe()
{
    delete signalMapper;
    for (unsigned int i = 0; i < sizeSqr; i++)
    {
        delete gameButtons[i];
    }
    delete ui;
}

void TicTacToe::refreshButtons(int newSize)
{
    for (unsigned int i = 0; i < sizeSqr; i++)
            delete gameButtons[i];
    delete[] gameButtons;
    fieldSize = newSize;
    sizeSqr = fieldSize * fieldSize;
    delete signalMapper;
    signalMapper = new QSignalMapper(this);
    buildLayout();
}

void TicTacToe::buttonClicked(int i)
{
    ui->sizeSpinBox->setEnabled(false);
    QPushButton *tmp = gameButtons[i];
    tmp->setEnabled(false);
    tmp->setText((isX ? "X" : "O"));
    freeButtons--;
    if (checkWin(tmp, i))
    {
        QString xOrO = (isX ? "X" : "O");
        QMessageBox::information(this, "Win", "Player " + xOrO);
        refreshButtons(fieldSize);
    }
    else if (freeButtons == 0)
    {
        QMessageBox::information(this, "Draw", "Haha!");
        refreshButtons(fieldSize);
    }
    isX = (isX ? false : true);
    ui->sizeSpinBox->setEnabled(true);
}

bool TicTacToe::checkWin(QPushButton *tmp, unsigned int position)
{
    bool isWinner = true;
    unsigned int tmp1 = position / fieldSize;
    unsigned int tmp2 = position % fieldSize;
    //row
    for (int i = tmp1 * fieldSize; i < (tmp1 + 1) * fieldSize; i++)
    {
        if (gameButtons[i]->text() != tmp->text())
        {
            isWinner = false;
            break;
        }
    }
    if (isWinner)
        return isWinner;
    isWinner = true;
    //column
    for (int i = tmp2; i < sizeSqr; i += fieldSize)
    {
        if (gameButtons[i]->text() != tmp->text())
        {
            isWinner = false;
            break;
        }
    }
    if (isWinner)
        return isWinner;
    isWinner = true;
    if (tmp1 == tmp2)
    {
        for (int i = 0; i < sizeSqr; i = i + (fieldSize + 1))
        {
            if (gameButtons[i]->text() != tmp->text())
            {
                isWinner = false;
                break;
            }
        }
    }
    if (isWinner && tmp1 == tmp2)
        return isWinner;
    isWinner = true;
    if (position % (fieldSize - 1) == 0 && position != 0)
    {
        for (int i = fieldSize - 1; i < sizeSqr - 1; i = i + (fieldSize - 1))
        {
            if (gameButtons[i]->text() != tmp->text())
            {
                isWinner = false;
                break;
            }
        }
        return isWinner;
    }
    else
        return false;
}

void TicTacToe::buildLayout()
{
    freeButtons = sizeSqr;
    int x = 0;
    int y = 40;
    this->resize(fieldSize * 55, 40 + fieldSize * 55);
    this->setMinimumWidth(fieldSize * 55);
    this->setMinimumHeight(40 + fieldSize * 55);
    this->setMaximumWidth(fieldSize * 55);
    this->setMaximumHeight(40 + fieldSize * 55);
    gameButtons = new QPushButton*[sizeSqr];
    for (unsigned int i = 0; i < fieldSize; i++)
    {
        for (unsigned int j = 0; j < fieldSize; j++)
        {
            QPushButton *button = new QPushButton(this);
            connect(button, SIGNAL(clicked()), signalMapper, SLOT(map()));
            signalMapper->setMapping(button, i * fieldSize + j);
            gameButtons[i * fieldSize + j] = button;
            button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            button->resize(50, 50);
            button->move(x, y);
            x = x + 55;
            button->setText("");
            connect(button, SIGNAL(clicked()), this, SLOT(buttonClicked(int)));
            button->show();
        }
        x = 0;
        y = y + 55;
    }
    connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(buttonClicked(int)));
}
