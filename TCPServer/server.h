#ifndef SERVER_H
#define SERVER_H

#include <QMainWindow>
#include <QTcpServer>
#include <QHostAddress>
#include <QTcpSocket>

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

private slots:
    void newCon();
    void dealData();
private:
    Ui::Server *ui;
    QTcpServer *server;
};

#endif // SERVER_H
