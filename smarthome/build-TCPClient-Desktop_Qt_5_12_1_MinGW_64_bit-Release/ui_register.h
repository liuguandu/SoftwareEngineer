/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Register
{
public:
    QLabel *label;
    QLineEdit *numberlineEdit;
    QLabel *label_2;
    QLineEdit *passwordlineEdit;
    QPushButton *confirmpushButton;
    QPushButton *cancelpushButton;
    QLabel *label_3;
    QLineEdit *plineEdit;

    void setupUi(QDialog *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName(QString::fromUtf8("Register"));
        Register->resize(599, 423);
        label = new QLabel(Register);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(120, 130, 72, 15));
        numberlineEdit = new QLineEdit(Register);
        numberlineEdit->setObjectName(QString::fromUtf8("numberlineEdit"));
        numberlineEdit->setGeometry(QRect(200, 130, 221, 21));
        label_2 = new QLabel(Register);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(120, 190, 72, 15));
        passwordlineEdit = new QLineEdit(Register);
        passwordlineEdit->setObjectName(QString::fromUtf8("passwordlineEdit"));
        passwordlineEdit->setGeometry(QRect(200, 190, 221, 21));
        confirmpushButton = new QPushButton(Register);
        confirmpushButton->setObjectName(QString::fromUtf8("confirmpushButton"));
        confirmpushButton->setGeometry(QRect(150, 300, 111, 41));
        cancelpushButton = new QPushButton(Register);
        cancelpushButton->setObjectName(QString::fromUtf8("cancelpushButton"));
        cancelpushButton->setGeometry(QRect(330, 300, 101, 41));
        label_3 = new QLabel(Register);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(120, 240, 72, 15));
        plineEdit = new QLineEdit(Register);
        plineEdit->setObjectName(QString::fromUtf8("plineEdit"));
        plineEdit->setGeometry(QRect(200, 240, 31, 21));

        retranslateUi(Register);

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QDialog *Register)
    {
        Register->setWindowTitle(QApplication::translate("Register", "Dialog", nullptr));
        label->setText(QApplication::translate("Register", "\346\263\250\345\206\214\350\264\246\345\217\267", nullptr));
        label_2->setText(QApplication::translate("Register", "\345\257\206\347\240\201", nullptr));
        confirmpushButton->setText(QApplication::translate("Register", "\347\241\256\345\256\232", nullptr));
        cancelpushButton->setText(QApplication::translate("Register", "\345\217\226\346\266\210", nullptr));
        label_3->setText(QApplication::translate("Register", "\346\235\203\351\231\220", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
