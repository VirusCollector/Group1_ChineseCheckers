#include<QObject>
#include<AI.h>
#include"player.h"
#include<vector>
#include<all_settings.h>
#include<stdlib.h>
#include"marble.h"
#include<math.h>
#include <algorithm>
#include<board.h>
#include<widget.h>
int _n = 4;//在这里修改托管的搜索深度（取值范围：0 <= n <= 14 && n==Z+ && n % the number of players == 0!)


using std::vector;
int _board[17][17];//oversave the marbles' place in AI;
bool will_win = false;//我方有超过八个棋子进入了大营
QPoint last_step;//上一步的起始位置
int last_marble;//上一次的棋子编号
bool has_full = false;//最内部的三个点已经填满
int difficult_marbles[10];//尚未进入敌方内部的棋子编号
int sizeof_diff_mar;//未进入对面大营的棋子个数
const QPoint nextl[3] = {QPoint(-1,0),QPoint(0,-1),QPoint(-1,1)};//if the place is too close to left, stop this chess to go left in search;
const QPoint nextr[3] = {QPoint(-1,0),QPoint(0,-1),QPoint(1,-1)};
const QPoint nextm[4] = {QPoint(-1,0),QPoint(0,-1),QPoint(1,-1),QPoint(-1,1)};

double max(double a,double b)
{
    if(a>=b) return a;
    return b;
}

