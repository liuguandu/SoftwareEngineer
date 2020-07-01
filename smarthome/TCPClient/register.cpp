#include "register.h"
#include "ui_register.h"

Register::Register(QTcpSocket *c,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    this->client=c;
    ui->setupUi(this);
    connect(ui->confirmpushButton,&QPushButton::clicked,this,&Register::on_confirm_clicked);
    connect(ui->cancelpushButton,&QPushButton::clicked,this,&Register::on_cancel_clicked);
}

Register::~Register()
{
    delete ui;
}
void Register::on_cancel_clicked()
{
    this->close();
}
void Register::on_confirm_clicked()
{
    QString a,b,c;
    a=ui->numberlineEdit->text();
    b=ui->passwordlineEdit->text();
    c=ui->plineEdit->text();            //获取文本输入
    if(a==""||b==""||c=="")
        QMessageBox::information(this,"错误","用户名或密码不能为空");
    else
    {
        QByteArray data;
        QString s="02 "+a+" "+b+" "+c;      //构建命令字，"02"表示注册，后面为账号，密码，权限等信息，以空格分隔。
        data=s.toUtf8();
        client->write(data);                //写入套接口
    }
    this->close();
}
