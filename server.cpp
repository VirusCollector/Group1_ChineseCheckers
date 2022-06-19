#include "server.h"
#include "ui_server.h"

server::server(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::server)
{
    ui->setupUi(this);
    this->setWindowTitle("myServer");
    myserver = new NetworkServer(this);
    myserver->listen(QHostAddress::Any, 9888);
    connect(myserver, SIGNAL(receive(QTcpSocket*, NetworkData)), this, SLOT(receiveData(QTcpSocket*, NetworkData)));
    connect(&myroom_1, SIGNAL(per(QString,int)), this, SLOT(update(QString,int)));
    connect(&myroom_1, SIGNAL(start_game(QString,int)), this, SLOT(start_game(QString,int)));

    timer =new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timeover()));
}

server::~server()
{
    delete ui;
}


void server::on_pushButton_2_clicked()
{
    myroom_1.show();
}

void server::update(QString a,int you)//向房间内其他玩家发送JOIN_ROOM_OP
{
    QString y=QString::number(you,10);
    NetworkData s(OPCODE::JOIN_ROOM_OP,a,y);
    for(int r=0;r<=inroom.size()-1;r++)
    {
        if(inroom[r]!=local)
        myserver->send(inroom[r],s);
    }

}

void server::receiveData(QTcpSocket* client, NetworkData data)//处理接收的信息
{
    if(data.op==OPCODE::JOIN_ROOM_OP)//JOIN_ROOM_OP
    {
        if(isingame)
        {
            NetworkData p(OPCODE::ERROR_OP,QString::number((int)ERRCODE::ROOM_IS_RUNNING),"1");//正在进行游戏
            myserver->send(client,p);
            return;
        }
        if(i<=5)
        {
            if(myroom_1.isexist(data.data2))
            {
                NetworkData p(OPCODE::ERROR_OP,QString::number((int)ERRCODE::INVALID_JOIN),"1");//用户名重复
                myserver->send(client,p);
                return;
            }
            local=client;
            inroom.append(client);
            QString ss=myroom_1.getnames();
            QString sp=myroom_1.getpres();
            NetworkData p(OPCODE::JOIN_ROOM_REPLY_OP,ss,sp);
            myserver->send(local,p);            //向该玩家发送JOIN_ROOM_REPLY_OP
            myroom_1.addplayer(data.data2,++i);
            //接update函数
        }
        else
        {
             qDebug()<<"Full!";//待补充人满错误码
        }
        return;
    }

    if(data.op==OPCODE::LEAVE_ROOM_OP)//LEAVE_ROOM_OP
    {

        myroom_1.person_delete(data.data2);
        for(int r=0;r<=inroom.size()-1;r++)
        {
            myserver->send(inroom[r],data);//向所有玩家发送LEAVE_ROOM_OP
        }
        inroom.remove(inroom.indexOf(client),1);
        i--;
        return;
    }

    if(data.op==OPCODE::PLAYER_READY_OP)//PLAYER_READY_OP
    {
           local=client;
           for(int r=0;r<=inroom.size()-1;r++)
           {
               myserver->send(inroom[r],data);//向所有玩家发送PLAYER_READY_OP
           }
           myroom_1.setready(data.data1);
           return;
    }

    if(data.op==OPCODE::MOVE_OP)//MOVE_OP
   {
       timer->stop();
       local=client;
       if(test(data.data2))
       {
           for(int r=0;r<=inroom.size()-1;r++)
           {
               myserver->send(inroom[r],data);//向其他玩家转发MOVE_UP
           }
       }
       if(winner.size()+loser.size()!=inroom.size()-1)//游戏未结束才进行下一步走棋
       {
        start_turns(++local_temp);
       }
        return;
   }

    if(data.op==OPCODE::END_TURN_OP)//END_TURN_OP
   {
       timer->stop();
       local=client;
       winner.append(client);
       if(winner.size()+loser.size()==inroom.size()-1)
       {
           for(int r=0;r<=inroom.size()-1;r++)
           {
               if(!winner.contains(inroom[r])&&!loser.contains(inroom[r]))
               {
                   winner.append(inroom[r]);
                   break;
               }
           }
           gameover();
           return;
       }
       return;
   }
    //非法请求
    NetworkData s(OPCODE::ERROR_OP,QString::number((int)ERRCODE::INVALID_REQ),"Invalid request!");
    myserver->send(client,s);
}

