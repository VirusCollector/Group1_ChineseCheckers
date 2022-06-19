#include "last_step.h"
#include "ui_last_step.h"

last_step::last_step(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::last_step)
{
    ui->setupUi(this);
    this->setWindowTitle("查看上一步");
    buttons[1]=ui->p1;
    buttons[2]=ui->p2;
    buttons[3]=ui->p3;
    buttons[4]=ui->p4;
    buttons[5]=ui->p5;
    buttons[6]=ui->p6;
    for(int r=1;r<=6;r++)
    {
        buttons[r]->setEnabled(false);
    }
}



last_step::~last_step()
{
    delete ui;
}

void last_step::on_p1_clicked()
{
    emit showlast(1);
    this->hide();
}

void last_step::on_p2_clicked()
{
    emit showlast(2);
    this->hide();
}

void last_step::on_p3_clicked()
{
    emit showlast(3);
    this->hide();
}

void last_step::on_p4_clicked()
{
    emit showlast(4);
    this->hide();
}

void last_step::on_p5_clicked()
{
    emit showlast(5);
    this->hide();
}

void last_step::on_p6_clicked()
{
    emit showlast(6);
    this->hide();
}

void last_step::in(int k)
{
    buttons[k]->setEnabled(true);
}
