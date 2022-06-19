#ifndef MARBLE_H
#define MARBLE_H

#include <QObject>
#include<QLabel>
#include<QMouseEvent>
#include<QPushButton>
#include"settings.h"
#include "music.h"

class Player;
//棋子类
class Marble : public QLabel
{
    Q_OBJECT
public:
    Marble(Player*_parentplayer,QWidget*_parentWidget);
    Marble(Marble &m);
    void moveto(int _x,int _y);//移动到birthplayerposition为(_x,_y)处,下个函数效果基本一样,只是坐标不同
    void moveto(QPoint birthboardposition);
    QPoint update_boardposition();//更新boardposition(playerposition改变时调用,下个函数同理）
    QPoint update_playerposition();
    void highlight();//to be complimented;TODO:高亮（点击棋子后调用，图标还没有~）
    void unset_highlight();//to be complimented;TODO：解除高亮
    void jumpto(std::vector<QPoint> _path);//to be complimented;TODO:从当前位置经路径_path跳至target(=_path.front())处（动画还没做)
    void get_hint_points();//used in isstuck(),which is used in setactivated()//搜索hint_points并存储至std::vector<QPoint>hint_points
    Player*parentplayer;//父玩家
    QPoint boardposition;//棋盘的通用坐标
    QPoint playerposition;//玩家的坐标
    //hint
    std::vector<QPoint>hint_points;//调用get_hint_points得到的hint_points
    std::vector<int>fromidxes;//第i个元素表示hint_points[i]的父节点在第i个元素表示hint_points的索引
    std::vector<QPoint> paths;//走棋路径
    int sizeofpaths;//路径里面的点数
    //music finalmove;
protected:
    void mousePressEvent(QMouseEvent *event);//鼠标点击事件(我也不知道是啥,照着教程敲的)
signals:
    void mouseClicked();//鼠标点击信号
private slots:
    void animation_finished();
};

#endif // MARBLE_H
