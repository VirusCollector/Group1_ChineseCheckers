#ifndef BOARD_H
#define BOARD_H

#include <QObject>
#include<vector>
#include "music.h"
#include"settings.h"
#include "networkdata.h"

class Player;
class Widget;
//棋盘类
class Board : public QObject
{
    Q_OBJECT
public:
    explicit Board(Widget*_parentwidget,int _playnum=2);
    ~Board();
    void pass_to_nextplayer(int currentidx);//将游戏控制权移交给下一位在场的玩家
    void set_activatedplayer(int idx);//激活玩家状态(进入回合)
    void unset_activatedplayer(int idx);//解除玩家状态(退出回合)
    //void showboard();//展示space的标记情况
    int playernum;//游戏人数
    int interval;//玩家区域号的间隔(=6/游戏人数)
    Widget*parentwidget;//父控件
    std::vector<Player*>players;//游戏玩家
    std::vector<Player*>winnerlist;//获胜者列表(先胜利先入)
    std::vector<Player*>loserlist;//困毙者列表(先困毙先入)
    int space[17][17];//一个17*17的空间,通过grid指针实现-8<=i,j<=8的grid[i][j]索引,表示棋盘某格点处的棋子状态(-1:hintbtn,0:无棋子或hintbtn,i(i>0):区域i玩家的棋子）

    int*p1[17];
    int**grid;//-8<=i,j<=8
    music finalmove;


signals:
   void step();

};

#endif // BOARD_H
