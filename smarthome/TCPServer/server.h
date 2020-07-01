#ifndef SERVER_H
#define SERVER_H

#include <QMainWindow>
#include <QTcpServer>
#include <QHostAddress>
#include <QTcpSocket>
#include <string.h>
#include <QSqlDatabase>
#include <QsqlQuery>
namespace Ui {
class Server;
}

class Server : public QMainWindow
{
    Q_OBJECT

public:
    explicit Server(QWidget *parent = nullptr);
    ~Server();
    bool loginData(QString a,QString b);
    bool registerData(QString a,QString b,QString c);
private slots:
    void newCon();
    void analyze();
private:
    Ui::Server *ui;
    QTcpServer *server;
};

#endif // SERVER_H
