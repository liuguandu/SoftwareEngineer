#include "seeksql.h"

SeekSql::SeekSql()      //此类和数据库操作有关
{

}
void SeekSql::initsql() //初始化，连接数据库
{
    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("123456");
    db.setDatabaseName("smarthome");
    if(db.open())
    {
        qDebug()<<"Database connected successfully!";
        return;
    }
    else
    {
        qDebug()<<"Database connected failed!";
        return;
    }
}
bool SeekSql::loguser(QString name, QString passward)   //登录，首先查找用户名和密码是否在数据库中，若在返回true，否则false
{
    QString str=QString("select * from user where number='%1' and password='%2'").arg(name).arg(passward);
    query=new QSqlQuery;
    query->exec(str);   //进行数据库查询

    query->last();
    int record=query->at()+1;//这两行就是判断返回的查询结果是否为真

    if(record==0)       //如果没找到
        return false;
    return true;
}
bool SeekSql::signup(QString name,QString passward,QString pression)    //登录，首先查找用户名是否在数据库中，若不在。则插入到数据库中。
{
    QString str=QString("select * from user where number='%1'").arg(name);
    qDebug()<<str;
    query=new QSqlQuery;
    query->exec(str);

    query->last();
    int record=query->at()+1;

    if(record!=0)
        return false;
    str=QString("insert into user values('%1','%2',%3)").arg(name).arg(passward).arg(pression.toInt());
//    qDebug()<<str<<endl;
    bool ret=query->exec(str);      //往数据库新添数据

    return ret;
}