void search_hint_point(vector<Player*> players,int who, int num)//overload the search_place function in AI;
{
    int flag = 0;
    if(who == 0 && has_full == true)//if the place(4,4)\(4,3)\(3,4)has full, there is no need to move the marbles that has be in.
    {
        for(int i = 0;i<sizeof_diff_mar;i++)
        {
            if(num == difficult_marbles[i])
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            players[who]->marbles[num]->fromidxes.push_back(-1);
            players[who]->marbles[num]->hint_points.push_back(players[who]->marbles[num]->boardposition);
            return;
        }
    }

    memset(_board,0,sizeof(_board));
    if(who == 0 && (will_win == true || last_marble == num))//if the chess has moved last time, it's no use to walk backward.
    {
        _board[last_step.x()+8][last_step.y()+8] = 2;
    }
    if(who == 0 && last_step.x() == last_step.y())//but if the chess is in the middle line, it is need because the other place maybe not suitable.
    {
        _board[last_step.x()+8][last_step.y()+8] = 0;
    }


    for(Player* i:players)
    {
        for(Marble* p:i->marbles)//save the chess board in AI;
        {
            _board[p->boardposition.x()+8][p->boardposition.y()+8] = -1;//-1表示有棋子了；0表示空位;1表示可以加入hintpoint的点；2表示是上次走过的位置
        }
    }


    QPoint hintpoint;//use BFS to search for the place that that this marble could move to.
    players[who]->marbles[num]->fromidxes.push_back(-1);
    players[who]->marbles[num]->hint_points.push_back(players[who]->marbles[num]->boardposition);


    int rear = 0,front = 0;//according the place the marble set, use different search function to prune.
    if(who == 0 && will_win == true&&players[who]->marbles[num]->boardposition.x() > players[who]->marbles[num]->boardposition.y())
    {
        qDebug()<<"OK1";
        while(front<=rear)
        {
            hintpoint = players[who]->marbles[num]->hint_points[front++];
            for(int i=0;i<3;i++)
            {
                if(isinboard(hintpoint+nextl[i]*2)&&_board[hintpoint.x()+nextl[i].x()*2+8][hintpoint.y()+nextl[i].y()*2+8] == 0&&_board[hintpoint.x()+nextl[i].x()+8][hintpoint.y()+nextl[i].y()+8] == -1)
                {
                    players[who]->marbles[num]->hint_points.push_back(hintpoint+nextl[i]*2);
                    _board[hintpoint.x()+nextl[i].x()*2+8][hintpoint.y()+nextl[i].y()*2+8] = 1;
                    players[who]->marbles[num]->fromidxes.push_back(front-1);
                    rear++;
                }
            }
        }
        hintpoint = players[who]->marbles[num]->boardposition;
        for(int i=0;i<3;i++)
        {
            if(isinboard(hintpoint+nextl[i])&&_board[hintpoint.x()+nextl[i].x()+8][hintpoint.y()+nextl[i].y()+8]==0)
            {
                players[who]->marbles[num]->hint_points.push_back(hintpoint+nextl[i]);
                _board[hintpoint.x()+nextl[i].x()+8][hintpoint.y()+nextl[i].y()+8] = 1;
                players[who]->marbles[num]->fromidxes.push_back(0);
            }
        }
    }
    else if(who == 0&&will_win == true&&players[who]->marbles[num]->boardposition.x() < players[who]->marbles[num]->boardposition.y())
    {
        qDebug()<<"OK2";
        while(front<=rear)
        {
            hintpoint = players[who]->marbles[num]->hint_points[front++];
            for(int i=0;i<3;i++)
            {
                if(isinboard(hintpoint+nextr[i]*2)&&_board[hintpoint.x()+nextr[i].x()*2+8][hintpoint.y()+nextr[i].y()*2+8] == 0&&_board[hintpoint.x()+nextl[i].x()+8][hintpoint.y()+nextl[i].y()+8] == -1)
                {
                    players[who]->marbles[num]->hint_points.push_back(hintpoint+nextr[i]*2);
                    _board[hintpoint.x()+nextr[i].x()*2+8][hintpoint.y()+nextr[i].y()*2+8] = 1;
                    players[who]->marbles[num]->fromidxes.push_back(front-1);
                    rear++;
                }
            }
        }
        hintpoint = players[who]->marbles[num]->boardposition;
        for(int i=0;i<3;i++)
        {
            if(isinboard(hintpoint+nextr[i])&&_board[hintpoint.x()+nextr[i].x()+8][hintpoint.y()+nextr[i].y()+8]==0)
            {
                players[who]->marbles[num]->hint_points.push_back(hintpoint+nextr[i]);
                _board[hintpoint.x()+nextr[i].x()+8][hintpoint.y()+nextl[i].y()+8] = 1;
                players[who]->marbles[num]->fromidxes.push_back(0);
            }
        }
    }
    else if(who == 0&&will_win == true&&players[who]->marbles[num]->boardposition.x() == players[who]->marbles[num]->boardposition.y())
    {
        while(front<=rear)
        {
            hintpoint = players[who]->marbles[num]->hint_points[front++];
            for(int i=0;i<4;i++)
            {
                if(isinboard(hintpoint+nextm[i]*2)&&_board[hintpoint.x()+nextm[i].x()*2+8][hintpoint.y()+nextm[i].y()*2+8] == 0&&_board[hintpoint.x()+nextl[i].x()+8][hintpoint.y()+nextl[i].y()+8] == -1)
                {
                    players[who]->marbles[num]->hint_points.push_back(hintpoint+nextm[i]*2);
                    _board[hintpoint.x()+nextm[i].x()*2+8][hintpoint.y()+nextm[i].y()*2+8] = 1;
                    players[who]->marbles[num]->fromidxes.push_back(front-1);
                    rear++;
                }
            }
        }
        hintpoint = players[who]->marbles[num]->boardposition;
        for(int i=0;i<4;i++)
        {
            if(isinboard(hintpoint+nextm[i])&&_board[hintpoint.x()+nextm[i].x()+8][hintpoint.y()+nextm[i].y()+8]==0)
            {
                players[who]->marbles[num]->hint_points.push_back(hintpoint+nextm[i]);
                _board[hintpoint.x()+nextm[i].x()+8][hintpoint.y()+nextm[i].y()+8] = 1;
                players[who]->marbles[num]->fromidxes.push_back(0);
            }
        }
    }
    else
    {
        while(front<=rear)
        {
            hintpoint = players[who]->marbles[num]->hint_points[front++];
            for(int i=0;i<6;i++)
            {
                if(isinboard(hintpoint+next[i]*2)&&_board[hintpoint.x()+next[i].x()*2+8][hintpoint.y()+next[i].y()*2+8] == 0&&_board[hintpoint.x()+next[i].x()+8][hintpoint.y()+next[i].y()+8] == -1)
                {
                    players[who]->marbles[num]->hint_points.push_back(hintpoint+next[i]*2);
                    _board[hintpoint.x()+next[i].x()*2+8][hintpoint.y()+next[i].y()*2+8] = 1;
                    players[who]->marbles[num]->fromidxes.push_back(front-1);
                    rear++;
                }
            }
        }
        hintpoint = players[who]->marbles[num]->boardposition;
        for(int i=0;i<6;i++)
        {
            if(isinboard(hintpoint+next[i])&&_board[hintpoint.x()+next[i].x()+8][hintpoint.y()+next[i].y()+8]==0)
            {
                players[who]->marbles[num]->hint_points.push_back(hintpoint+next[i]);
                _board[hintpoint.x()+next[i].x()+8][hintpoint.y()+next[i].y()+8] = 1;
                players[who]->marbles[num]->fromidxes.push_back(0);
            }
        }
    }


}

