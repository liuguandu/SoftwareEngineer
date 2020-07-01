#ifndef CLIENT_H
#define CLIENT_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QHostAddress>
#include <QMessageBox>

namespace Ui {
class Client;
}

class Client : public QMainWindow
{
    Q_OBJECT

public:
    explicit Client(QWidget *parent = nullptr);
    ~Client();
private slots:
    void on_cancelButton_2_clicked();
    void on_loginButton_clicked();
    void on_register_clicked();
    void readMessage();

private:
    Ui::Client *ui;
    QTcpSocket *client;
};

#endif // CLIENT_H
