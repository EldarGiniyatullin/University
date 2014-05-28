#pragma once

#include <QMainWindow>
#include <QProgressBar>
#include <QPushButton>
#include <QTimer>
#include <QApplication>
#include <QTime>

namespace Ui {
class ProgressBarWindow;
}

class ProgressBarWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ProgressBarWindow(QWidget *parent = 0);
    ~ProgressBarWindow();


private slots:
    void startUpRising();
    void upBar();


private:
    Ui::ProgressBarWindow *ui;

    QTimer *timer;

};