double AI::get_value2(std::vector<Player*> player)//2-players' value function.
{
    double ad_score = 0;
    double sub_score = 0;

    for(int i=0;i<10;i++)//use the place of the other player's marbles to judge when now is;
    {
        sub_score-=player[1]->marbles[i]->playerposition.x()+ player[1]->marbles[i]->playerposition.y();
    }


    if(sub_score>0)//对面已走半场以上
    {
        for(int i=0;i<10;i++)
        {
            ad_score-=(player[0]->marbles[i]->playerposition.x()+player[0]->marbles[i]->playerposition.y())*2.5;//放大差异
            if(player[0]->marbles[i]->playerposition.x()+player[0]->marbles[i]->playerposition.y()<-4)//if the marble has arrive, give it other reward.
            {
                ad_score+=5-1.2*(player[0]->marbles[i]->playerposition.x()+player[0]->marbles[i]->playerposition.y());
            }
        }
    }

    else
    {
        for(int i=0;i<10;i++)//在自己家里是正
        {
            ad_score-=(player[0]->marbles[i]->playerposition.x()+player[0]->marbles[i]->playerposition.y())*1.1;//also use the point to give value.
            if(player[0]->marbles[i]->playerposition.x()+player[0]->marbles[i]->playerposition.y()>4)//if the chess still not leave, give it a punishment.
                ad_score-=0.4*pow((player[0]->marbles[i]->playerposition.x()+player[0]->marbles[i]->playerposition.y()-4),2)+0.7*(player[0]->marbles[i]->playerposition.x()+player[0]->marbles[i]->playerposition.y());
        }
    }

    for(int i=0;i<10;i++)//偏离中线给予惩罚
    {
        if(fabs(player[0]->marbles[i]->playerposition.x()-player[0]->marbles[i]->playerposition.y())>3)
        {
            ad_score-=fabs(player[0]->marbles[i]->playerposition.x()-player[0]->marbles[i]->playerposition.y())*0.4;
        }
    }

    return ad_score-sub_score*0.5;
}

double AI::get_value3(std::vector<Player*> player)//3-players' value function.
{
    double my_score = 0;
    double a_score = 0;
    double b_score = 0;

    for(int i=0;i<10;i++)//use the place of the other player's marbles to judge when now is;
    {
        a_score -= player[1]->marbles[i]->playerposition.x()+ player[1]->marbles[i]->playerposition.y();
        b_score -= player[2]->marbles[i]->playerposition.x()+ player[2]->marbles[i]->playerposition.y();
    }

    if(max(a_score,b_score)>0)
    {
        for(int i=0;i<10;i++)
        {
            my_score-=(player[0]->marbles[i]->playerposition.x()+player[0]->marbles[i]->playerposition.y())*1.2;//放大差异
            if(player[0]->marbles[i]->playerposition.x()+player[0]->marbles[i]->playerposition.y()>0)//未到达对岸的给予惩罚
            {
                my_score-=3+1.5*(player[0]->marbles[i]->playerposition.x()+player[0]->marbles[i]->playerposition.y());
            }
            if(player[0]->marbles[i]->playerposition.x()+player[0]->marbles[i]->playerposition.y()<-4)//if the marble has arrive, give it other reward.
            {
                my_score+=5-1.2*(player[0]->marbles[i]->playerposition.x()+player[0]->marbles[i]->playerposition.y()+4);
            }
        }
    }

    else
    {
        for(int i=0;i<10;i++)
        {
            my_score-=(player[0]->marbles[i]->playerposition.x()+player[0]->marbles[i]->playerposition.y())*1.05;//also use the point to give value.
            if(player[0]->marbles[i]->playerposition.x()+player[0]->marbles[i]->playerposition.y()>4)//if the chess still not leave, give it a punishment.
                my_score-=1+0.8*(player[0]->marbles[i]->playerposition.x()+player[0]->marbles[i]->playerposition.y());
        }
    }

    for(int i=0;i<10;i++)
    {
        if(fabs(player[0]->marbles[i]->playerposition.x()-player[0]->marbles[i]->playerposition.y())>3)
        {
            my_score-=fabs(player[0]->marbles[i]->playerposition.x()-player[0]->marbles[i]->playerposition.y())*0.15;
        }
    }

    return my_score-0.25*(a_score+b_score);
}

