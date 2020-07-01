#ifndef CHAT_H
#define CHAT_H

#include <QDialog>
#include <QTcpSocket>
#include <QString>
namespace Ui {
class Chat;
}
class test{
public:
    QString s;
    int type;
};

class Chat : public QDialog
{
    Q_OBJECT

public:
    explicit Chat(QTcpSocket *c,QWidget *parent = nullptr);
    ~Chat();
private slots:
    void on_cancelpushButton_clicked();//取消

    void on_pushButton_2_clicked(); //确定
private:
    Ui::Chat *ui;
    QTcpSocket *client;
};

#endif // CHAT_H
