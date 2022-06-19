#include "room_1.h"
#include "ui_room_1.h"


room_1::room_1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::room_1)
{
    ui->setupUi(this);
    this->setWindowTitle("服务器1号房间");
    players[1]=ui->player_1;
    players[2]=ui->player_2;
    players[3]=ui->player_3;
    players[4]=ui->player_4;
    players[5]=ui->player_5;
    players[6]=ui->player_6;


    names[1] =ui->name_1;
    names[2] =ui->name_2;
    names[3] =ui->name_3;
    names[4] =ui->name_4;
    names[5] =ui->name_5;
    names[6] =ui->name_6;

    pres[1]=ui->checkBox_1;
    pres[2]=ui->checkBox_2;
    pres[3]=ui->checkBox_3;
    pres[4]=ui->checkBox_4;
    pres[5]=ui->checkBox_5;
    pres[6]=ui->checkBox_6;

    for(int k=1;k<=6;k++)
    {
        pres[k]->setEnabled(false);
    }

}

room_1::~room_1()
{
    delete ui;
}

void room_1::addplayer(QString a, int k)
{
    for(int m=1;m<=6;m++)
   {
        if(names[m]->text()=="")
        {
            all++;
            names[m]->setText(a);
            emit per(a,m);
            break;
        }
    }
}

void room_1::setready(QString k)
{
    for(int r=1;r<=6;r++)
    {
        if(names[r]->text()==k)
                pres[r]->setChecked(true);
    }
    examine();//检查是否可以开始游戏
}

void room_1::examine()
{
    if(all==2||all==3||all==6)
    {
        for(int r=1;r<=all;r++)
        {
            if(!pres[r]->isChecked())
                return;
        }
        QString gamers=" ";
        for(int r=1;r<=all;r++)
        {
            gamers+=names[r]->text();
            gamers+=" ";
        }
        emit start_game(gamers,all);
    }
}

void room_1::person_delete(QString k)
{
    int r;
    for(r=1;r<=6;r++)
    {
        if(names[r]->text()==k)
        {
            all--;
            names[r]->clear();
            pres[r]->setChecked(false);
            break;
        }
    }
    r++;
    for(;r<=6;r++)
    {
        if(names[r]->text()=="")
            break;
        else
        {
            names[r-1]->setText(names[r]->text());
            pres[r-1]->setChecked(pres[r]->isChecked());
            names[r]->clear();
            pres[r]->setChecked(false);
        }
    }
}

bool room_1::isexist(QString t)
{
    for(int k=1;k<=6;k++)
    {
        if(names[k]->text()==t)
        {
            return true;
        }
    }
    return false;
}

QString room_1::getnames()
{
    QString ss="";
    for(int m=1;m<=6;m++)
    {
        if(names[m]->text()!="")
        {
            ss+=names[m]->text();
            ss+=" ";
        }
    }
    return ss;
}

QString room_1::getpres()
{
    QString sp="";
    for(int m=1;m<=6;m++)
    {
        if(names[m]->text()!="")
        {
           if(pres[m]->isChecked())
               sp+="1";
           else
               sp+="0";
        }
    }
    return sp;
}

QString room_1::getname(int r)
{
    return names[r]->text();
}
