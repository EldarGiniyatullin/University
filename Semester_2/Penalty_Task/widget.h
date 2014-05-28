#ifndef WIDGET_H
#define WIDGET_H


#include <QCoreApplication>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QNetworkReply>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QLabel>
#include <QPixmap>
#include <QJsonParseError>
#include <QPixmap>
#include <QGridLayout>
#include <QPushButton>
#include <math.h>
#include <QAbstractButton>
#include <QComboBox>
#include <QLineEdit>


#include <QWidget>
#include <QWebView>


class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);

private slots:


    void showUserBar();

    void buildButton();

    void buildPersonDataFromButton();

    void parseData();

    void parseCurrent();

//    void buildPersonDataFollowing();

//    void buildPersonDataFollowers();

    void buildDataAfterButtonPressure();


private:

    QLabel statusLabel;


    QNetworkAccessManager *manager;
    QWebView *view;

    QGridLayout *personsLayout;
    int tempPosition;
    QNetworkReply *reply;

    QString userToShow;

    int numberOfPersons;
    int squareSize;
    QStringList follow = (QStringList() << "followers" << "following");
    QString userLogin;

    void buildPersonData(QString person, QString action);

    QJsonDocument jsonDoc;

    QByteArray imageData;

    int iter;

    QComboBox *buildFolderType();

    void doLater();

    QComboBox *folderType;

    QString *userNameArray;

    QLineEdit *personNameLineEdit;

    QGridLayout *tempLayout;

    QPushButton *actionButton;
};



#endif // WIDGET_H
