/********************************************************************************
** Form generated from reading UI file 'c_room.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_C_ROOM_H
#define UI_C_ROOM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_c_room
{
public:
    QWidget *centralwidget;
    QCheckBox *checkBox_1;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_6;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *player_1;
    QLabel *player_2;
    QLabel *player_3;
    QLabel *player_6;
    QLabel *player_5;
    QLabel *player_4;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *name_1;
    QLabel *name_2;
    QLabel *name_3;
    QLabel *name_4;
    QLabel *name_5;
    QLabel *name_6;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *c_room)
    {
        if (c_room->objectName().isEmpty())
            c_room->setObjectName(QString::fromUtf8("c_room"));
        c_room->resize(800, 600);
        centralwidget = new QWidget(c_room);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        checkBox_1 = new QCheckBox(centralwidget);
        checkBox_1->setObjectName(QString::fromUtf8("checkBox_1"));
        checkBox_1->setGeometry(QRect(490, 30, 151, 71));
        QFont font;
        font.setPointSize(18);
        checkBox_1->setFont(font);
        checkBox_2 = new QCheckBox(centralwidget);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(490, 100, 151, 71));
        checkBox_2->setFont(font);
        checkBox_3 = new QCheckBox(centralwidget);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setGeometry(QRect(490, 180, 151, 71));
        checkBox_3->setFont(font);
        checkBox_4 = new QCheckBox(centralwidget);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));
        checkBox_4->setGeometry(QRect(490, 250, 151, 71));
        checkBox_4->setFont(font);
        checkBox_5 = new QCheckBox(centralwidget);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));
        checkBox_5->setGeometry(QRect(490, 330, 151, 71));
        checkBox_5->setFont(font);
        checkBox_6 = new QCheckBox(centralwidget);
        checkBox_6->setObjectName(QString::fromUtf8("checkBox_6"));
        checkBox_6->setGeometry(QRect(490, 410, 151, 71));
        checkBox_6->setFont(font);
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(30, 30, 121, 441));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        player_1 = new QLabel(widget);
        player_1->setObjectName(QString::fromUtf8("player_1"));
        QFont font1;
        font1.setPointSize(16);
        player_1->setFont(font1);
        player_1->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(player_1);

        player_2 = new QLabel(widget);
        player_2->setObjectName(QString::fromUtf8("player_2"));
        player_2->setFont(font1);
        player_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(player_2);

        player_3 = new QLabel(widget);
        player_3->setObjectName(QString::fromUtf8("player_3"));
        player_3->setFont(font1);
        player_3->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(player_3);

        player_6 = new QLabel(widget);
        player_6->setObjectName(QString::fromUtf8("player_6"));
        player_6->setFont(font1);
        player_6->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(player_6);

        player_5 = new QLabel(widget);
        player_5->setObjectName(QString::fromUtf8("player_5"));
        player_5->setFont(font1);
        player_5->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(player_5);

        player_4 = new QLabel(widget);
        player_4->setObjectName(QString::fromUtf8("player_4"));
        player_4->setFont(font1);
        player_4->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(player_4);

        widget1 = new QWidget(centralwidget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(190, 30, 261, 441));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        name_1 = new QLabel(widget1);
        name_1->setObjectName(QString::fromUtf8("name_1"));
        name_1->setFont(font1);
        name_1->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(name_1);

        name_2 = new QLabel(widget1);
        name_2->setObjectName(QString::fromUtf8("name_2"));
        name_2->setFont(font1);
        name_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(name_2);

        name_3 = new QLabel(widget1);
        name_3->setObjectName(QString::fromUtf8("name_3"));
        name_3->setFont(font1);
        name_3->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(name_3);

        name_4 = new QLabel(widget1);
        name_4->setObjectName(QString::fromUtf8("name_4"));
        name_4->setFont(font1);
        name_4->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(name_4);

        name_5 = new QLabel(widget1);
        name_5->setObjectName(QString::fromUtf8("name_5"));
        name_5->setFont(font1);
        name_5->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(name_5);

        name_6 = new QLabel(widget1);
        name_6->setObjectName(QString::fromUtf8("name_6"));
        name_6->setFont(font1);
        name_6->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(name_6);

        c_room->setCentralWidget(centralwidget);
        menubar = new QMenuBar(c_room);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 19));
        c_room->setMenuBar(menubar);
        statusbar = new QStatusBar(c_room);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        c_room->setStatusBar(statusbar);

        retranslateUi(c_room);

        QMetaObject::connectSlotsByName(c_room);
    } // setupUi

    void retranslateUi(QMainWindow *c_room)
    {
        c_room->setWindowTitle(QCoreApplication::translate("c_room", "MainWindow", nullptr));
        checkBox_1->setText(QCoreApplication::translate("c_room", "\345\267\262\345\207\206\345\244\207", nullptr));
        checkBox_2->setText(QCoreApplication::translate("c_room", "\345\267\262\345\207\206\345\244\207", nullptr));
        checkBox_3->setText(QCoreApplication::translate("c_room", "\345\267\262\345\207\206\345\244\207", nullptr));
        checkBox_4->setText(QCoreApplication::translate("c_room", "\345\267\262\345\207\206\345\244\207", nullptr));
        checkBox_5->setText(QCoreApplication::translate("c_room", "\345\267\262\345\207\206\345\244\207", nullptr));
        checkBox_6->setText(QCoreApplication::translate("c_room", "\345\267\262\345\207\206\345\244\207", nullptr));
        player_1->setText(QCoreApplication::translate("c_room", "\347\216\251\345\256\2661\357\274\232", nullptr));
        player_2->setText(QCoreApplication::translate("c_room", "\347\216\251\345\256\2662\357\274\232", nullptr));
        player_3->setText(QCoreApplication::translate("c_room", "\347\216\251\345\256\2663\357\274\232", nullptr));
        player_6->setText(QCoreApplication::translate("c_room", "\347\216\251\345\256\2664\357\274\232", nullptr));
        player_5->setText(QCoreApplication::translate("c_room", "\347\216\251\345\256\2665\357\274\232", nullptr));
        player_4->setText(QCoreApplication::translate("c_room", "\347\216\251\345\256\2666\357\274\232", nullptr));
        name_1->setText(QString());
        name_2->setText(QString());
        name_3->setText(QString());
        name_4->setText(QString());
        name_5->setText(QString());
        name_6->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class c_room: public Ui_c_room {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_C_ROOM_H
