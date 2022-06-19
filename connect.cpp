#include "connect.h"
#include "ui_connect.h"

Connect::Connect(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Connect)
{
    ui->setupUi(this);
    this->setWindowTitle("连接到服务器");
    ui->IP->setText("");
    ui->port->setText("");
}

Connect::~Connect()
{
    delete ui;
}

void Connect::on_pushButton_clicked()
{
    emit info(ui->IP->toPlainText(),ui->port->toPlainText());
}