void server::start_game(QString gamers,int all)//START_GAME_OP
{
    isingame=true;
    QString place="";
   if(all==2)
       place+="A D";
   if(all==3)
       place+="A C E";
   if(all==6)
       place+="A B C D E F";
   NetworkData s(OPCODE::START_GAME_OP,gamers,place);
   for(int r=0;r<=all-1;r++)
   {
       myserver->send(inroom[r],s);
   }
   start_turns(local_temp);
}

void server::start_turns(int r)//START_TURN_OP
{
    if(r==inroom.size())
    {
        local_temp=0;
        start_turns(local_temp);
        return;
    }
    if(winner.contains(inroom[r])||loser.contains(inroom[r]))//已经赢了或者输了就不再给他传递走棋信号
    {
        start_turns(++local_temp);
        return;
    }

    QString sTime = QString::number(QDateTime::currentMSecsSinceEpoch()/1000);
    NetworkData turn(OPCODE::START_TURN_OP,0,sTime);
    myserver->send(inroom[r],turn);
    timer->start(15000);
}

void server::timeover()//MOVE_OP超时
{
    int r=local_temp;
    int s=inroom.size();
    QString local_area;
    local=inroom[r];
    loser.append(local);//加入败者列表

    if(r==0)
    {
        local_area="A";
    }
    if(r==1)
    {
        if(s==2)
            local_area="D";
        else if(s==3)
            local_area="C";
        else if(s==6)
            local_area="B";
    }
    if(r==2)
    {
        if(s==3)
            local_area="E";
        else if(s==6)
            local_area="C";
    }
    if(r==3)
        local_area="D";
    if(r==4)
        local_area="E";
    if(r==5)
        local_area="F";

    NetworkData timeout(OPCODE::MOVE_OP,local_area,"-1");
    for(int s=0;s<=inroom.size()-1;s++)
    {
        myserver->send(inroom[s],timeout);//向其他玩家转发MOVE_OP超时
    }
    timer->stop();
    if(winner.size()+loser.size()==inroom.size()-1)
    {
        for(int r=0;r<=inroom.size()-1;r++)
        {
            if(!winner.contains(inroom[r])&&!loser.contains(inroom[r]))
            {
                winner.append(inroom[r]);
                break;
            }
        }
        gameover();
        return;
    }
    start_turns(++local_temp);//让下一位玩家接着走
}

void server::gameover()//游戏结束
{
    isingame=false;
    QString list="";
    if(winner.size()!=0)
    {
        for(int r=0;r<=winner.size()-1;r++)
        {
            list+=myroom_1.getname(inroom.indexOf(winner[r])+1);
            list+=" ";
        }
    }
    NetworkData over(OPCODE::END_GAME_OP,list,0);
    for(int r=0;r<=inroom.size()-1;r++)
    {
        myserver->send(inroom[r],over);//向所有玩家发送END_GAME_OP
    }
}

bool server::test(QString p)
{
    QStringList ss=p.split(" ");
    int r=ss.size();
    if(r==4)
    {
        if((abs(ss[2].toInt()-ss[0].toInt())==1&&abs(ss[3].toInt()-ss[1].toInt())==1)||(abs(ss[2].toInt()-ss[0].toInt())==2&&abs(ss[3].toInt()-ss[1].toInt())==2))
            return true;
    }
    if(r>4)
    {
        for(int m=r-1;m>=3;m=m-2)
        {
            if(abs(ss[m].toInt()-ss[m-2].toInt())!=2)
                return true;
        }
        for(int m=r-2;m>=2;m=m-2)
        {
            if(abs(ss[m].toInt()-ss[m-2].toInt())!=2)
                return true;
        }
        return true;
    }
    return true;
}