double AI::get_value6(std::vector<Player*> player)//6-players' value function.
{
    double ad_score = -5;
    double ag_score = 0;
    double oth_score[4] = {0};

    for(int i=0;i<10;i++)
    {
        ag_score-=player[3]->marbles[i]->playerposition.x()+ player[3]->marbles[i]->playerposition.y();
        if(player[3]->marbles[i]->playerposition.x()+player[3]->marbles[i]->playerposition.y()>4)
        {
            ag_score-=1;
        }
        if(player[3]->marbles[i]->playerposition.x()+player[3]->marbles[i]->playerposition.y()<-4)
        {
            ad_score+=1;
        }
        for(int j = 0;j<2;j++)
        {
            oth_score[j] -= player[j+1]->marbles[i]->playerposition.x()+player[j+1]->marbles[i]->playerposition.y();
            if(player[j+1]->marbles[i]->playerposition.y()>4) oth_score[j]-=1;
        }
        for(int j = 2;j<4;j++)
        {
            oth_score[j] -= player[j+1]->marbles[i]->playerposition.x()+player[j+1]->marbles[i]->playerposition.y();
            if(player[j+1]->marbles[i]->playerposition.y()>4) oth_score[j]-=1;
        }
    }

    if(ag_score>0)
    {
        for(int i=0;i<10;i++)
        {
            ad_score-=(player[0]->marbles[i]->playerposition.x()+player[0]->marbles[i]->playerposition.y())*1.2;//放大差异
            if(player[0]->marbles[i]->playerposition.x()+player[0]->marbles[i]->playerposition.y()>4)//未到达对岸的给予惩罚
            {
                ad_score+=5-1.5*(player[0]->marbles[i]->playerposition.x()+player[0]->marbles[i]->playerposition.y()-4);
            }
            if(player[0]->marbles[i]->playerposition.x()+player[0]->marbles[i]->playerposition.y()<-4)
            {
                ad_score-=3+1.1*(player[0]->marbles[i]->playerposition.x()+player[0]->marbles[i]->playerposition.y()+4);
            }
        }
    }

    else
    {
        for(int i=0;i<10;i++)
        {
            ad_score+=(player[0]->marbles[i]->playerposition.x()+player[0]->marbles[i]->playerposition.y())*1.05;
            if(player[0]->marbles[i]->playerposition.x()+player[0]->marbles[i]->playerposition.y()>4)
                ad_score+=1-0.8*(player[0]->marbles[i]->playerposition.x()+player[0]->marbles[i]->playerposition.y()-4);
        }
    }

    for(int i=0;i<10;i++)
    {
        if(abs(player[0]->marbles[i]->playerposition.x()-player[0]->marbles[i]->playerposition.y())>3)
        {
            ad_score+=abs(player[0]->marbles[i]->playerposition.x()-player[0]->marbles[i]->playerposition.y())*0.4;
        }
    }

    return ad_score - 0.5 * ag_score - (oth_score[0]+oth_score[1]+oth_score[2])/6;
}

