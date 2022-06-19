#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSoundEffect>
#include <QMessageBox>
#include"player.h"
#include"board.h"
#include"marble.h"
#include "music.h"
#include"settings.h"
#include "all_settings.h"
#include "connect.h"
#include <temp_player.h>
#include "networkserver.h"
#include "networksocket.h"
#include "networkdata.h"
#include "server.h"
#include "rooms.h"
#include "c_room.h"
#include "rank.h"
#include <QMediaPlayer>
#include<QStringList>
#include<QDebug>
#include <last_step.h>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    all_settings set;//设置界面
    rooms room_opt;//用户进入房间前的选择界面
    Connect c_connect;//连接到服务器的界面
    last_step showlast;//显示上一步界面
    QSoundEffect *background=new QSoundEffect;
    c_room myroom;//显示我加入的房间
    QStringList NicknameList;//名称列表
    QStringList RegionList;//区域列表
    QString nickname;//即c_you
    QString CharIdx;//A-F，反转前
    int OldPlayersIdx;//0-5，反转前,表示反转前在board::players中的idx
    int OldRegionIdx;//1-6,反转前,表示反转前的区域号，具体颜色参考settings::color
    NetworkSocket *socket;
    rank ranks;//显示排名
    QString room_num;
    QString c_you,c_order;//你的用户名和房间里的位置
    QString places[6]={"蓝","红","黄","橙","绿","紫"};
    QTimer c_timer;//计时器
    QStringList e;
    int playnumber=0;
    int step=0;
    int c_time;//规定秒数
    int isover[6]={0};   
    bool isconnected =false;
    bool isAI=false;


    void displayError();//连接失败
    void connected();//连接成功提示
    void LCDclear();//计时器归零
    void setlocalplayer(int k);//显示当前行棋方
    void runAI();//运行AI

private slots:
    void on_startplay_clicked();//点击开始游戏
    void on_pushButton_clicked();//设置界面
    void c_inroom(QString a,QString b);//请求进入房间，发送JOIN_ROOM_OP
    void c_beready();//请求准备，发送PLAYER_READY_OP
    void receiveinfo(NetworkData);//接受服务端消息
    void c_leave();//接受退出房间信号并发给服务器
    void update_time();//更新计时器
    void toserver(QString ip,QString port);//连接服务器
    void on_AI_clicked();//点击托管
    void on_show_last_clicked();//显示上一步
    void show_last_step(int k);//展示指定玩家最后一步

private:
    Ui::Widget *ui;
    Board* board;

};
#endif // WIDGET_H
