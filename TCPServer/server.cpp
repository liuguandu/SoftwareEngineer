#include "server.h"
#include "ui_server.h"
#include<iostream>
using namespace std;
Server::Server(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Server)
{
    ui->setupUi(this);
    server=new QTcpServer;
    server ->listen(QHostAddress::AnyIPv4,8888);
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
//    db.setHostName("localhost");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("ncdb");       //这里输入你的数据库名
    db.setUserName("root");
    db.setPassword("123456");
    if (!db.open())
    {
       cout<<"error"<<endl;
    }
    QSqlQuery query;
    query.exec("select *from user");
//    cout<<"LL"<<endl;
    while (query.next())
    {
        QString country = query.value(1).toString();
        qDebug()<<country;
    }
    connect(server,&QTcpServer::newConnection,this,&Server::newCon);
}
void Server::newCon()
{
    QTcpSocket *socket=server->nextPendingConnection(); //创建socket连接
    QHostAddress clientAddress =socket->peerAddress();
    quint16 clientPort=socket->peerPort();

    ui->addressLineEdit->setText(clientAddress.toString());
    ui->portLineEdit->setText(QString::number(clientPort));

    connect(socket,&QTcpSocket::readyRead,this,&Server::dealData);

}
void Server::dealData()
{
    QTcpSocket *socket=(QTcpSocket *)sender(); //获取信号的发出者


    ui->textEdit->setText(QString(socket->readAll()));
}
Server::~Server()
{
    delete ui;
}
