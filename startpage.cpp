#include "startpage.h"
#include "ui_startpage.h"
#include <QApplication>

StartPage::StartPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StartPage)
{
    ui->setupUi(this);
    this->setWindowTitle("模式选择");
}

StartPage::~StartPage()
{
    delete ui;
}

void StartPage::on_pushButton_clicked()
{
    t=new server;
    t->show();
    this->hide();
}

void StartPage::on_pushButton_2_clicked()
{
    s=new Widget;
    s->show();
    this->hide();
}

