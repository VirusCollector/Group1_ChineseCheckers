/********************************************************************************
** Form generated from reading UI file 'room_1.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROOM_1_H
#define UI_ROOM_1_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_room_1
{
public:
    QWidget *centralwidget;
    QLabel *player_1;
    QLabel *player_2;
    QLabel *player_3;
    QLabel *player_4;
    QLabel *player_5;
    QLabel *player_6;
    QLabel *name_1;
    QLabel *name_2;
    QLabel *name_3;
    QLabel *name_4;
    QLabel *name_5;
    QLabel *name_6;
    QCheckBox *checkBox_1;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_6;
    QMenuBar *menubar;
    QMenu *menu_1;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *room_1)
    {
        if (room_1->objectName().isEmpty())
            room_1->setObjectName(QString::fromUtf8("room_1"));
        room_1->resize(583, 461);
        centralwidget = new QWidget(room_1);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        player_1 = new QLabel(centralwidget);
        player_1->setObjectName(QString::fromUtf8("player_1"));
        player_1->setGeometry(QRect(30, 20, 81, 51));
        QFont font;
        font.setPointSize(16);
        player_1->setFont(font);
        player_1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        player_2 = new QLabel(centralwidget);
        player_2->setObjectName(QString::fromUtf8("player_2"));
        player_2->setGeometry(QRect(30, 80, 81, 51));
        player_2->setFont(font);
        player_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        player_3 = new QLabel(centralwidget);
        player_3->setObjectName(QString::fromUtf8("player_3"));
        player_3->setGeometry(QRect(30, 140, 81, 51));
        player_3->setFont(font);
        player_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        player_4 = new QLabel(centralwidget);
        player_4->setObjectName(QString::fromUtf8("player_4"));
        player_4->setGeometry(QRect(30, 200, 81, 51));
        player_4->setFont(font);
        player_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        player_5 = new QLabel(centralwidget);
        player_5->setObjectName(QString::fromUtf8("player_5"));
        player_5->setGeometry(QRect(30, 260, 81, 51));
        player_5->setFont(font);
        player_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        player_6 = new QLabel(centralwidget);
        player_6->setObjectName(QString::fromUtf8("player_6"));
        player_6->setGeometry(QRect(30, 320, 81, 51));
        player_6->setFont(font);
        player_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        name_1 = new QLabel(centralwidget);
        name_1->setObjectName(QString::fromUtf8("name_1"));
        name_1->setGeometry(QRect(150, 20, 171, 51));
        name_1->setFont(font);
        name_1->setAlignment(Qt::AlignCenter);
        name_2 = new QLabel(centralwidget);
        name_2->setObjectName(QString::fromUtf8("name_2"));
        name_2->setGeometry(QRect(150, 80, 171, 51));
        name_2->setFont(font);
        name_2->setAlignment(Qt::AlignCenter);
        name_3 = new QLabel(centralwidget);
        name_3->setObjectName(QString::fromUtf8("name_3"));
        name_3->setGeometry(QRect(150, 140, 171, 51));
        name_3->setFont(font);
        name_3->setAlignment(Qt::AlignCenter);
        name_4 = new QLabel(centralwidget);
        name_4->setObjectName(QString::fromUtf8("name_4"));
        name_4->setGeometry(QRect(150, 200, 171, 51));
        name_4->setFont(font);
        name_4->setAlignment(Qt::AlignCenter);
        name_5 = new QLabel(centralwidget);
        name_5->setObjectName(QString::fromUtf8("name_5"));
        name_5->setGeometry(QRect(150, 260, 171, 51));
        name_5->setFont(font);
        name_5->setAlignment(Qt::AlignCenter);
        name_6 = new QLabel(centralwidget);
        name_6->setObjectName(QString::fromUtf8("name_6"));
        name_6->setGeometry(QRect(150, 320, 171, 51));
        name_6->setFont(font);
        name_6->setAlignment(Qt::AlignCenter);
        checkBox_1 = new QCheckBox(centralwidget);
        checkBox_1->setObjectName(QString::fromUtf8("checkBox_1"));
        checkBox_1->setGeometry(QRect(400, 20, 81, 51));
        checkBox_2 = new QCheckBox(centralwidget);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(400, 80, 81, 51));
        checkBox_3 = new QCheckBox(centralwidget);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setGeometry(QRect(400, 140, 81, 51));
        checkBox_4 = new QCheckBox(centralwidget);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));
        checkBox_4->setGeometry(QRect(400, 200, 81, 51));
        checkBox_5 = new QCheckBox(centralwidget);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));
        checkBox_5->setGeometry(QRect(400, 260, 81, 51));
        checkBox_6 = new QCheckBox(centralwidget);
        checkBox_6->setObjectName(QString::fromUtf8("checkBox_6"));
        checkBox_6->setGeometry(QRect(400, 320, 81, 51));
        room_1->setCentralWidget(centralwidget);
        menubar = new QMenuBar(room_1);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 583, 19));
        menu_1 = new QMenu(menubar);
        menu_1->setObjectName(QString::fromUtf8("menu_1"));
        room_1->setMenuBar(menubar);
        statusbar = new QStatusBar(room_1);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        room_1->setStatusBar(statusbar);

        menubar->addAction(menu_1->menuAction());

        retranslateUi(room_1);

        QMetaObject::connectSlotsByName(room_1);
    } // setupUi

    void retranslateUi(QMainWindow *room_1)
    {
        room_1->setWindowTitle(QCoreApplication::translate("room_1", "MainWindow", nullptr));
        player_1->setText(QCoreApplication::translate("room_1", "\347\216\251\345\256\2661\357\274\232", nullptr));
        player_2->setText(QCoreApplication::translate("room_1", "\347\216\251\345\256\2662\357\274\232", nullptr));
        player_3->setText(QCoreApplication::translate("room_1", "\347\216\251\345\256\2663\357\274\232", nullptr));
        player_4->setText(QCoreApplication::translate("room_1", "\347\216\251\345\256\2664\357\274\232", nullptr));
        player_5->setText(QCoreApplication::translate("room_1", "\347\216\251\345\256\2665\357\274\232", nullptr));
        player_6->setText(QCoreApplication::translate("room_1", "\347\216\251\345\256\2666\357\274\232", nullptr));
        name_1->setText(QString());
        name_2->setText(QString());
        name_3->setText(QString());
        name_4->setText(QString());
        name_5->setText(QString());
        name_6->setText(QString());
        checkBox_1->setText(QCoreApplication::translate("room_1", "\345\267\262\345\207\206\345\244\207", nullptr));
        checkBox_2->setText(QCoreApplication::translate("room_1", "\345\267\262\345\207\206\345\244\207", nullptr));
        checkBox_3->setText(QCoreApplication::translate("room_1", "\345\267\262\345\207\206\345\244\207", nullptr));
        checkBox_4->setText(QCoreApplication::translate("room_1", "\345\267\262\345\207\206\345\244\207", nullptr));
        checkBox_5->setText(QCoreApplication::translate("room_1", "\345\267\262\345\207\206\345\244\207", nullptr));
        checkBox_6->setText(QCoreApplication::translate("room_1", "\345\267\262\345\207\206\345\244\207", nullptr));
        menu_1->setTitle(QCoreApplication::translate("room_1", "\346\210\277\351\227\2641", nullptr));
    } // retranslateUi

};

namespace Ui {
    class room_1: public Ui_room_1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROOM_1_H
