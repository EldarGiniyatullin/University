#ifndef RUNNINGBITTON_H
#define RUNNINGBITTON_H

#include <QMainWindow>
#include <QPushButton>
#include <time.h>
#include <QEvent>
#include <QTimer>
#include <QMouseEvent>

namespace Ui {
class RunningBitton;
}
/**
 * @brief The RunningBitton class implements a button that "runs" out of a mouse
 */
class RunningBitton : public QMainWindow
{
    Q_OBJECT

public:
    explicit RunningBitton(QWidget *parent = 0);
    ~RunningBitton();

private slots:
    /**
     * @brief run moves theButton to random place
     */
    void run();
    /**
     * @brief emptyText sets theButton an empty text
     */
    void emptyText();

private:
    int value1;
    int value2;
    Ui::RunningBitton *ui;
    QEvent *event;
    QPushButton* theButton;
    bool eventFilter(QObject *object, QEvent *event);
};

#endif // RUNNINGBITTON_H
