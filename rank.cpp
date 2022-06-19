#include "rank.h"
#include "ui_rank.h"


rank::rank(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::rank)
{
    ui->setupUi(this);
    this->setWindowTitle("游戏结束");
    rank_names[1] =ui->name1;
    rank_names[2] =ui->name2;
    rank_names[3] =ui->name3;
    rank_names[4] =ui->name4;
    rank_names[5] =ui->name5;
    rank_names[6] =ui->name6;
}

rank::~rank()
{
    delete ui;
}

void rank::setrank(int r,QString t)
{
    rank_names[r]->setText(t);
}

void rank::closeEvent (QCloseEvent *event)//重写关闭窗口函数
{
    for(int r=1;r<=6;r++)
        rank_names[r]->clear();
    event->accept();
}
