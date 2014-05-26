#include "bashrss.h"
#include "ui_bashrss.h"

BashRSS::BashRSS(QWidget *parent) :
    QWidget(parent), number(1)
{

    ratingLineEdit = new QLineEdit(this);
    ratingLineEdit->setReadOnly(true);
    idLineEdit = new QLineEdit(this);
    idLineEdit->setReadOnly(true);

    nextButton = new QPushButton("Next", this);
    rulezButton = new QPushButton("+", this);
    suxButton = new QPushButton("-", this);
    ratingLabel = new QLabel(tr("Rating"));
    bayanButton = new QPushButton("[:||||:]");
    bashTextEdit = new QTextEdit(this);
    bashTextEdit->clear();
    bashTextEdit->setReadOnly(true);

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(rulezButton, 0, 0);
    mainLayout->addWidget(bayanButton, 0, 1);
    mainLayout->addWidget(suxButton, 0, 2);
    mainLayout->addWidget(nextButton, 2, 0);
    mainLayout->addWidget(ratingLabel, 1, 0);
    mainLayout->addWidget(ratingLineEdit, 1, 1);
    mainLayout->addWidget(idLineEdit, 1, 2);
    mainLayout->addWidget(bashTextEdit, 0, 3, 4, 3);
    setLayout(mainLayout);


    view = new QWebView();
    view->load(QUrl("http://bash.im/random"));

    connect(view, SIGNAL(loadFinished(bool)), this, SLOT(proccessReply()));
    connect(nextButton, SIGNAL(clicked(bool)), this, SLOT(readNext()));
    connect(rulezButton, SIGNAL(clicked()), this, SLOT(rulezPressed()));
    connect(bayanButton, SIGNAL(clicked()), this, SLOT(bayanPressed()));
    connect(suxButton, SIGNAL(clicked()), this, SLOT(suxPressed()));
}


void BashRSS::readBash()
{
    nextButton->setEnabled(false);
    enableDisableButtons(false);
    QWebElement bashText = commonWidget.findFirst("div[class=text]");
    QWebElement ratingValue = commonWidget.findFirst("span[class=rating]");
    QWebElement idValue = commonWidget.findFirst("a[class=id]");
    bashTextEdit->clear();
    bashTextEdit->textCursor().insertText(bashText.toPlainText());
    ratingLineEdit->clear();
    ratingLineEdit->setText(ratingValue.toPlainText());
    idLineEdit->clear();
    idLineEdit->setText(idValue.toPlainText());
    if (ratingLineEdit->text() == "")
    {
        enableDisableButtons(false);
    }
    else
        enableDisableButtons(true);
    nextButton->setEnabled(true);
}

void BashRSS::readNext()
{
    commonWidget = commonWidget.nextSibling();
    if (!commonWidget.isNull())
        readBash();
}

void BashRSS::rulezPressed()
{
    enableDisableButtons(false);
    QString tmp = commonWidget.findFirst("a[class=id]").toPlainText();
    tmp.remove(0, 1);
    //отправка запроса
    tempView = new QWebView;
    tempView->load(QUrl("http://bash.im/quote/" + tmp));
    nextButton->setEnabled(false);
    connect(tempView, SIGNAL(loadFinished(bool)), this, SLOT(refreshRating()));
    enableDisableButtons(true);
}

void BashRSS::bayanPressed()
{
    enableDisableButtons(false);
    QString tmp = commonWidget.findFirst("a[class=id]").toPlainText();
    tmp.remove(0, 1);
    //отправка запроса
    tempView = new QWebView;
    tempView->load(QUrl("http://bash.im/quote/" + tmp));
    nextButton->setEnabled(false);
    connect(tempView, SIGNAL(loadFinished(bool)), this, SLOT(refreshRating()));
    enableDisableButtons(true);
}

void BashRSS::suxPressed()
{
    enableDisableButtons(false);
    QString tmp = commonWidget.findFirst("a[class=id]").toPlainText();
    tmp.remove(0, 1);
    //отправка запроса
    tempView = new QWebView;
    tempView->load(QUrl("http://bash.im/quote/" + tmp));
    nextButton->setEnabled(false);
    connect(tempView, SIGNAL(loadFinished(bool)), this, SLOT(refreshRating()));
    enableDisableButtons(true);
}

void BashRSS::refreshRating()
{
    tempWidget = tempView->page()->mainFrame()->findFirstElement("span[class=rating]");
    ratingLineEdit->clear();
    ratingLineEdit->setText(tempWidget.toPlainText());
    nextButton->setEnabled(true);
}

void BashRSS::enableDisableButtons(bool enable)
{
    bayanButton->setEnabled(enable);
    rulezButton->setEnabled(enable);
    suxButton->setEnabled(enable);
}

void BashRSS::proccessReply()
{
    collection = view->page()->mainFrame()->findAllElements("div[class=quote]");
    commonWidget = view->page()->mainFrame()->findFirstElement("div[class=quote]");
    readBash();
}