int AI::alpha_beta(std::vector<Player*> now,int alpha,int beta,int depth,int num)
{
    int value = 0;

    if(!depth)//has arrived the depth, need to use value function to get value.
    {
        if(num == 2)
        {
            return get_value2(now);
        }
        if(num == 3)
        {
            return get_value3(now);
        }
        if(num == 6)
        {
            return get_value6(now);
        }
    }

    for(int i=0;i<10;i++)//it's depth%num's turn, who has ten marbles.
    {

        now[(depth-1)%num]->marbles[i]->hint_points.clear();
        search_hint_point(now,(depth-1)%num,i);//search for the point that it can move, and save it in the hint_points;

        for(unsigned int j = 1;j < now[(depth-1)%num]->marbles[i]->hint_points.size();j++)//the ith has j ways to move.
        {

            std::vector<Player*> next;
            for(int k = 0;k<num;k++)//set a new board for this way.
            {
                next.push_back(new Player(now[k],i,now[(depth-1)%num]->marbles[i]->hint_points[j],(k == ((depth-1)%num))));
            }

            if(next[0]->win() == true)//if he will win, this way will be the best.
            {
                return 10000;
            }


            if((depth-1)%num == 0||(depth-1)%num == 1)//if the aim between this player and the next will change, use alpha to be beta and let beta be alpha.
            {
                value = -alpha_beta(next, -beta, -alpha, depth-1, num);
                alpha = (alpha>value)? value: alpha;
                if(alpha>= beta) return alpha;
            }
            else//or keep this aim to move.
            {
                value = alpha_beta(next, alpha, beta, depth-1, num);
                alpha = (alpha>value)? alpha:value;
                if(alpha>= beta) return alpha;
            }


            for(unsigned int is = 0;is < next.size();is++)
            {
                delete next[is];
            }
            next.clear();
        }
    }
    return alpha;
}

std::vector<QPoint> AI::use()//每次用吐一步，需要多次调用。
{
    std::vector<QPoint>_path;
    double max = -100000;
    QPoint best;
    int number;
    double temp;

    int flag = 0;
    int num_of_in = 0;
    memset(difficult_marbles,0,sizeof(difficult_marbles));

    for(int i=0;i<10;i++)
    {
        if(players[0]->marbles[i]->playerposition.x()+players[0]->marbles[i]->playerposition.y()>=-4)//save the marble that still didn't be in;
        {
            difficult_marbles[flag++] = i;
        }
        if(players[0]->marbles[i]->playerposition.x()+players[0]->marbles[i]->playerposition.y()<-6)//check the special place(4,4)(4,3)(3,4);
        {
            num_of_in++;
        }
    }
    if(flag<2)//only 1 chess that not be in;
    {
        will_win = true;
    }
    if(num_of_in == 3)//the point (4,4)(4,3)(3,4) has full.
    {
        has_full = true;
        sizeof_diff_mar = flag;
    }

    for(int i=0;i<10;i++)//展开第i个棋子的所有走法
    {

        players[0]->marbles[i]->hint_points.clear();
        search_hint_point(players,0,i);//search for the way this marble could move and save it in hint_points;

        for(unsigned int j = 1;j<players[0]->marbles[i]->hint_points.size();j++)
        {

            std::vector<Player*> now;
            if(num_of_players != 2){_n = 0;}
            for(int k = 0 ;k < num_of_players;k++)//save the board of this time in this place;
            {
                now.push_back(new Player(players[k],i,players[0]->marbles[i]->hint_points[j],!k));
            }

            temp = alpha_beta(now,20000,-20000,_n,num_of_players);//use alpha_beta function to get the score of this step;

            if(temp>max)//if this step is best, save it;
            {
                max = temp;
                number = i;
                best = players[0]->marbles[i]->hint_points[j];
            }
            for(Player* p : now)
            {
                delete p;
            }
        }
    }

    last_marble = number;//save the message of last step for pruning.
    last_step = players[0]->marbles[number]->boardposition;

    //get the path of the marble move instead of the point for animation.
    int iter;
    players[0]->marbles[number]->hint_points.clear();
    search_hint_point(players,0,number);
    for(unsigned int i=0;i<players[0]->marbles[number]->hint_points.size();i++)
    {
        if(players[0]->marbles[number]->hint_points[i] == best)
        {
            iter = i;
            while(iter!=-1)
            {
                _path.push_back(players[0]->marbles[number]->hint_points[iter]);
                iter = players[0]->marbles[number]->fromidxes[iter];
            }
            break;
        }
    }

    return _path;
}

