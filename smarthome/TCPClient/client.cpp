#include "client.h"
#include "ui_client.h"
#include "Register.h"
#include<iostream>
using namespace std;
Client::Client(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Client)
{
    ui->setupUi(this);
    client =new QTcpSocket;
    QHostAddress serverAddress("127.0.0.1");
    quint16 serverPort=8888;
    client->connectToHost(serverAddress,serverPort);
    connect(ui->pushButton,&QPushButton::clicked,this,&Client::on_loginButton_clicked);
    connect(ui->cancelpushButton,&QPushButton::clicked,this,&Client::on_cancelButton_2_clicked);
    connect(ui->registerpushButton,&QPushButton::clicked,this,&Client::on_register_clicked);
    connect(client,&QTcpSocket::connected,
                [this]()
        {
            QMessageBox::information(this,"连接提示","连接成功");
        });
    connect(client,SIGNAL(readyRead()),this,SLOT(readMessage()));       //同样检测套接口中的数据，转到readMessage()


}

Client::~Client()
{
    delete ui;
}
void Client::on_cancelButton_2_clicked()  //取消
{
    this->close();
}
void Client::readMessage()      //获取套接口中的数据
{
    cout<<"LL"<<endl;
    QString data=client->readAll();
    QStringList list=data.split(" ");       //进行命令拆分
    if(list[0]=="02" && list[1]=="true")    //这时获取的组装字是从服务器端传过来的，服务器组装的内容有操作功能list[0]，操作是否成功list[1]
    {
        QMessageBox::information(this,"信息提示","注册成功!",QMessageBox::Ok);
        //跳转至个人界面
    }
    else if(list[0]=="02" && list[1]=="false")
        QMessageBox::information(this,"信息提示","注册失败,用户名已经被注册!",QMessageBox::Ok);
    else if(list[0]=="01" && list[1]=="true")
    {
        QMessageBox::information(this,"信息提示","登录成功!",QMessageBox::Ok);
        //跳转至个人界面
    }
    else if(list[0]=="01" && list[1]=="false")
        QMessageBox::information(this,"信息提示","登录失败,用户名或密码错误!",QMessageBox::Ok);
    else
        return;

}
void Client::on_register_clicked()
{
    Register *r=new Register(client);
    r->show();
}

void Client::on_loginButton_clicked()   //登陆
{
    QByteArray data;                    //同理，组装命令字，以空格分开，送往服务器端
    QString a="01 "+ui->nameLineEdit->text()+" "+ui->passwordLineEdit->text();
    data=a.toUtf8();
    client->write(data);
}

