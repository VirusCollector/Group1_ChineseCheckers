#include "player.h"
#include"marble.h"
#include"board.h"
#include"settings.h"
#include"widget.h"

Player::Player(int _region,Board* _parentBoard,QObject *parent)
    : QObject{parent},region(_region),mode(0),parentBoard(_parentBoard),selected_marble(nullptr)
{
//initialize
    player_idx=(region-1)/_parentBoard->interval;
    marbles.clear();
    path.clear();
    hint_btns.clear();
    int i,j;
    for(i=1;i<5;i++)
        for(j=5-i;j<5;j++)
        {
            marbles.push_back(new Marble(this,this->parentBoard->parentwidget));
            marbles.back()->moveto(i,j);
            marbles.back()->setStyleSheet("QLabel{border-image:url("+color[region]+");}");
        }
}
Player::Player(Player *state, int name, QPoint pat, int mod)
{
    region = state->region;
    mode = mod;
    player_idx = state->player_idx;
    parentBoard = state->parentBoard;
    selected_marble = state->selected_marble;
    for(int i=0;i<10;i++)
    {
        marbles.push_back(new Marble(*state->marbles[i]));
    }
    if(mod == 1)
    {
        marbles[name]->boardposition=pat;
        marbles[name]->update_playerposition();
    }
}


Player::~Player()
{
    for(Marble*marble:marbles)
        delete marble;
    marbles.clear();
}

bool Player::isstuck()//已经不用再考虑这种情况，函数调用处已经被注释
{
    int ret=0;
    for(Marble*iter:marbles)
    {
        iter->get_hint_points();
        ret+=iter->hint_points.size();
    }
    return ret==10;
}

void Player::searchHintPoints()
{
    for(Marble*iter:marbles)
    {
        iter->get_hint_points();
    }
}

void Player::get_path(Marble *target,int idx)
{
    int iter=idx;
    while(iter!=-1)
    {
        path.push_back(target->hint_points[iter]);
        iter=target->fromidxes[iter];
    }
}

bool Player::win()
{
    bool ret=true;
    for(Marble*iter:marbles)
        ret&=(iter->playerposition.x()+iter->playerposition.y())<-4;
    return ret;
}

void Player::set_winstate()
{
    mode=2;
    parentBoard->winnerlist.push_back(this);
}

void Player::set_loserstate()
{
    mode=2;
    if(hint_btns.size())
        clear_hint_btn();
    parentBoard->loserlist.push_back(this);
    for(Marble* marble0:marbles)
    {
        setstate(parentBoard->grid,marble0->boardposition,0);
        delete marble0;
    }
    marbles.clear();
}

void Player::on_btnclicked()
{
    selected_marble->unset_highlight();
    int idx=qobject_cast<QPushButton*>(sender())->property("boardpositionidx").toInt();
    get_path(selected_marble,idx);
    clear_hint_btn();
    QString data2=PathToData2(path,parentBoard->parentwidget->OldRegionIdx);
    NetworkData p(OPCODE(200007),parentBoard->parentwidget->CharIdx,data2);
    parentBoard->parentwidget->socket->send(p);//向服务器发送MOVE_OP
    parentBoard->parentwidget->LCDclear();
    path.clear();
    selected_marble=nullptr;
    parentBoard->unset_activatedplayer(this->player_idx);
}

void Player::show_last_step()
{
    QTimer::singleShot(2000,this,SLOT(close_last()));
    unsigned int s=LatestPath.size();
    for(int i=0;i<s;i++)
    {
        temp[i]=new QPushButton(this->parentBoard->parentwidget);
        temp[i]->setProperty("boardpositionidx",i);
        temp[i]->setVisible(true);
        temp[i]->setGeometry(pixelToRect(BoardToPixel(LatestPath[i]),half_hintlen));
        if(i==s-1)
        {
            temp[i]->setStyleSheet("QPushButton {min-width: 30px;max-width: 30px; max-height: 30px;min-height: 30px;border-radius: 15px;font-size: 15px;color: white;background: 	#000000 ; /* 默认颜色 */}"
                                   "QPushButton:hover {font-size: 18px;color: white;background: #FFC0CB; /* 悬停颜色 */}" );
        }
        else
        {
            temp[i]->setStyleSheet("QPushButton {min-width: 30px;max-width: 30px; max-height: 30px;min-height: 30px;border-radius: 15px;font-size: 15px;color: white;background: 	#FFC0CB ; /* 默认颜色 */}"
                                   "QPushButton:hover {font-size: 18px;color: white;background: #FFC0CB; /* 悬停颜色 */}" );
        }
    }
}

void Player::close_last()
{
    temp_s++;
    for(int i=0;i<LatestPath.size();i++)
    {
        delete temp[i];
    }
}

void Player::show_hint_btn(Marble *m)
{
    unsigned int i;
    for(i=1;i<m->hint_points.size();i++)
    {
        hint_btns.push_back(new QPushButton(this->parentBoard->parentwidget));
        hint_btns.back()->setProperty("boardpositionidx",i);
        hint_btns.back()->setStyleSheet("QPushButton {min-width: 30px;max-width: 30px; max-height: 30px;min-height: 30px;border-radius: 15px;font-size: 15px;color: white;background: 	#00FF7F ; /* 默认颜色 */}"
                              "QPushButton:hover {font-size: 18px;color: white;background: #d5d5d5; /* 悬停颜色 */}"
                              "QPushButton:pressed {background: #f2f2f2 /* 按下颜色 */}"
                              );
        hint_btns.back()->setVisible(true);
        hint_btns.back()->setGeometry(pixelToRect(BoardToPixel(m->hint_points[i]),half_hintlen));
        connect(hint_btns.back(),SIGNAL(clicked()),this,SLOT(on_btnclicked()));
    }
}

void Player::clear_hint_btn()
{
    unsigned int i;
    for(i=0;i<hint_btns.size();i++)
        delete hint_btns[i];
    hint_btns.clear();
}

void Player::on_marbleClicked()
{
    Marble*clicked_marble=qobject_cast<Marble*>(sender());
    if(mode==1&&selected_marble!=clicked_marble)
    {
        if(selected_marble==nullptr)//no selected_marble before
        {
            selected_marble=clicked_marble;
            selected_marble->highlight();
            show_hint_btn(selected_marble);
        }
        else
        {
            selected_marble->unset_highlight();
            clear_hint_btn();
            selected_marble=clicked_marble;
            selected_marble->highlight();
            show_hint_btn(selected_marble);
        }
    }
}
