/********************************************************************************
** Form generated from reading UI file 'rooms.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROOMS_H
#define UI_ROOMS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_rooms
{
public:
    QWidget *centralwidget;
    QLabel *room_1;
    QLabel *name_1;
    QLineEdit *room_edit;
    QLineEdit *name_edit;
    QPushButton *goin;
    QPushButton *ready;
    QLabel *number;
    QLabel *persons;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *rooms)
    {
        if (rooms->objectName().isEmpty())
            rooms->setObjectName(QString::fromUtf8("rooms"));
        rooms->resize(460, 415);
        rooms->setMinimumSize(QSize(460, 415));
        rooms->setMaximumSize(QSize(460, 415));
        centralwidget = new QWidget(rooms);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        room_1 = new QLabel(centralwidget);
        room_1->setObjectName(QString::fromUtf8("room_1"));
        room_1->setGeometry(QRect(51, 40, 131, 92));
        QFont font;
        font.setPointSize(20);
        room_1->setFont(font);
        room_1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        name_1 = new QLabel(centralwidget);
        name_1->setObjectName(QString::fromUtf8("name_1"));
        name_1->setGeometry(QRect(70, 120, 131, 131));
        name_1->setFont(font);
        name_1->setAlignment(Qt::AlignCenter);
        room_edit = new QLineEdit(centralwidget);
        room_edit->setObjectName(QString::fromUtf8("room_edit"));
        room_edit->setGeometry(QRect(230, 60, 141, 51));
        name_edit = new QLineEdit(centralwidget);
        name_edit->setObjectName(QString::fromUtf8("name_edit"));
        name_edit->setGeometry(QRect(230, 160, 141, 51));
        goin = new QPushButton(centralwidget);
        goin->setObjectName(QString::fromUtf8("goin"));
        goin->setGeometry(QRect(150, 260, 151, 31));
        ready = new QPushButton(centralwidget);
        ready->setObjectName(QString::fromUtf8("ready"));
        ready->setGeometry(QRect(150, 320, 151, 31));
        number = new QLabel(centralwidget);
        number->setObjectName(QString::fromUtf8("number"));
        number->setGeometry(QRect(180, 360, 121, 51));
        QFont font1;
        font1.setPointSize(14);
        number->setFont(font1);
        number->setAlignment(Qt::AlignCenter);
        persons = new QLabel(centralwidget);
        persons->setObjectName(QString::fromUtf8("persons"));
        persons->setGeometry(QRect(450, 360, 121, 51));
        persons->setFont(font1);
        persons->setAlignment(Qt::AlignCenter);
        rooms->setCentralWidget(centralwidget);
        menubar = new QMenuBar(rooms);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 460, 19));
        rooms->setMenuBar(menubar);
        statusbar = new QStatusBar(rooms);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        rooms->setStatusBar(statusbar);

        retranslateUi(rooms);

        QMetaObject::connectSlotsByName(rooms);
    } // setupUi

    void retranslateUi(QMainWindow *rooms)
    {
        rooms->setWindowTitle(QCoreApplication::translate("rooms", "MainWindow", nullptr));
        room_1->setText(QCoreApplication::translate("rooms", "\346\210\277\351\227\264\345\217\267\357\274\232", nullptr));
        name_1->setText(QCoreApplication::translate("rooms", "\345\220\215\347\247\260\357\274\232", nullptr));
        goin->setText(QCoreApplication::translate("rooms", "\345\212\240\345\205\245\346\210\277\351\227\264", nullptr));
        ready->setText(QCoreApplication::translate("rooms", "\345\207\206\345\244\207", nullptr));
        number->setText(QString());
        persons->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class rooms: public Ui_rooms {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROOMS_H
