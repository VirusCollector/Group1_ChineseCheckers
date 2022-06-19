/********************************************************************************
** Form generated from reading UI file 'connect.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECT_H
#define UI_CONNECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Connect
{
public:
    QLabel *label;
    QTextEdit *IP;
    QLabel *label_2;
    QTextEdit *port;
    QPushButton *pushButton;

    void setupUi(QWidget *Connect)
    {
        if (Connect->objectName().isEmpty())
            Connect->setObjectName(QString::fromUtf8("Connect"));
        Connect->resize(377, 260);
        label = new QLabel(Connect);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 50, 91, 51));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        IP = new QTextEdit(Connect);
        IP->setObjectName(QString::fromUtf8("IP"));
        IP->setGeometry(QRect(160, 60, 151, 31));
        label_2 = new QLabel(Connect);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 120, 91, 51));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);
        port = new QTextEdit(Connect);
        port->setObjectName(QString::fromUtf8("port"));
        port->setGeometry(QRect(160, 130, 151, 31));
        pushButton = new QPushButton(Connect);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(120, 180, 131, 61));
        QFont font1;
        font1.setPointSize(14);
        pushButton->setFont(font1);

        retranslateUi(Connect);

        QMetaObject::connectSlotsByName(Connect);
    } // setupUi

    void retranslateUi(QWidget *Connect)
    {
        Connect->setWindowTitle(QCoreApplication::translate("Connect", "Form", nullptr));
        label->setText(QCoreApplication::translate("Connect", "IP\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("Connect", "\347\253\257\345\217\243\357\274\232", nullptr));
        pushButton->setText(QCoreApplication::translate("Connect", "\350\277\236\346\216\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Connect: public Ui_Connect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECT_H
