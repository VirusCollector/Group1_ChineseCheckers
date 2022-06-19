#include "rooms.h"
#include "ui_rooms.h"

rooms::rooms(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::rooms)
{
    ui->setupUi(this);
    this->setWindowTitle("加入房间");
    ui->ready->setDisabled(true);
}

rooms::~rooms()
{
    delete ui;
}

void rooms::on_goin_clicked()
{
    QString room_1=ui->room_edit->text();
    QString name_1=ui->name_edit->text();
    if(examok(room_1,name_1))
    {
       emit inroom(room_1,name_1);
       ui->name_edit->setDisabled(true);
       ui->goin->setDisabled(true);
       ui->room_edit->setDisabled(true);
       ui->ready->setDisabled(false);
    }
}

void rooms::on_ready_clicked()
{
    if(!ui->goin->isEnabled())
    {
    emit beready();
    ui->ready->setText("已准备");
    ui->ready->setDisabled(true);
    }
    else
    {
        QMessageBox::about(this, tr("温馨提示"), tr("请先进入房间再准备！"));
    }

}

void rooms::recover()
{
    ui->name_edit->setDisabled(false);
    ui->goin->setDisabled(false);
    ui->room_edit->setDisabled(false);
    ui->ready->setDisabled(true);
    ui->ready->setText("准备");
}

bool rooms::examok(QString room_1,QString name_1)
{
    if(room_1!="1")
    {
        QMessageBox::about(this, tr("温馨提示"), tr("只开启了1号房间，请重新输入！"));
         return false;
    }
    if(name_1.size()>20)
    {
         QMessageBox::about(this, tr("温馨提示"), tr("用户名只能在20个字符以内！"));
         return false;
    }

    for(int r=0;r<=name_1.size()-1;r++)
    {
        ushort uni = (ushort)name_1[r].unicode();
        if(uni >= 0x4E00 && uni <= 0x9FA5)
        {
             QMessageBox::about(this, tr("温馨提示"), tr("用户名不能包含中文！"));
             return false;
        }
        if(name_1[r].isDigit()||name_1[r].isLetter()||name_1[r]=='_')
            continue;
        else
        {
         QMessageBox::about(this, tr("温馨提示"), tr("用户名只能包括大小写字母、数字和下划线！"));
         return false;
        }
    }
    return true;
}

