#include "all_settings.h"
#include "ui_all_settings.h"

bool isvolume=true;
all_settings::all_settings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::all_settings)
{
    ui->setupUi(this);
    this->setWindowTitle("设置");
    if(ui->volume->isChecked()==false)
    {
        ui->volume->setCheckState(Qt::Checked);
    }
    if(ui->back->isChecked()==false)
    {
        ui->back->setCheckState(Qt::Checked);
    }
}

all_settings::~all_settings()
{
    delete ui;
}


void all_settings::on_volume_stateChanged(int arg1)
{
     if(ui->volume->isChecked()==false)
     {
         isvolume=false;
     }
     if(ui->volume->isChecked()==true)
     {
         isvolume=true;
     }
}


void all_settings::on_back_stateChanged(int arg1)
{
    if(ui->back->isChecked()==false)
    {
      b.offbackmusic();
    }
    if(ui->back->isChecked()==true)
    {
      b.backmusic();
    }
}


void all_settings::on_pushButton_clicked()
{
    QDesktopServices::openUrl(QUrl(QString("https://cpp.ruc.megaowier.cc/instructions/inst-rule/")));
}

