#ifndef ROOM_1_H
#define ROOM_1_H

#include <QMainWindow>
#include "ui_room_1.h"

namespace Ui {
class room_1;
}

class room_1 : public QMainWindow  //服务器端创建1号房间
{
    Q_OBJECT

public:
    explicit room_1(QWidget *parent = nullptr);
    ~room_1();
    void addplayer(QString a,int k);//添加该玩家至列表中
    void setready(QString k);//设置玩家准备状态
    void examine();//检查是否可以开始游戏
    QString getnames();//获取玩家列表
    QString getname(int r);//通过编号获得玩家用户名
    QString getpres();//获取玩家准备情况
    void person_delete(QString k);//删除离开的用户
    bool isexist(QString t);//判断用户名是否重复
    QLabel *players[7];
    QLabel *names[7];
    QCheckBox *pres[7];
    int all=0;

signals:
    void per(QString a,int m);//发送玩家信息
    void start_game(QString games,int all);//发出开始游戏信号

private:
    Ui::room_1 *ui;
};

#endif // ROOM_1_H
