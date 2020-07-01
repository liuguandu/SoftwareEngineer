#include "server.h"
#include "ui_server.h"
#include "seeksql.h"
#include<iostream>
using namespace std;
Server::Server(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Server)
{
    ui->setupUi(this);
    server=new QTcpServer;
    server ->listen(QHostAddress::AnyIPv4,8888);
    connect(server,&QTcpServer::newConnection,this,&Server::newCon);
}
void Server::newCon()       //建立起新的连接
{
    QTcpSocket *socket=server->nextPendingConnection(); //创建socket连接
    QHostAddress clientAddress =socket->peerAddress();
    quint16 clientPort=socket->peerPort();
    ui->addressLineEdit->setText(clientAddress.toString());
    ui->portLineEdit->setText(QString::number(clientPort));
    connect(socket,&QTcpSocket::readyRead,this,&Server::analyze);   //当socket中有数时，跳转到槽analyse

}
void Server::analyze()
{

    QTcpSocket *socket1=(QTcpSocket *)sender(); //获取信号的发出者
    QString a=QString(socket1->readAll());
    QStringList b;
    b=a.split(" ");
    bool ret=0;
    if(b[0]=="01")                              //分解从socket中得到的字节，以空格分隔
        ret=loginData(b[1],b[2]);               //首位"01"代表登录功能，"02"代表注册功能
    else if(b[0]=="02")                         //根据不同功能跳转到对应的函数进行处理
        ret=registerData(b[1],b[2],b[3]);
    else {
        return;
    }
    QString sendData=b[0];
    if(ret)
        //加上空格表示分隔
        sendData+=" true";                      //根据功能是否执行成功，来组装字节传给客户端
    else
        sendData+=" false";
        qDebug()<<sendData<<endl;
        socket1->write(sendData.toLatin1());
}
bool Server::registerData(QString a,QString b,QString c)    //注册
{
    SeekSql *s=new SeekSql();
    s->initsql();                       //切记，在使用seekSql方法时，一定要先初始化。
    bool ret = s->signup(a,b,c);        //调用seekSql中的方法查找数据库
    ui->textEdit->setText(b);
    return ret;
}
bool Server::loginData(QString a,QString b)     //登录
{
    SeekSql *s=new SeekSql();
    s->initsql();
    bool ret = s->loguser(a,b);         //调用seekSql中的方法查找数据库
    ui->textEdit->setText(b);
    qDebug()<<ret<<endl;
    return ret;
}
Server::~Server()
{
    delete ui;
}

//一些算法，便遍历整个数据库
//        while (query.next())
//        {
//            QString country = query.value(0).toString();
//            qDebug()<<country;
//        }
//        query.last();
//        int record=query.at()+1;
