#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <QMap>
#include <QSignalMapper>
#include <QMainWindow>
#include <QPushButton>
#include <QMapIterator>
#include <QMessageBox>
#include <QString>

namespace Ui {
class TicTacToe;
}

/**
 * @brief The TicTacToe class реализует графическое приложение для игры в крестики-нолики
 */
class TicTacToe : public QMainWindow
{
    Q_OBJECT

public:
    explicit TicTacToe(QWidget *parent = 0);
    ~TicTacToe();

private slots:
    /**
     * @brief refreshButtons создает чистое поле размера newSize (выбранного пользователем)
     */
    void refreshButtons(int newSize);
    void buttonClicked(int i);

private:
    Ui::TicTacToe *ui;
    /**
     * @brief isX равен true, если после нажатия на кнопку появится X, если O - false
     */
    bool isX;
    /**
     * @brief checkWin проверяет, победил ли кто-либо из игроков
     * @param tmp кнопка, после нажатия которой следует проверка
     * @param position - порядковый номер кнопкиы
     * @return true, если есть победитель, иначе false
     */
    bool checkWin(QPushButton *tmp, unsigned int position);
    QSignalMapper *signalMapper;
    unsigned int fieldSize;
    /**
     * @brief buildLayout строит набор игровых кнопок
     */
    void buildLayout();
    /**
     * @brief gameButtons предназначен для хранения всех кнопок
     */
    QPushButton **gameButtons;
    /**
     * @brief freeButtons - количество еще не нажатых кнопок
     */
    unsigned int freeButtons;
    /**
     * @brief sizeSqr = fieldSize^2
     */
    unsigned int sizeSqr;
};

#endif // TICTACTOE_H
