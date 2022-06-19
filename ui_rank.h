/********************************************************************************
** Form generated from reading UI file 'rank.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RANK_H
#define UI_RANK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_rank
{
public:
    QLabel *label;
    QLabel *r1;
    QLabel *r2;
    QLabel *r3;
    QLabel *r4;
    QLabel *r5;
    QLabel *r6;
    QLabel *name1;
    QLabel *name2;
    QLabel *name3;
    QLabel *name4;
    QLabel *name5;
    QLabel *name6;

    void setupUi(QWidget *rank)
    {
        if (rank->objectName().isEmpty())
            rank->setObjectName(QString::fromUtf8("rank"));
        rank->resize(512, 499);
        label = new QLabel(rank);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(140, 10, 201, 51));
        QFont font;
        font.setPointSize(26);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        r1 = new QLabel(rank);
        r1->setObjectName(QString::fromUtf8("r1"));
        r1->setGeometry(QRect(50, 80, 41, 41));
        QFont font1;
        font1.setPointSize(36);
        r1->setFont(font1);
        r1->setStyleSheet(QString::fromUtf8("color: rgb(255, 215, 0);"));
        r1->setAlignment(Qt::AlignCenter);
        r2 = new QLabel(rank);
        r2->setObjectName(QString::fromUtf8("r2"));
        r2->setGeometry(QRect(50, 150, 41, 41));
        r2->setFont(font1);
        r2->setStyleSheet(QString::fromUtf8("color: rgb(192, 192, 192);"));
        r2->setAlignment(Qt::AlignCenter);
        r3 = new QLabel(rank);
        r3->setObjectName(QString::fromUtf8("r3"));
        r3->setGeometry(QRect(50, 220, 41, 41));
        r3->setFont(font1);
        r3->setStyleSheet(QString::fromUtf8("color: rgb(198, 145, 69);"));
        r3->setAlignment(Qt::AlignCenter);
        r4 = new QLabel(rank);
        r4->setObjectName(QString::fromUtf8("r4"));
        r4->setGeometry(QRect(50, 290, 41, 41));
        QFont font2;
        font2.setPointSize(16);
        r4->setFont(font2);
        r4->setAlignment(Qt::AlignCenter);
        r5 = new QLabel(rank);
        r5->setObjectName(QString::fromUtf8("r5"));
        r5->setGeometry(QRect(50, 360, 41, 41));
        r5->setFont(font2);
        r5->setAlignment(Qt::AlignCenter);
        r6 = new QLabel(rank);
        r6->setObjectName(QString::fromUtf8("r6"));
        r6->setGeometry(QRect(50, 430, 41, 41));
        r6->setFont(font2);
        r6->setAlignment(Qt::AlignCenter);
        name1 = new QLabel(rank);
        name1->setObjectName(QString::fromUtf8("name1"));
        name1->setGeometry(QRect(150, 80, 331, 41));
        name1->setFont(font2);
        name1->setAlignment(Qt::AlignCenter);
        name2 = new QLabel(rank);
        name2->setObjectName(QString::fromUtf8("name2"));
        name2->setGeometry(QRect(150, 150, 331, 41));
        QFont font3;
        font3.setPointSize(18);
        name2->setFont(font3);
        name2->setAlignment(Qt::AlignCenter);
        name3 = new QLabel(rank);
        name3->setObjectName(QString::fromUtf8("name3"));
        name3->setGeometry(QRect(150, 220, 331, 41));
        name3->setFont(font3);
        name3->setAlignment(Qt::AlignCenter);
        name4 = new QLabel(rank);
        name4->setObjectName(QString::fromUtf8("name4"));
        name4->setGeometry(QRect(150, 290, 331, 41));
        name4->setFont(font3);
        name4->setAlignment(Qt::AlignCenter);
        name5 = new QLabel(rank);
        name5->setObjectName(QString::fromUtf8("name5"));
        name5->setGeometry(QRect(150, 360, 331, 41));
        name5->setFont(font3);
        name5->setAlignment(Qt::AlignCenter);
        name6 = new QLabel(rank);
        name6->setObjectName(QString::fromUtf8("name6"));
        name6->setGeometry(QRect(150, 430, 331, 41));
        name6->setFont(font3);
        name6->setAlignment(Qt::AlignCenter);

        retranslateUi(rank);

        QMetaObject::connectSlotsByName(rank);
    } // setupUi

    void retranslateUi(QWidget *rank)
    {
        rank->setWindowTitle(QCoreApplication::translate("rank", "Form", nullptr));
        label->setText(QCoreApplication::translate("rank", "\345\257\271\345\261\200\346\216\222\345\220\215", nullptr));
        r1->setText(QCoreApplication::translate("rank", "1", nullptr));
        r2->setText(QCoreApplication::translate("rank", "2", nullptr));
        r3->setText(QCoreApplication::translate("rank", "3", nullptr));
        r4->setText(QCoreApplication::translate("rank", "4", nullptr));
        r5->setText(QCoreApplication::translate("rank", "5", nullptr));
        r6->setText(QCoreApplication::translate("rank", "6", nullptr));
        name1->setText(QString());
        name2->setText(QString());
        name3->setText(QString());
        name4->setText(QString());
        name5->setText(QString());
        name6->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class rank: public Ui_rank {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RANK_H
