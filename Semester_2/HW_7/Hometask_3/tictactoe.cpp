#include "tictactoe.h"
#include "ui_tictactoe.h"

TicTacToe::TicTacToe(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TicTacToe), isWinner(false), oldSize(3), isX(true)
{
    ui->setupUi(this);

    isWinner = false;

    buildLayout();

//    buttons.clear();

//    connect(ui->buttonsLayout);
    connect(ui->sizeSpinBox, SIGNAL(valueChanged(int)), this, SLOT(refreshButtons(int)));
}

TicTacToe::~TicTacToe()
{
    delete ui;
}

void TicTacToe::refreshButtons(int newSize)
{
    for (int i = 0; i < oldSize; i++)
    {
        for (int j = 0; j < oldSize; j++)
        {
            delete ui->buttonsLayout->itemAtPosition(i, j)->widget();
        }
    }
    oldSize = newSize;
    for (int i = 0; i < newSize; i++)
    {
        for (int j = 0; j < newSize; j++)
        {
            QPushButton *button = new QPushButton;
            button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            ui->buttonsLayout->addWidget(button, i, j);
            button->setText(" ");
            connect(button, SIGNAL(clicked()), this, SLOT(buttonClicked()));
        }
    }
}

void TicTacToe::buttonClicked()
{
    QPushButton *tmp = dynamic_cast<QPushButton *>(sender());
    tmp->setText((isX ? "X" : "O"));
    isX = (isX ? false : true);
}

void TicTacToe::checkWin(unsigned int i, unsigned int j)
{

}

void TicTacToe::buildLayout()
{
    for (int i = 0; i < oldSize; i++)
    {
        for (int j = 0; j < oldSize; j++)
        {
            QPushButton *button = new QPushButton;
            button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            ui->buttonsLayout->addWidget(button, i, j);
            button->setText(" ");
            connect(button, SIGNAL(clicked()), this, SLOT(buttonClicked()));
        }
    }
}
