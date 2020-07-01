#include "chat.h"
#include "ui_chat.h"

Chat::Chat(QTcpSocket *c,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Chat)
{
    this->client=c;
    ui->setupUi(this);
    connect(ui->pushButton,&QPushButton::clicked,this,&Chat::on_pushButton_2_clicked);
    connect(ui->cancelpushButton,&QPushButton::clicked,this,&Chat::on_cancelpushButton_clicked);
}

Chat::~Chat()
{
    delete ui;
}
void Chat::on_cancelpushButton_clicked()  //取消
{
    this->close();
}

void Chat::on_pushButton_2_clicked()  //确定
{
    QByteArray data;
//    data.append(ui->mainLineEdit->text());
    QString a="01 "+ui->mainLineEdit->text();
    data=a.toUtf8();
    client->write(data);
}
