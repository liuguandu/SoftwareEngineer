/********************************************************************************
** Form generated from reading UI file 'chat.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHAT_H
#define UI_CHAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Chat
{
public:
    QPushButton *pushButton;
    QPushButton *cancelpushButton;
    QLineEdit *mainLineEdit;

    void setupUi(QDialog *Chat)
    {
        if (Chat->objectName().isEmpty())
            Chat->setObjectName(QString::fromUtf8("Chat"));
        Chat->resize(538, 428);
        pushButton = new QPushButton(Chat);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(110, 270, 111, 51));
        cancelpushButton = new QPushButton(Chat);
        cancelpushButton->setObjectName(QString::fromUtf8("cancelpushButton"));
        cancelpushButton->setGeometry(QRect(310, 270, 111, 51));
        mainLineEdit = new QLineEdit(Chat);
        mainLineEdit->setObjectName(QString::fromUtf8("mainLineEdit"));
        mainLineEdit->setGeometry(QRect(130, 160, 281, 31));

        retranslateUi(Chat);

        QMetaObject::connectSlotsByName(Chat);
    } // setupUi

    void retranslateUi(QDialog *Chat)
    {
        Chat->setWindowTitle(QApplication::translate("Chat", "Dialog", nullptr));
        pushButton->setText(QApplication::translate("Chat", "\347\241\256\350\256\244", nullptr));
        cancelpushButton->setText(QApplication::translate("Chat", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Chat: public Ui_Chat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAT_H
