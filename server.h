#ifndef SERVER_H
#define SERVER_H

#include <QMainWindow>
#include "networkserver.h"
#include "networksocket.h"
#include "networkdata.h"
#include "room_1.h"
#include <math.h>
#include <QTimer>

namespace Ui {
class server;
}

class server : public QMainWindow
{
    Q_OBJECT

public:
    explicit server(QWidget *parent = nullptr);
    ~server();

    room_1 myroom_1;//服务器1号房间
    bool test(QString p);//检查走棋坐标是否正确
    QTimer *timer;//创建计时器
    void gameover();//游戏结束
    bool isingame=false;//是否正在游戏
    int i=0;
    int local_temp=0;
    QTcpSocket* local;
    QList<QTcpSocket*> inroom;
    QList<QTcpSocket*> winner;
    QList<QTcpSocket*> loser;

private slots:
    void on_pushButton_2_clicked();//打开1号房间
    void receiveData(QTcpSocket* client, NetworkData data);//接收客户端消息
    void update(QString a,int you);//向房间内其他玩家发送JOIN_ROOM_OP
    void start_game(QString gamers,int all);//开始游戏
    void start_turns(int r);//开始回合
    void timeover();//超时


signals:


private:
    Ui::server *ui;
    NetworkSocket *mysocket;
    NetworkServer *myserver;
};

#endif // SERVER_H
