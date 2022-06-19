#ifndef ROOMS_H
#define ROOMS_H

#include <QMainWindow>
#include<QCoreApplication>
#include<QCoreApplication>
#include <QWidget>
#include <QMessageBox>
#include <QChar>

namespace Ui {
class rooms;
}

class rooms : public QMainWindow
{
    Q_OBJECT

public:
    explicit rooms(QWidget *parent = nullptr);
    ~rooms();
    void recover();//恢复进入房间和准备按钮
    bool examok(QString room_1,QString name_1);//检查用户名是否合法

signals:
    void inroom(QString a,QString b);//发送进入房间信号
    void beready();//发送准备信号


private slots:
    void on_goin_clicked();
    void on_ready_clicked();

private:
    Ui::rooms *ui;
};

#endif // ROOMS_H
