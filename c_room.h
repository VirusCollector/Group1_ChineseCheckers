#ifndef C_ROOM_H
#define C_ROOM_H

#include <QMainWindow>
#include <QCloseEvent>
#include "ui_c_room.h"
#include <QMessageBox>

namespace Ui {
class c_room;
}

class c_room : public QMainWindow
{
    Q_OBJECT

public:
    explicit c_room(QWidget *parent = nullptr);
    ~c_room();
    void situation(QString a,int b);//设置玩家状态
    void setready(QChar t,int k);//设置该玩家为准备状态
    void setready(QString k);//设置该玩家为准备状态
    void person_leave(QString k);//让该玩家离开
    QLabel *c_players[7];//玩家编号
    QLabel *c_names[7];//玩家名称
    QCheckBox *c_pres[7];//玩家准备状态

signals:
    void leave();//离开房间发出信号

protected:
    void closeEvent (QCloseEvent *event);//重写关闭窗口函数

private:
    Ui::c_room *ui;

};

#endif // C_ROOM_H
