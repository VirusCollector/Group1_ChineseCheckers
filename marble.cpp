#include "marble.h"
#include"player.h"
#include"board.h"
#include"settings.h"
#include<QDebug>
#include"widget.h"
#include <QPropertyAnimation>
extern bool isvolume;
Marble::Marble(Player*_parentplayer,QWidget*_parentWidget):QLabel(_parentWidget)
,parentplayer(_parentplayer)
{
    hint_points.clear();
    fromidxes.clear();
    connect(this,SIGNAL(mouseClicked()),parentplayer,SLOT(on_marbleClicked()));
    setVisible(true);

}
Marble::Marble(Marble &m)
{
    parentplayer = m.parentplayer;
    boardposition = m.boardposition;
    playerposition = m.playerposition;
}


void Marble::moveto(int _x, int _y)
{
playerposition=QPoint(_x,_y);
update_boardposition();
moveto(boardposition);
}

void Marble::moveto(QPoint birthboardposition)
{
    boardposition=birthboardposition;
    update_playerposition();
    parentplayer->parentBoard->grid[boardposition.x()][boardposition.y()]=parentplayer->region;
    QPoint pixelpostion=BoardToPixel(boardposition);
    setGeometry(pixelpostion.x()-halflen,pixelpostion.y()-halflen,2*halflen,2*halflen);
}

QPoint Marble::update_boardposition()
{
    boardposition=BaseTransformation(parentplayer->region,1,playerposition);
    return boardposition;
}

QPoint Marble::update_playerposition()
{
    playerposition=BaseTransformation(1,parentplayer->region,boardposition);
    return playerposition;
}

void Marble::highlight()
{
    setText("highlighted");
}

void Marble::unset_highlight()
{
    setText("");
}

void Marble::animation_finished()
{
    QPropertyAnimation *pAnimation1 = new QPropertyAnimation(this, "geometry");
    connect(pAnimation1,SIGNAL(finished()),this,SLOT(animation_finished()));
    sizeofpaths-=1;
    if(sizeofpaths>=0)
    {
        QPoint temp=BoardToPixel(paths[sizeofpaths]);
        pAnimation1->setDuration(500);
        pAnimation1->startValue();
        pAnimation1->setEndValue(pixelToRect(temp,halflen));
        pAnimation1->start(QAbstractAnimation::DeleteWhenStopped);
    }
    //落子音效
    else
    {
        if(isvolume)
        {
            parentplayer->parentBoard->finalmove.movemusic();
        }
    }
}

void Marble::jumpto(std::vector<QPoint> _path)
{
    //_path是调动get_path后得到的棋子移动路径,_path[0]为目标点,_path[_path.size()-1]为出发点
    paths.clear();
    paths=_path;
    QPoint target=_path.front();//取出目标点
    setstate(this->parentplayer->parentBoard->grid,boardposition,0);//将棋盘上旧boardposition的占据状态更新为0
    boardposition=target;//将棋子的boardposition更新为target
    update_playerposition();//根据boardposition更新棋子的playerposition
    setstate(this->parentplayer->parentBoard->grid,target,this->parentplayer->region);//将棋盘上新boardposition的占据状态更新为棋子所属玩家的region
    //下面是动画实现的位置
    //可能用到的函数：QPoint BoardToPixel(QPoint boardposition)；QRect pixelToRect(QPoint pixelposition,int _halflen)
    //都在settings.cpp里

    //动画部分代码开始

    QPropertyAnimation *pAnimation1 = new QPropertyAnimation(this, "geometry");
    connect(pAnimation1,SIGNAL(finished()),this,SLOT(animation_finished()));


    sizeofpaths=paths.size();
    sizeofpaths-=2;
    QPoint temp=BoardToPixel(_path[sizeofpaths]);
    pAnimation1->setDuration(500);
    pAnimation1->startValue();
    pAnimation1->setEndValue(pixelToRect(temp,halflen));
    pAnimation1->start(QAbstractAnimation::DeleteWhenStopped);



    //动画部分代码结束

    QPoint pixelpostion=BoardToPixel(boardposition);//通过目标点的boardposition得到对应的pixelpostion（绝对像素坐标）
    setGeometry(pixelpostion.x()-halflen,pixelpostion.y()-halflen,2*halflen,2*halflen);//让棋子的图像在新的位置显示

}

void Marble::get_hint_points()
{
if(hint_points.empty())
{
    hint_points.push_back(boardposition);//起始点入队
    int front=0,rear=1;
    unsigned int i;
    fromidxes.push_back(-1);//设置起始点来源=-1
    QPoint hintpoint;
    //搜索一次连续跳跃可到达的位置
    while(front!=rear)//队列不为空
    {
        hintpoint=hint_points[front++];//出队
        for(i=0;i<6;i++)//6个方向BFS,当前位置为hintpoint,目标点为hintpoint+next[i]*2
        {//3个条件:目标点位于棋盘内,当前位置与目标点间有棋子,目标点未被占据(包括要求未被设置为-1)
            if(isinboard(hintpoint+next[i]*2)&&getstate(parentplayer->parentBoard->grid,hintpoint+next[i])>0&&getstate(parentplayer->parentBoard->grid,hintpoint+next[i]*2)==0)
            {
                hint_points.push_back(hintpoint+next[i]*2);//入队
                setstate(parentplayer->parentBoard->grid,hint_points.back(),-1);//该点可通过一次连续的跳跃到达,设置为-1
                fromidxes.push_back(front-1);//设置来源索引为front-1
                rear++;
            }
        }
    }
    //搜索从起始点通过平移可到达的位置
    hintpoint=hint_points.front();
    for(i=0;i<6;i++)
    {
        if(isinboard(hintpoint+next[i])&&getstate(parentplayer->parentBoard->grid,hintpoint+next[i])==0)
        {
            hint_points.push_back(hintpoint+next[i]);
            setstate(parentplayer->parentBoard->grid,hint_points.back(),-1);
            fromidxes.push_back(0);
        }
    }
    //清空设置的-1标记,避免影响其他棋子的搜索,注意不要把起始点的标记清了
    for(i=1;i<hint_points.size();i++)
    {
        setstate(parentplayer->parentBoard->grid,hint_points[i],0);
    }
}
}

void Marble::mousePressEvent(QMouseEvent *event)
{

    if(event->button()==Qt::LeftButton)
    {
        emit mouseClicked();
    }
}

