#pragma once

#include <QWidget>
#include <QObject>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QTextCodec>
#include <QtWebKit/QWebElement>
#include <QWebFrame>
#include <QWebPage>
#include <QWebView>
#include <QDomDocument>
#include <QDebug>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QLayout>
#include <QTextEdit>

class BashRSS : public QWidget
{
    Q_OBJECT

public:
    explicit BashRSS(QWidget *parent = 0);

private:


public slots:

    void proccessReply();

    void readNext();

    void rulezPressed();

    void bayanPressed();

    void suxPressed();

    void refreshRating();

private:

    QTextEdit *bashTextEdit;
    QPushButton *nextButton;
    QLineEdit *ratingLineEdit;
    QLineEdit *idLineEdit;
    QPushButton *suxButton;
    QPushButton *rulezButton;
    QPushButton *bayanButton;
    QLabel *ratingLabel;
    QWebView *view;
    QWebElementCollection collection;
    QWebElement commonWidget;
    QWebElement tempWidget;
    QWebView *tempView;
    int number;


    void enableDisableButtons(bool enable);
    void readBash();
};
