#include "widget.h"
#include "ui_widget.h"
#include <QTimer>

Widget::Widget(QWidget *parent) :
    QWidget(parent), tempPosition(0),
    personsLayout(new QGridLayout), numberOfPersons(0), squareSize(0), userToShow("EldarGiniyatullin"), manager(new QNetworkAccessManager), userLogin(""),
    iter(0), userNameArray(new QString[1])
{
    buildPersonData(userToShow, follow[0]);
}


void Widget::showUserBar()
{
    actionButton = new QPushButton("Show", this);
    personsLayout->addWidget(actionButton, 0, 2);
    connect(actionButton, SIGNAL(clicked()), this, SLOT(buildDataAfterButtonPressure()));
    personNameLineEdit = new QLineEdit(this);
    personsLayout->addWidget(personNameLineEdit, 1, 0, 1, 5);
    folderType = buildFolderType();
    personsLayout->addWidget(folderType, 0, 0);
    parseData();
}

void Widget::buildButton()
{
    QNetworkReply *tempReply = dynamic_cast<QNetworkReply *>(sender());
    imageData = tempReply->readAll();
    QPixmap image;
    image.loadFromData(imageData);
    image.scaled(20, 20);
    QString tmp = userLogin;
    QPushButton *personButton = new QPushButton(tmp);
    personButton->setFixedHeight(50);
    personButton->setFixedWidth(150);

    personButton->setIcon(QIcon(image));
    personButton->setIconSize(personButton->size());

    personsLayout->addWidget(personButton, 2 + (tempPosition) / squareSize, (tempPosition) % squareSize);
    tempPosition++;
    connect(personButton, SIGNAL(clicked()), this, SLOT(buildPersonDataFromButton()));
}

void Widget::buildPersonDataFromButton()
{
    QPushButton *button = static_cast<QPushButton*>(sender());
    QString person = button->text();
    buildPersonData(person, follow[0]);
}

void Widget::buildPersonData(QString person, QString action)
{
    QString tmp = "https://api.github.com/users/" + person + "/" + action;
    QLayoutItem* item;
    while ((item = personsLayout->takeAt(0)) != NULL )
    {
        delete item->widget();
        delete item;
    }
    reply = manager->get(QNetworkRequest(QUrl(tmp)));
    connect(reply, SIGNAL(finished()), this, SLOT(showUserBar()));
}

QComboBox *Widget::buildFolderType()
{
    QComboBox *comboBox = new QComboBox(this);
    comboBox->addItems(follow);
    connect(comboBox, SIGNAL(activated(follow[0])), this, SLOT(buildPersonDataFollowers()));
    connect(comboBox, SIGNAL(activated(follow[1])), this, SLOT(buildPersonDataFollowing()));
    return comboBox;
}

void Widget::parseData()
{
    iter = -1;
    QByteArray dataToParse = reply->readAll();
    QJsonParseError parseError;
    jsonDoc = QJsonDocument::fromJson(dataToParse, &parseError);
    if (parseError.error == QJsonParseError::NoError)
    {
        numberOfPersons = jsonDoc.array().size();
        squareSize = static_cast<int>(round(sqrt(static_cast<double>(numberOfPersons))));
        delete[] userNameArray;
        userNameArray = new QString[numberOfPersons];
        parseCurrent();
        setLayout(personsLayout);
    }
    else
    {
        qDebug() << parseError.errorString();
    }
    tempPosition = 0;

}

void Widget::parseCurrent()
{
        iter++;
        if (iter < jsonDoc.array().size())
        {
            userLogin = jsonDoc.array().at(iter).toObject()["login"].toString();
            QString userImageURL = jsonDoc.array().at(iter).toObject()["avatar_url"].toString();
            reply = manager->get(QNetworkRequest(QUrl(userImageURL)));
            connect(reply, SIGNAL(finished()), this, SLOT(buildButton()));
            connect(reply, SIGNAL(finished()), this, SLOT(parseCurrent()));
        }
}

void Widget::buildDataAfterButtonPressure()
{
    if (personNameLineEdit->text() == "")
//        userToShow = "EldarGiniyatullin";
        return;
    userToShow = personNameLineEdit->text();
    if (folderType->currentText() == follow[0])
    {
        buildPersonData(userToShow, follow[0]);
    }

    else if (folderType->currentText() == follow[1])
    {
        buildPersonData(userToShow, follow[1]);
    }

}
