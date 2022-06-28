#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include<QPushButton>
#include"settings.h"
#include "networkdata.h"
#include <QLabel>
#include <QTimer>

class Board;
class Marble;
//玩家类
class Player : public QObject
{
    Q_OBJECT
public:
    explicit Player(int _region,Board* _parentBoard,QObject *parent = nullptr);
     explicit Player(Player* state,int idx, QPoint path,int mode);
    ~Player();
    int region;//玩家出生区域,下方橙色区域为1,逆时针依次增加,与游戏人数无关
    int mode;//0:playing but not in his turn;1:playing and in his turn;2:finished game(0:游戏中但未激活，1：激活,2:已结束游戏）
    int player_idx;//玩家在board::std::vector<Player*>players里的索引,从0开始,当游戏人数不同时,同一区域对应的player_idx可能不同
    Board* parentBoard;//父棋盘
    Marble* selected_marble;//当前选中的其中,若无则指向nullptr
    std::vector<Marble*> marbles;//玩家拥有的棋子,共十个
    std::vector<QPoint> path;//调动get_path后得到的棋子移动路径,path[0]为目标点,path[path.size()-1]为出发点
    std::vector<QPushButton*>hint_btns;//调用show_hint_btn后得到的可移动位置的提示按钮
    std::vector<QPoint> LatestPath;//最后一步移动的路径，格式和path相同,第一轮为空，可用LatestPath->empty()来判断
    QPushButton* temp[100];//显示上一步
    QTimer last_time;
    bool loser_state = false;
    bool isstuck();//是否困毙 注:函数内会调用所有棋子的get_hint_points,
    void searchHintPoints();
    void show_hint_btn(Marble*m);//TODO:显示hint_btn(可以换个图之类的完善一下)
    void show_last_step();//显示上一步
    void clear_hint_btn();//TODO：清除hint_btn
    void get_path(Marble*target,int idx);//获得目标棋子到该棋子hint_points[iter]按钮处的路径并存储在player::std::vector<QPoint> path内
    bool win();//是否胜利
    void set_winstate();//设置胜利状态
    void set_loserstate();//超时后设置为失败状态
    int temp_s=0;
signals:


private slots:
        void on_marbleClicked();//TODO:基于marble被点击后的slot(音效可以加这里,下同)
        void on_btnclicked();//基于按钮被点击后的slot
        void close_last();//关闭上一步路径显示
};

#endif // PLAYER_H
