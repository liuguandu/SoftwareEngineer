#ifndef SEEKSQL_H
#define SEEKSQL_H
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

class SeekSql
{
public:
    SeekSql();
    void initsql();
    bool loguser(QString name,QString passward);
    bool signup(QString name,QString passward,QString pression);
private:
    QSqlQuery *query;
};

#endif // SEEKSQL_H
