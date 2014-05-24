/********************************************************************************
** Form generated from reading UI file 'ubercalculator.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UBERCALCULATOR_H
#define UI_UBERCALCULATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UberCalculator
{
public:
    QAction *exitButton;
    QAction *infoButton;
    QWidget *centralWidget;
    QWidget *mainPanel;
    QGridLayout *mainWidget;
    QPushButton *pushButton_addition;
    QPushButton *pushButton_multiplication;
    QPushButton *pushButton_division;
    QPushButton *pushButton_result;
    QPushButton *pushButton_numeric2;
    QPushButton *pushButton_numeric9;
    QPushButton *pushButton_numeric6;
    QPushButton *pushButton_numeric3;
    QPushButton *pushButton_numeric5;
    QPushButton *pushButton_numeric0;
    QLineEdit *expressionPanel;
    QPushButton *pushButton_subtraction;
    QPushButton *pushButton_numeric4;
    QPushButton *pushButton_numeric1;
    QPushButton *pushButton_dot;
    QPushButton *pushButton_numeric8;
    QPushButton *pushButton_numeric7;
    QPushButton *pushButton_closeBreak;
    QPushButton *pushButton_deleteAll;
    QPushButton *pushButton_deleteLast;
    QPushButton *pushButton_openBreak;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *infoMenu;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *UberCalculator)
    {
        if (UberCalculator->objectName().isEmpty())
            UberCalculator->setObjectName(QStringLiteral("UberCalculator"));
        UberCalculator->resize(390, 438);
        UberCalculator->setMinimumSize(QSize(381, 380));
        exitButton = new QAction(UberCalculator);
        exitButton->setObjectName(QStringLiteral("exitButton"));
        infoButton = new QAction(UberCalculator);
        infoButton->setObjectName(QStringLiteral("infoButton"));
        centralWidget = new QWidget(UberCalculator);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        mainPanel = new QWidget(centralWidget);
        mainPanel->setObjectName(QStringLiteral("mainPanel"));
        mainPanel->setGeometry(QRect(0, 0, 391, 381));
        mainPanel->setMinimumSize(QSize(380, 281));
        mainWidget = new QGridLayout(mainPanel);
        mainWidget->setSpacing(6);
        mainWidget->setContentsMargins(11, 11, 11, 11);
        mainWidget->setObjectName(QStringLiteral("mainWidget"));
        mainWidget->setSizeConstraint(QLayout::SetMinAndMaxSize);
        pushButton_addition = new QPushButton(mainPanel);
        pushButton_addition->setObjectName(QStringLiteral("pushButton_addition"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(35);
        sizePolicy.setVerticalStretch(55);
        sizePolicy.setHeightForWidth(pushButton_addition->sizePolicy().hasHeightForWidth());
        pushButton_addition->setSizePolicy(sizePolicy);
        pushButton_addition->setMinimumSize(QSize(35, 55));
        pushButton_addition->setBaseSize(QSize(35, 55));
        QFont font;
        font.setFamily(QStringLiteral("Courier New"));
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(false);
        font.setUnderline(false);
        font.setWeight(75);
        font.setStrikeOut(false);
        pushButton_addition->setFont(font);
        pushButton_addition->setAutoDefault(false);
        pushButton_addition->setDefault(false);
        pushButton_addition->setFlat(false);

        mainWidget->addWidget(pushButton_addition, 1, 3, 1, 1);

        pushButton_multiplication = new QPushButton(mainPanel);
        pushButton_multiplication->setObjectName(QStringLiteral("pushButton_multiplication"));
        sizePolicy.setHeightForWidth(pushButton_multiplication->sizePolicy().hasHeightForWidth());
        pushButton_multiplication->setSizePolicy(sizePolicy);
        pushButton_multiplication->setMinimumSize(QSize(35, 55));
        pushButton_multiplication->setBaseSize(QSize(35, 55));
        pushButton_multiplication->setFont(font);
        pushButton_multiplication->setAutoDefault(false);
        pushButton_multiplication->setDefault(false);
        pushButton_multiplication->setFlat(false);

        mainWidget->addWidget(pushButton_multiplication, 3, 3, 1, 1);

        pushButton_division = new QPushButton(mainPanel);
        pushButton_division->setObjectName(QStringLiteral("pushButton_division"));
        sizePolicy.setHeightForWidth(pushButton_division->sizePolicy().hasHeightForWidth());
        pushButton_division->setSizePolicy(sizePolicy);
        pushButton_division->setMinimumSize(QSize(35, 55));
        pushButton_division->setBaseSize(QSize(35, 55));
        pushButton_division->setFont(font);
        pushButton_division->setAutoDefault(false);
        pushButton_division->setDefault(false);
        pushButton_division->setFlat(false);

        mainWidget->addWidget(pushButton_division, 4, 3, 1, 1);

        pushButton_result = new QPushButton(mainPanel);
        pushButton_result->setObjectName(QStringLiteral("pushButton_result"));
        sizePolicy.setHeightForWidth(pushButton_result->sizePolicy().hasHeightForWidth());
        pushButton_result->setSizePolicy(sizePolicy);
        pushButton_result->setMinimumSize(QSize(35, 55));
        pushButton_result->setBaseSize(QSize(35, 55));
        pushButton_result->setFont(font);
        pushButton_result->setAutoDefault(false);
        pushButton_result->setDefault(false);
        pushButton_result->setFlat(false);

        mainWidget->addWidget(pushButton_result, 4, 2, 1, 1);

        pushButton_numeric2 = new QPushButton(mainPanel);
        pushButton_numeric2->setObjectName(QStringLiteral("pushButton_numeric2"));
        sizePolicy.setHeightForWidth(pushButton_numeric2->sizePolicy().hasHeightForWidth());
        pushButton_numeric2->setSizePolicy(sizePolicy);
        pushButton_numeric2->setMinimumSize(QSize(35, 55));
        pushButton_numeric2->setBaseSize(QSize(35, 55));
        pushButton_numeric2->setFont(font);
        pushButton_numeric2->setAutoDefault(false);
        pushButton_numeric2->setDefault(false);
        pushButton_numeric2->setFlat(false);

        mainWidget->addWidget(pushButton_numeric2, 1, 1, 1, 1);

        pushButton_numeric9 = new QPushButton(mainPanel);
        pushButton_numeric9->setObjectName(QStringLiteral("pushButton_numeric9"));
        sizePolicy.setHeightForWidth(pushButton_numeric9->sizePolicy().hasHeightForWidth());
        pushButton_numeric9->setSizePolicy(sizePolicy);
        pushButton_numeric9->setMinimumSize(QSize(35, 55));
        pushButton_numeric9->setBaseSize(QSize(35, 55));
        pushButton_numeric9->setFont(font);
        pushButton_numeric9->setAutoDefault(false);
        pushButton_numeric9->setDefault(false);
        pushButton_numeric9->setFlat(false);

        mainWidget->addWidget(pushButton_numeric9, 3, 2, 1, 1);

        pushButton_numeric6 = new QPushButton(mainPanel);
        pushButton_numeric6->setObjectName(QStringLiteral("pushButton_numeric6"));
        sizePolicy.setHeightForWidth(pushButton_numeric6->sizePolicy().hasHeightForWidth());
        pushButton_numeric6->setSizePolicy(sizePolicy);
        pushButton_numeric6->setMinimumSize(QSize(35, 55));
        pushButton_numeric6->setBaseSize(QSize(35, 55));
        pushButton_numeric6->setFont(font);
        pushButton_numeric6->setAutoDefault(false);
        pushButton_numeric6->setDefault(false);
        pushButton_numeric6->setFlat(false);

        mainWidget->addWidget(pushButton_numeric6, 2, 2, 1, 1);

        pushButton_numeric3 = new QPushButton(mainPanel);
        pushButton_numeric3->setObjectName(QStringLiteral("pushButton_numeric3"));
        sizePolicy.setHeightForWidth(pushButton_numeric3->sizePolicy().hasHeightForWidth());
        pushButton_numeric3->setSizePolicy(sizePolicy);
        pushButton_numeric3->setMinimumSize(QSize(35, 55));
        pushButton_numeric3->setBaseSize(QSize(35, 55));
        pushButton_numeric3->setFont(font);
        pushButton_numeric3->setAutoDefault(false);
        pushButton_numeric3->setDefault(false);
        pushButton_numeric3->setFlat(false);

        mainWidget->addWidget(pushButton_numeric3, 1, 2, 1, 1);

        pushButton_numeric5 = new QPushButton(mainPanel);
        pushButton_numeric5->setObjectName(QStringLiteral("pushButton_numeric5"));
        sizePolicy.setHeightForWidth(pushButton_numeric5->sizePolicy().hasHeightForWidth());
        pushButton_numeric5->setSizePolicy(sizePolicy);
        pushButton_numeric5->setMinimumSize(QSize(35, 55));
        pushButton_numeric5->setBaseSize(QSize(35, 55));
        pushButton_numeric5->setFont(font);
        pushButton_numeric5->setAutoDefault(false);
        pushButton_numeric5->setDefault(false);
        pushButton_numeric5->setFlat(false);

        mainWidget->addWidget(pushButton_numeric5, 2, 1, 1, 1);

        pushButton_numeric0 = new QPushButton(mainPanel);
        pushButton_numeric0->setObjectName(QStringLiteral("pushButton_numeric0"));
        sizePolicy.setHeightForWidth(pushButton_numeric0->sizePolicy().hasHeightForWidth());
        pushButton_numeric0->setSizePolicy(sizePolicy);
        pushButton_numeric0->setMinimumSize(QSize(35, 55));
        pushButton_numeric0->setBaseSize(QSize(35, 55));
        pushButton_numeric0->setFont(font);
        pushButton_numeric0->setAutoDefault(false);
        pushButton_numeric0->setDefault(false);
        pushButton_numeric0->setFlat(false);

        mainWidget->addWidget(pushButton_numeric0, 4, 0, 1, 1);

        expressionPanel = new QLineEdit(mainPanel);
        expressionPanel->setObjectName(QStringLiteral("expressionPanel"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(expressionPanel->sizePolicy().hasHeightForWidth());
        expressionPanel->setSizePolicy(sizePolicy1);
        expressionPanel->setMinimumSize(QSize(35, 55));
        QFont font1;
        font1.setPointSize(12);
        expressionPanel->setFont(font1);
        expressionPanel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        expressionPanel->setDragEnabled(false);
        expressionPanel->setReadOnly(true);

        mainWidget->addWidget(expressionPanel, 0, 0, 1, 6);

        pushButton_subtraction = new QPushButton(mainPanel);
        pushButton_subtraction->setObjectName(QStringLiteral("pushButton_subtraction"));
        sizePolicy.setHeightForWidth(pushButton_subtraction->sizePolicy().hasHeightForWidth());
        pushButton_subtraction->setSizePolicy(sizePolicy);
        pushButton_subtraction->setMinimumSize(QSize(35, 55));
        pushButton_subtraction->setBaseSize(QSize(35, 55));
        pushButton_subtraction->setFont(font);
        pushButton_subtraction->setAutoDefault(false);
        pushButton_subtraction->setDefault(false);
        pushButton_subtraction->setFlat(false);

        mainWidget->addWidget(pushButton_subtraction, 2, 3, 1, 1);

        pushButton_numeric4 = new QPushButton(mainPanel);
        pushButton_numeric4->setObjectName(QStringLiteral("pushButton_numeric4"));
        sizePolicy.setHeightForWidth(pushButton_numeric4->sizePolicy().hasHeightForWidth());
        pushButton_numeric4->setSizePolicy(sizePolicy);
        pushButton_numeric4->setMinimumSize(QSize(35, 55));
        pushButton_numeric4->setBaseSize(QSize(35, 55));
        pushButton_numeric4->setFont(font);
        pushButton_numeric4->setAutoDefault(false);
        pushButton_numeric4->setDefault(false);
        pushButton_numeric4->setFlat(false);

        mainWidget->addWidget(pushButton_numeric4, 2, 0, 1, 1);

        pushButton_numeric1 = new QPushButton(mainPanel);
        pushButton_numeric1->setObjectName(QStringLiteral("pushButton_numeric1"));
        sizePolicy.setHeightForWidth(pushButton_numeric1->sizePolicy().hasHeightForWidth());
        pushButton_numeric1->setSizePolicy(sizePolicy);
        pushButton_numeric1->setMinimumSize(QSize(35, 55));
        pushButton_numeric1->setBaseSize(QSize(35, 55));
        pushButton_numeric1->setFont(font);
        pushButton_numeric1->setAutoDefault(false);
        pushButton_numeric1->setDefault(false);
        pushButton_numeric1->setFlat(false);

        mainWidget->addWidget(pushButton_numeric1, 1, 0, 1, 1);

        pushButton_dot = new QPushButton(mainPanel);
        pushButton_dot->setObjectName(QStringLiteral("pushButton_dot"));
        sizePolicy.setHeightForWidth(pushButton_dot->sizePolicy().hasHeightForWidth());
        pushButton_dot->setSizePolicy(sizePolicy);
        pushButton_dot->setMinimumSize(QSize(35, 55));
        pushButton_dot->setBaseSize(QSize(35, 55));
        pushButton_dot->setFont(font);
        pushButton_dot->setAutoDefault(false);
        pushButton_dot->setDefault(false);
        pushButton_dot->setFlat(false);

        mainWidget->addWidget(pushButton_dot, 4, 1, 1, 1);

        pushButton_numeric8 = new QPushButton(mainPanel);
        pushButton_numeric8->setObjectName(QStringLiteral("pushButton_numeric8"));
        sizePolicy.setHeightForWidth(pushButton_numeric8->sizePolicy().hasHeightForWidth());
        pushButton_numeric8->setSizePolicy(sizePolicy);
        pushButton_numeric8->setMinimumSize(QSize(35, 55));
        pushButton_numeric8->setBaseSize(QSize(35, 55));
        pushButton_numeric8->setFont(font);
        pushButton_numeric8->setAutoDefault(false);
        pushButton_numeric8->setDefault(false);
        pushButton_numeric8->setFlat(false);

        mainWidget->addWidget(pushButton_numeric8, 3, 1, 1, 1);

        pushButton_numeric7 = new QPushButton(mainPanel);
        pushButton_numeric7->setObjectName(QStringLiteral("pushButton_numeric7"));
        sizePolicy.setHeightForWidth(pushButton_numeric7->sizePolicy().hasHeightForWidth());
        pushButton_numeric7->setSizePolicy(sizePolicy);
        pushButton_numeric7->setMinimumSize(QSize(35, 55));
        pushButton_numeric7->setBaseSize(QSize(35, 55));
        pushButton_numeric7->setFont(font);
        pushButton_numeric7->setAutoDefault(false);
        pushButton_numeric7->setDefault(false);
        pushButton_numeric7->setFlat(false);

        mainWidget->addWidget(pushButton_numeric7, 3, 0, 1, 1);

        pushButton_closeBreak = new QPushButton(mainPanel);
        pushButton_closeBreak->setObjectName(QStringLiteral("pushButton_closeBreak"));
        sizePolicy.setHeightForWidth(pushButton_closeBreak->sizePolicy().hasHeightForWidth());
        pushButton_closeBreak->setSizePolicy(sizePolicy);
        pushButton_closeBreak->setMinimumSize(QSize(35, 55));
        pushButton_closeBreak->setBaseSize(QSize(35, 55));
        pushButton_closeBreak->setFont(font);
        pushButton_closeBreak->setAutoDefault(false);
        pushButton_closeBreak->setDefault(false);
        pushButton_closeBreak->setFlat(false);

        mainWidget->addWidget(pushButton_closeBreak, 2, 4, 1, 1);

        pushButton_deleteAll = new QPushButton(mainPanel);
        pushButton_deleteAll->setObjectName(QStringLiteral("pushButton_deleteAll"));
        sizePolicy.setHeightForWidth(pushButton_deleteAll->sizePolicy().hasHeightForWidth());
        pushButton_deleteAll->setSizePolicy(sizePolicy);
        pushButton_deleteAll->setMinimumSize(QSize(35, 55));
        pushButton_deleteAll->setBaseSize(QSize(35, 55));
        pushButton_deleteAll->setFont(font);
        pushButton_deleteAll->setAutoDefault(false);
        pushButton_deleteAll->setDefault(false);
        pushButton_deleteAll->setFlat(false);

        mainWidget->addWidget(pushButton_deleteAll, 3, 4, 1, 1);

        pushButton_deleteLast = new QPushButton(mainPanel);
        pushButton_deleteLast->setObjectName(QStringLiteral("pushButton_deleteLast"));
        sizePolicy.setHeightForWidth(pushButton_deleteLast->sizePolicy().hasHeightForWidth());
        pushButton_deleteLast->setSizePolicy(sizePolicy);
        pushButton_deleteLast->setMinimumSize(QSize(35, 55));
        pushButton_deleteLast->setBaseSize(QSize(35, 55));
        pushButton_deleteLast->setFont(font);
        pushButton_deleteLast->setAutoDefault(false);
        pushButton_deleteLast->setDefault(false);
        pushButton_deleteLast->setFlat(false);

        mainWidget->addWidget(pushButton_deleteLast, 4, 4, 1, 1);

        pushButton_openBreak = new QPushButton(mainPanel);
        pushButton_openBreak->setObjectName(QStringLiteral("pushButton_openBreak"));
        sizePolicy.setHeightForWidth(pushButton_openBreak->sizePolicy().hasHeightForWidth());
        pushButton_openBreak->setSizePolicy(sizePolicy);
        pushButton_openBreak->setMinimumSize(QSize(35, 55));
        pushButton_openBreak->setBaseSize(QSize(35, 55));
        pushButton_openBreak->setFont(font);
        pushButton_openBreak->setAutoDefault(false);
        pushButton_openBreak->setDefault(false);
        pushButton_openBreak->setFlat(false);

        mainWidget->addWidget(pushButton_openBreak, 1, 4, 1, 1);

        UberCalculator->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(UberCalculator);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 390, 26));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        infoMenu = new QMenu(menuBar);
        infoMenu->setObjectName(QStringLiteral("infoMenu"));
        UberCalculator->setMenuBar(menuBar);
        statusBar = new QStatusBar(UberCalculator);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        UberCalculator->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(infoMenu->menuAction());
        menu->addAction(exitButton);
        infoMenu->addAction(infoButton);

        retranslateUi(UberCalculator);

        QMetaObject::connectSlotsByName(UberCalculator);
    } // setupUi

    void retranslateUi(QMainWindow *UberCalculator)
    {
        UberCalculator->setWindowTitle(QApplication::translate("UberCalculator", "UberCalculator", 0));
        exitButton->setText(QApplication::translate("UberCalculator", "\320\222\321\213\321\205\320\276\320\264", 0));
        infoButton->setText(QApplication::translate("UberCalculator", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", 0));
        pushButton_addition->setText(QApplication::translate("UberCalculator", "+", 0));
        pushButton_multiplication->setText(QApplication::translate("UberCalculator", "*", 0));
        pushButton_division->setText(QApplication::translate("UberCalculator", "/", 0));
        pushButton_result->setText(QApplication::translate("UberCalculator", "=", 0));
        pushButton_numeric2->setText(QApplication::translate("UberCalculator", "2", 0));
        pushButton_numeric9->setText(QApplication::translate("UberCalculator", "9", 0));
        pushButton_numeric6->setText(QApplication::translate("UberCalculator", "6", 0));
        pushButton_numeric3->setText(QApplication::translate("UberCalculator", "3", 0));
        pushButton_numeric5->setText(QApplication::translate("UberCalculator", "5", 0));
        pushButton_numeric0->setText(QApplication::translate("UberCalculator", "0", 0));
        expressionPanel->setText(QApplication::translate("UberCalculator", "777", 0));
        pushButton_subtraction->setText(QApplication::translate("UberCalculator", "-", 0));
        pushButton_numeric4->setText(QApplication::translate("UberCalculator", "4", 0));
        pushButton_numeric1->setText(QApplication::translate("UberCalculator", "1", 0));
        pushButton_dot->setText(QApplication::translate("UberCalculator", ".", 0));
        pushButton_numeric8->setText(QApplication::translate("UberCalculator", "8", 0));
        pushButton_numeric7->setText(QApplication::translate("UberCalculator", "7", 0));
        pushButton_closeBreak->setText(QApplication::translate("UberCalculator", ")", 0));
        pushButton_deleteAll->setText(QApplication::translate("UberCalculator", "\320\241", 0));
        pushButton_deleteLast->setText(QApplication::translate("UberCalculator", "<-", 0));
        pushButton_openBreak->setText(QApplication::translate("UberCalculator", "(", 0));
        menu->setTitle(QApplication::translate("UberCalculator", "\320\234\320\265\320\275\321\216", 0));
        infoMenu->setTitle(QApplication::translate("UberCalculator", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", 0));
    } // retranslateUi

};

namespace Ui {
    class UberCalculator: public Ui_UberCalculator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UBERCALCULATOR_H
