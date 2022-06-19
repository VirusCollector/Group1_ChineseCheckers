/********************************************************************************
** Form generated from reading UI file 'startpage.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTPAGE_H
#define UI_STARTPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StartPage
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_2;

    void setupUi(QWidget *StartPage)
    {
        if (StartPage->objectName().isEmpty())
            StartPage->setObjectName(QString::fromUtf8("StartPage"));
        StartPage->resize(640, 427);
        label = new QLabel(StartPage);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 691, 481));
        label->setMinimumSize(QSize(691, 481));
        label->setMaximumSize(QSize(691, 481));
        label->setStyleSheet(QString::fromUtf8("background-image: url(:/images/pictures/landscape-ge31a3ab68_640.jpg);"));
        pushButton = new QPushButton(StartPage);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(90, 110, 201, 91));
        QFont font;
        font.setPointSize(24);
        pushButton->setFont(font);
        pushButton->setFlat(true);
        pushButton_2 = new QPushButton(StartPage);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(350, 110, 201, 91));
        pushButton_2->setFont(font);
        pushButton_2->setFlat(true);
        label_2 = new QLabel(StartPage);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(110, 10, 401, 71));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        retranslateUi(StartPage);

        QMetaObject::connectSlotsByName(StartPage);
    } // setupUi

    void retranslateUi(QWidget *StartPage)
    {
        StartPage->setWindowTitle(QCoreApplication::translate("StartPage", "Form", nullptr));
        label->setText(QString());
        pushButton->setText(QCoreApplication::translate("StartPage", "Server", nullptr));
        pushButton_2->setText(QCoreApplication::translate("StartPage", "Client", nullptr));
        label_2->setText(QCoreApplication::translate("StartPage", "\350\257\267\351\200\211\346\213\251\350\277\233\345\205\245\347\232\204\346\250\241\345\274\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StartPage: public Ui_StartPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTPAGE_H
