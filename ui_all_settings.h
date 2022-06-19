/********************************************************************************
** Form generated from reading UI file 'all_settings.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALL_SETTINGS_H
#define UI_ALL_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_all_settings
{
public:
    QPushButton *pushButton;
    QSplitter *splitter;
    QCheckBox *volume;
    QCheckBox *back;

    void setupUi(QWidget *all_settings)
    {
        if (all_settings->objectName().isEmpty())
            all_settings->setObjectName(QString::fromUtf8("all_settings"));
        all_settings->resize(230, 157);
        all_settings->setMaximumSize(QSize(230, 157));
        pushButton = new QPushButton(all_settings);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(40, 90, 131, 51));
        splitter = new QSplitter(all_settings);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(80, 30, 51, 41));
        splitter->setOrientation(Qt::Vertical);
        volume = new QCheckBox(splitter);
        volume->setObjectName(QString::fromUtf8("volume"));
        splitter->addWidget(volume);
        back = new QCheckBox(splitter);
        back->setObjectName(QString::fromUtf8("back"));
        splitter->addWidget(back);

        retranslateUi(all_settings);

        QMetaObject::connectSlotsByName(all_settings);
    } // setupUi

    void retranslateUi(QWidget *all_settings)
    {
        all_settings->setWindowTitle(QCoreApplication::translate("all_settings", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("all_settings", "\346\270\270\346\210\217\350\247\204\345\210\231", nullptr));
        volume->setText(QCoreApplication::translate("all_settings", "\351\237\263\346\225\210", nullptr));
        back->setText(QCoreApplication::translate("all_settings", "\351\237\263\344\271\220", nullptr));
    } // retranslateUi

};

namespace Ui {
    class all_settings: public Ui_all_settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALL_SETTINGS_H
