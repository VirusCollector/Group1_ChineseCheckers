#include "board.h"
#include"player.h"
#include"marble.h"
#include"settings.h"
#include"widget.h"
#include<QDebug>
Board::Board(Widget*_parentwidget,int _playernum)
    : playernum(_playernum),interval(6/playernum),parentwidget(_parentwidget)
{
    //负索引实现
    memset(space,0,sizeof(space));
    int i;
        for (i = 0; i < 17; i++)
            p1[i] = space[i] + 8;
    grid = p1 + 8;
//initialize
    players.clear();
    winnerlist.clear();
    loserlist.clear();
    for(i=1;i<=6;i+=interval)
        players.push_back(new Player(i,this));

}

Board::~Board()
{
for(Player*player:players)
    delete player;
players.clear();
}

void Board::pass_to_nextplayer(int currentidx)
{
    if(winnerlist.size()+loserlist.size()<(unsigned)playernum)
    {
        int nextidx=(currentidx+1)%playernum;
        while(players[nextidx]->mode==2)
        {
            nextidx=(nextidx+1)%playernum;
        }
        emit step();
        set_activatedplayer(nextidx);
    }
    else
    {
    }
}

void Board::set_activatedplayer(int idx)
{
        players[idx]->searchHintPoints();
        players[idx]->mode=1;
}

void Board::unset_activatedplayer(int idx)
{
    for(Marble*m:players[idx]->marbles)
    {
        m->hint_points.clear();
        m->fromidxes.clear();
    }
    players[idx]->mode=0;
}

