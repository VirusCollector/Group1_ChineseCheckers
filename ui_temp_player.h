/********************************************************************************
** Form generated from reading UI file 'temp_player.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEMP_PLAYER_H
#define UI_TEMP_PLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_temp_player
{
public:
    QLabel *label;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;

    void setupUi(QWidget *temp_player)
    {
        if (temp_player->objectName().isEmpty())
            temp_player->setObjectName(QString::fromUtf8("temp_player"));
        temp_player->resize(288, 216);
        label = new QLabel(temp_player);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 40, 241, 31));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        label->setFont(font);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAlignment(Qt::AlignCenter);
        layoutWidget = new QWidget(temp_player);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(100, 70, 91, 131));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);


        retranslateUi(temp_player);

        QMetaObject::connectSlotsByName(temp_player);
    } // setupUi

    void retranslateUi(QWidget *temp_player)
    {
        temp_player->setWindowTitle(QCoreApplication::translate("temp_player", "\346\270\270\346\210\217\344\272\272\346\225\260\350\256\276\345\256\232", nullptr));
        label->setText(QCoreApplication::translate("temp_player", "\351\200\211\346\213\251\346\270\270\346\210\217\344\272\272\346\225\260", nullptr));
        pushButton->setText(QCoreApplication::translate("temp_player", "2", nullptr));
        pushButton_3->setText(QCoreApplication::translate("temp_player", "3", nullptr));
        pushButton_2->setText(QCoreApplication::translate("temp_player", "6", nullptr));
    } // retranslateUi

};

namespace Ui {
    class temp_player: public Ui_temp_player {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEMP_PLAYER_H
