/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label;
    QPushButton *startplay;
    QPushButton *pushButton;
    QLabel *Round;
    QLabel *Round_num;
    QLabel *Round_2;
    QLabel *player;
    QLCDNumber *timer;
    QPushButton *AI;
    QPushButton *show_last;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(917, 650);
        Widget->setMinimumSize(QSize(917, 650));
        Widget->setMaximumSize(QSize(917, 650));
        Widget->setAutoFillBackground(false);
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(6, 6, 917, 650));
        label->setMinimumSize(QSize(917, 650));
        label->setMaximumSize(QSize(917, 650));
        label->setAutoFillBackground(false);
        label->setTextFormat(Qt::MarkdownText);
        label->setPixmap(QPixmap(QString::fromUtf8(":/images/pictures/board.jpg")));
        label->setScaledContents(true);
        label->setWordWrap(false);
        startplay = new QPushButton(Widget);
        startplay->setObjectName(QString::fromUtf8("startplay"));
        startplay->setGeometry(QRect(710, 560, 201, 121));
        startplay->setStyleSheet(QString::fromUtf8("border-image: url(:/images/pictures/Start1.png);"));
        startplay->setFlat(true);
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 20, 51, 51));
        pushButton->setStyleSheet(QString::fromUtf8("border-image: url(:/images/pictures/setting.jpeg);"));
        pushButton->setFlat(true);
        Round = new QLabel(Widget);
        Round->setObjectName(QString::fromUtf8("Round"));
        Round->setGeometry(QRect(90, 20, 111, 51));
        QFont font;
        font.setPointSize(26);
        Round->setFont(font);
        Round->setStyleSheet(QString::fromUtf8(""));
        Round->setAlignment(Qt::AlignCenter);
        Round_num = new QLabel(Widget);
        Round_num->setObjectName(QString::fromUtf8("Round_num"));
        Round_num->setGeometry(QRect(220, 20, 61, 51));
        QFont font1;
        font1.setPointSize(22);
        font1.setBold(true);
        Round_num->setFont(font1);
        Round_num->setStyleSheet(QString::fromUtf8(""));
        Round_num->setAlignment(Qt::AlignCenter);
        Round_2 = new QLabel(Widget);
        Round_2->setObjectName(QString::fromUtf8("Round_2"));
        Round_2->setGeometry(QRect(94, 80, 121, 51));
        QFont font2;
        font2.setPointSize(20);
        Round_2->setFont(font2);
        Round_2->setAlignment(Qt::AlignCenter);
        player = new QLabel(Widget);
        player->setObjectName(QString::fromUtf8("player"));
        player->setGeometry(QRect(220, 80, 61, 51));
        QFont font3;
        font3.setPointSize(22);
        player->setFont(font3);
        player->setStyleSheet(QString::fromUtf8("color: rgb(0, 85, 255);"));
        player->setAlignment(Qt::AlignCenter);
        timer = new QLCDNumber(Widget);
        timer->setObjectName(QString::fromUtf8("timer"));
        timer->setGeometry(QRect(610, 20, 71, 51));
        timer->setFont(font1);
        AI = new QPushButton(Widget);
        AI->setObjectName(QString::fromUtf8("AI"));
        AI->setGeometry(QRect(590, 600, 101, 41));
        QFont font4;
        font4.setPointSize(18);
        AI->setFont(font4);
        AI->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 85, 0);"));
        show_last = new QPushButton(Widget);
        show_last->setObjectName(QString::fromUtf8("show_last"));
        show_last->setGeometry(QRect(560, 80, 121, 41));
        QFont font5;
        font5.setPointSize(16);
        show_last->setFont(font5);
        show_last->setAutoFillBackground(false);
        show_last->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 170, 0);"));
        show_last->setFlat(false);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QString());
        startplay->setText(QString());
        pushButton->setText(QString());
        Round->setText(QCoreApplication::translate("Widget", "Steps:", nullptr));
        Round_num->setText(QCoreApplication::translate("Widget", "0", nullptr));
        Round_2->setText(QCoreApplication::translate("Widget", "\350\241\214\346\243\213\346\226\271\357\274\232", nullptr));
        player->setText(QString());
        AI->setText(QCoreApplication::translate("Widget", "\346\211\223\345\274\200\346\211\230\347\256\241", nullptr));
        show_last->setText(QCoreApplication::translate("Widget", "\346\237\245\347\234\213\344\270\212\344\270\200\346\255\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
