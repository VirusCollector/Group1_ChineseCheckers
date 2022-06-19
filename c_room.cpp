#include "c_room.h"
#include "ui_c_room.h"
#include <QMessageBox>


c_room::c_room(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::c_room)
{
    ui->setupUi(this);
    this->setWindowTitle("我的房间");
    c_players[1]=ui->player_1;
    c_players[2]=ui->player_2;
    c_players[3]=ui->player_3;
    c_players[4]=ui->player_4;
    c_players[5]=ui->player_5;
    c_players[6]=ui->player_6;


    c_names[1] =ui->name_1;
    c_names[2] =ui->name_2;
    c_names[3] =ui->name_3;
    c_names[4] =ui->name_4;
    c_names[5] =ui->name_5;
    c_names[6] =ui->name_6;

    c_pres[1]=ui->checkBox_1;
    c_pres[2]=ui->checkBox_2;
    c_pres[3]=ui->checkBox_3;
    c_pres[4]=ui->checkBox_4;
    c_pres[5]=ui->checkBox_5;
    c_pres[6]=ui->checkBox_6;

    for(int k=1;k<=6;k++)
    {
        c_pres[k]->setEnabled(false);
    }

}

c_room::~c_room()
{
    delete ui;
}

void c_room::situation(QString a,int b)
{
    c_names[b]->setText(a);
}

void c_room::setready(QChar t,int k)
{
    if(t=='1')
        c_pres[k]->setChecked(true);
}

void c_room::setready(QString k)
{
    for(int r=1;r<=6;r++)
    {
        if(c_names[r]->text()==k)
         {
            c_pres[r]->setChecked(true);
            break;
        }
    }
}

void c_room::person_leave(QString k)
{
    int r;
    for(r=1;r<=6;r++)
    {
        if(c_names[r]->text()==k)
         {
            c_names[r]->clear();
            c_pres[r]->setChecked(false);
            break;
        }
    }
    r++;
    for(;r<=6;r++)
    {
        if(c_names[r]->text()=="")
            break;
        else
        {
            c_names[r-1]->setText(c_names[r]->text());
            c_pres[r-1]->setChecked(c_pres[r]->isChecked());
            c_names[r]->clear();
            c_pres[r]->setChecked(false);
        }
    }
}

void c_room::closeEvent (QCloseEvent *event)
{
      auto temp = QMessageBox::information(this, "窗口提示", tr("确认退出房间吗？"), QMessageBox::Yes | QMessageBox::No);
       if (temp == QMessageBox::Yes)
       {
           emit leave();
           event->accept();
        }
        else
        {
            event->ignore();
        }

}

