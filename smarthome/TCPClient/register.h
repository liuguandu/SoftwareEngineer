#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>
#include <QTcpSocket>
#include <QString>
#include <QMessageBox>
namespace Ui {
class Register;
}

class Register : public QDialog
{
    Q_OBJECT

public:
    explicit Register(QTcpSocket *c, QWidget *parent = nullptr);
    ~Register();
private slots:
    void on_confirm_clicked();
    void on_cancel_clicked();
private:
    Ui::Register *ui;
    QTcpSocket *client;
};

#endif // REGISTER_H
