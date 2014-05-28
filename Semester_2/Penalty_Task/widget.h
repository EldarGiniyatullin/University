#pragma once

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


    /**
     * @brief showUserBar собирает рабочую панель
     */
    void showUserBar();

    /**
     * @brief buildButton собирает кнопку-пользователя
     */
    void buildButton();

    /**
     * @brief buildPersonDataFromButton - построение данных при их запросе с кнопки-пользователя
     */
    void buildPersonDataFromButton();

    void parseData();

    /**
     * @brief parseCurrent парсит данные пользователя из списка
     */
    void parseCurrent();

    /**
     * @brief buildDataAfterButtonPressure - потроение данных при нажатии кнопки "Show"
     */
    void buildDataAfterButtonPressure();


private:

    QGridLayout *personsLayout;
    QNetworkAccessManager *manager;
    QWebView *view;

    int tempPosition;
    QNetworkReply *reply;

    QString userToShow;

    /**
     * @brief numberOfPersons - количество пользователей в списке (github дает не более 30)
     */
    int numberOfPersons;
    int squareSize;

    QStringList follow = (QStringList() << "followers" << "following");
    QString userLogin;


    QJsonDocument jsonDoc;

    QByteArray imageData;

    int iter;

    QComboBox *folderType;
    QLineEdit *personNameLineEdit;
    QGridLayout *tempLayout;
    QPushButton *actionButton;

    /**
     * @brief buildPersonData - единый метод построения данных
     * @param person - ник пользователя
     * @param action - followers или following
     */
    void buildPersonData(QString person, QString action);

    /**
     * @brief buildFolderType - строит QComboBox с выбором папки
     */
    QComboBox *buildFolderType();
};

