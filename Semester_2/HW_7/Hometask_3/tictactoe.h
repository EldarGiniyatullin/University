#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <QMainWindow>
#include <QPushButton>

namespace Ui {
class TicTacToe;
}

class TicTacToe : public QMainWindow
{
    Q_OBJECT

public:
    explicit TicTacToe(QWidget *parent = 0);
    ~TicTacToe();

private slots:
    void refreshButtons(int newSize);
    void buttonClicked();
    void checkWin(unsigned int i, unsigned int j);

private:
    Ui::TicTacToe *ui;
    bool isWinner;
    bool isX;
    struct Coordinates
    {
        unsigned int row;
        unsigned int column;
    };
    unsigned int oldSize;
    void buildLayout();
//    QMap<QPushButton*, Coordinates> buttons;
};

#endif // TICTACTOE_H
