#include "temp_player.h"
#include "ui_temp_player.h"
#include <widget.h>

temp_player::temp_player(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::temp_player)
{
    ui->setupUi(this);
}

temp_player::~temp_player()
{
    delete ui;
}


void temp_player::on_pushButton_clicked()
{
   emit sendnum(2);
   this->hide();
}


void temp_player::on_pushButton_3_clicked()
{
    emit sendnum(3);
    this->hide();
}


void temp_player::on_pushButton_2_clicked()
{
    emit sendnum(6);
    this->hide();
}

