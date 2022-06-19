#include "widget.h"
#include "ui_widget.h"
#include<AI.h>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
   ui->setupUi(this);
   this->setWindowTitle("中国跳棋");

   ui->timer->setDigitCount(2);
   ui->Round_num->setText("0");
   ui->AI->setDisabled(true);
   ui->show_last->setDisabled(true);

   socket=new NetworkSocket(new QTcpSocket,this);
   c_connect.show();

   connect(&c_connect,SIGNAL(info(QString,QString)),this,SLOT(toserver(QString,QString)));
   connect(socket, SIGNAL(receive(NetworkData)), this, SLOT(receiveinfo(NetworkData)));//接受服务端发来的消息
   connect(socket->base(), &QAbstractSocket::disconnected, [=]()
   {
       QMessageBox::critical(this, tr("Connection lost"), tr("Connection to server has closed"));
   });
   connect(socket->base(), &QAbstractSocket::errorOccurred, this, &Widget::displayError);
   connect(socket->base(), &QAbstractSocket::connected, this, &Widget::connected);
   connect(&myroom,SIGNAL(leave()),this,SLOT(c_leave()));//接受退出房间信号
   connect(&c_timer,SIGNAL(timeout()),this,SLOT(update_time()));//刷新时间
   connect(&showlast,SIGNAL(showlast(int)),this,SLOT(show_last_step(int)));

   memset(&isover,0,6*sizeof (int));
   step=0;

}

Widget::~Widget()
{
    delete ui;
}

 void Widget::on_startplay_clicked()
{
     if(isconnected)
     {
    room_opt.show();
    connect(&room_opt,SIGNAL(inroom(QString,QString)),this,SLOT(c_inroom(QString ,QString )));
    connect(&room_opt,SIGNAL(beready()),this,SLOT(c_beready()));
     }
     else
     {
         QMessageBox::about(this, tr("客户端提示"), tr("请先连接服务器！"));
     }
}

void Widget::on_pushButton_clicked()
{
    set.show();
}

void Widget::displayError()
{
    QMessageBox::critical(this, tr("Error"), tr("An error has occurred!"));
}

void Widget::connected()
{
     QMessageBox::about(this, tr("服务器提示"), tr("连接服务器成功！"));
     c_connect.hide();
     isconnected=true;
}

void Widget::toserver(QString ip,QString port)
{
    socket->hello(ip,port.toInt());
}

void Widget::c_inroom(QString a,QString b)
{
    room_num=a;
    c_you=b;
    nickname=b;
    NetworkData p(OPCODE::JOIN_ROOM_OP,a,b);
    socket->send(p);
}

void Widget::c_beready()
{
    NetworkData p(OPCODE::PLAYER_READY_OP,c_you,0);
    socket->send(p);
}

void Widget::c_leave()
{
    room_opt.recover();
    NetworkData p(OPCODE::LEAVE_ROOM_OP,room_num,c_you);
    socket->send(p);
}

void Widget::update_time()
{
    if(c_time)
    ui->timer->display(QString::number(--c_time,10));
}

void Widget::LCDclear()
{
    c_timer.stop();
    ui->timer->display("0");
}

void Widget::setlocalplayer(int k)
{
    ui->player->setText(places[k]);
    switch (k)
    {
   case 0:
    {
        ui->player->setStyleSheet("color:blue;");
        break;
    }
   case 1:
    {
        ui->player->setStyleSheet("color:red;");
        break;
    }

    case 2:
        {
            ui->player->setStyleSheet("color:yellow;");
            break;
        }
    case 3:
        {
            ui->player->setStyleSheet("color:orange;");
            break;
        }
    case 4:
        {
            ui->player->setStyleSheet("color:green;");
            break;
        }
    case 5:
        {
            ui->player->setStyleSheet("color:purple;");
            break;
        }
    }
}

void Widget::receiveinfo(NetworkData data)
{

    if(data.op==OPCODE::JOIN_ROOM_OP)//JOIN_ROOM_OP
    {
        QString cc_you=data.data1;
        QString cc_order=data.data2;
        myroom.situation(cc_you,cc_order.toInt());
    }

    if(data.op==OPCODE::JOIN_ROOM_REPLY_OP)//JOIN_ROOM_REPLY_OP
    {
        QMessageBox::about(this, tr("服务器提示"), tr("进入房间成功！"));
        QStringList names=data.data1.split(" ");
        int r;
        for(r=0;r<=names.size()-1;r++)
        {
            myroom.situation(names[r],r+1);//获取之前进入玩家的名字
        }
        myroom.situation(c_you,r);
        for(int s=1;s<=data.data2.size();s++)
        {
            myroom.setready(data.data2[s-1],s);//获取之前进入玩家的状态
        }
        myroom.show();
    }

    if(data.op==OPCODE::LEAVE_ROOM_OP)//LEAVE_ROOM_OP
    {
        myroom.person_leave(data.data2);
    }

    if(data.op==OPCODE::PLAYER_READY_OP)//PLAYER_READY_OP
    {
        myroom.setready(data.data1);
    }

    if(data.op==OPCODE::START_GAME_OP)//START_GAME_OP
    {
        //准备分配区域开始游戏
        ui->AI->setDisabled(false);
        ui->show_last->setDisabled(false);
        playnumber=(data.data2.size()+1)/2;
        board=new Board(this,playnumber);
        ui->startplay->hide();
        NicknameList=data.data1.split(" ");
        NicknameList.removeAll(QString(" "));
        NicknameList.removeAll(QString(""));
        RegionList=data.data2.split(" ");
        RegionList.removeAll(QString(""));
        RegionList.removeAll(QString(" "));


        CharIdx=RegionList[NicknameList.indexOf(nickname)];
        OldPlayersIdx=(CharIdx[0].toLatin1()-'A')/board->interval;
        OldRegionIdx=(CharIdx[0].toLatin1()-'A'+1);


        if(playnumber==2)
        {
            e.append("0");
            e.append("3");
        }
        if(playnumber==3)
        {
            e.append("0");
            e.append("2");
            e.append("4");
        }
        if(playnumber==6)
        {
            e.append("0");
            e.append("1");
            e.append("2");
            e.append("3");
            e.append("4");
            e.append("5");
        }

        int temp='D'-CharIdx[0].toLatin1();
        setlocalplayer((temp+6)%6);

    }

    if(data.op==OPCODE::START_TURN_OP)//START_TURN_OP
    {
        int over=0;
        for(int i=0;i<=5;i++)
        {
            if(isover[i]==1)
                over++;
        }
        if(over+1==playnumber)
            return;

        QString now = QString::number(QDateTime::currentMSecsSinceEpoch()/1000);
        c_time=15-now.toInt()+data.data2.toInt();
        ui->timer->display(QString::number(c_time,10));
        c_timer.setInterval(1000);
        c_timer.start();
        if(board->players[0]->win())
        {
            board->players[0]->set_winstate();
            NetworkData s(OPCODE::END_TURN_OP,0,0);
            socket->send(s);//向服务器发送END_TURN_OP
            return;
        }
        if(!isAI)
        board->set_activatedplayer(0);
        else
        {
            board->players[0]->searchHintPoints();
            runAI();//执行AI代码，返回path
        }
    }

    if(data.op==OPCODE::MOVE_OP)//MOVE_OP
    {
        //移动别人当前回合走的棋子
        step++;
        QString str=QString::number(step,10);
        ui->Round_num->setText(str);//上面是修改Step的数值

        int CurrentPlayerIdx=(data.data1[0].toLatin1()-'A')/board->interval;//获取当前玩家的索引
        int newCurrentPlayerIdx=(CurrentPlayerIdx-OldPlayersIdx+playnumber)%playnumber;
        if(data.data2=="-1")
        {
            //移除此区域所有棋子
            board->players[newCurrentPlayerIdx]->set_loserstate();
            isover[newCurrentPlayerIdx]=1;
            ui->AI->setCheckable(false);//关闭AI按钮
        }
        else
        {
            std::vector<QPoint> MovePath;//移动路径
            Data2ToPath(MovePath,data.data2,OldRegionIdx);//调用函数，通过字符串的信息将路径以QPoint存在MovePath里，其中MovePath[0]是目标点，MovePath.back()是出发点
            board->players[newCurrentPlayerIdx]->LatestPath=MovePath;
            unsigned int MovedMarbleIdx;//将要移动的棋子在player::marbles的索引
            for(MovedMarbleIdx=0;MovedMarbleIdx<board->players[newCurrentPlayerIdx]->marbles.size();MovedMarbleIdx++)
               {
               //依次遍历std::vector<Marble*> marbles里的所有棋子，找到坐标对应和MovePath里存的出发点相同的那一个，然后移动这个棋子，结束循环
               if(board->players[newCurrentPlayerIdx]->marbles[MovedMarbleIdx]->boardposition==MovePath.back())
               {
                   board->players[newCurrentPlayerIdx]->marbles[MovedMarbleIdx]->jumpto(MovePath);//
                   break;
               }
               }
            if(0==newCurrentPlayerIdx&&board->players[newCurrentPlayerIdx]->win())//判断自己是否胜利
            {
                board->players[newCurrentPlayerIdx]->set_winstate();
                NetworkData s(OPCODE::END_TURN_OP,0,0);
                this->socket->send(s);//发送结束请求
                ui->AI->setCheckable(false);//关闭AI按钮
            }
        }

       int temp='D'-CharIdx[0].toLatin1();//转换视角参数
        for(int m=0;m<=e.size()-1;m++)//检测当前所有玩家中获胜者
        {
            if(board->players[m]->win())
            {
                isover[e[m].toInt()]=1;
            }
        }

        int flag=0;
        for(int m=0;m<=e.size()-1;m++)
        {
            if(!(isover[e[m].toInt()]))
            {
                flag=1;
                break;
            }
        }

        if(flag==1)
        {
        int ss=(CurrentPlayerIdx+1)%playnumber;
        while(isover[e[ss].toInt()])
        {
            ss=(ss+1)%playnumber;
        }
        setlocalplayer((e[ss].toInt()+temp+6)%6);
        }

    }

    if(data.op==OPCODE::END_GAME_OP)//END_GAME_OP
    {
        if(data.data1!="")
        {
            QStringList rank=data.data1.split(" ");
            for(int r=0;r<=rank.size()-1;r++)
            {
                ranks.setrank(r+1,rank[r]);
            }
        }
        ranks.show();
        room_opt.recover();
        c_timer.stop();
    }

    if(data.op==OPCODE::ERROR_OP)//ERROR_OP
    {
        if(data.data1==QString::number((int)ERRCODE::INVALID_JOIN))
        {
        QMessageBox::about(this, tr("服务器提示"), tr("用户名已存在！"));
        room_opt.recover();
        }
        if(data.data1==QString::number((int)ERRCODE::INVALID_REQ))
        {
        QMessageBox::about(this, tr("服务器提示"), tr("非法请求！"));
        }
        if(data.data1==QString::number((int)ERRCODE::ROOM_IS_RUNNING))
        {
        QMessageBox::about(this, tr("服务器提示"), tr("房间正在游戏中，不能进入！"));
        }
    }
}

void Widget::on_AI_clicked()
{

    if(ui->AI->text()=="打开托管")
    {
        ui->AI->setText("关闭托管");
        isAI=true;
        if(c_timer.isActive())//在自己回合内打开托管按钮
        {
            if(board->players[0]->selected_marble)
            {
                board->players[0]->selected_marble->unset_highlight();
                board->players[0]->clear_hint_btn();
            }
            runAI();//调用AI函数
        }
    }
    else if(ui->AI->text()=="关闭托管")
    {
        ui->AI->setText("打开托管");
        isAI=false;
    }
}

void Widget::runAI()
{
    std::vector<QPoint> _path;
    AI *ai = new AI(board->players);
    board->players[0]->mode=0;
    _path = ai->use();
    {
        QString data2=PathToData2(_path,OldRegionIdx);
        NetworkData p(OPCODE(200007),CharIdx,data2);
        socket->send(p);
        board->players[0]->path.clear();
        board->players[0]->selected_marble=nullptr;
        board->unset_activatedplayer(0);
        LCDclear();
    }
    delete ai;
}

void Widget::on_show_last_clicked()
{
    if(playnumber==2)
    {
        showlast.in(1);
        showlast.in(4);
    }
    if(playnumber==3)
    {
        showlast.in(1);
        showlast.in(3);
        showlast.in(5);
    }
    if(playnumber==6)
    {
        showlast.in(1);
        showlast.in(2);
        showlast.in(3);
        showlast.in(4);
        showlast.in(5);
        showlast.in(6);
    }
    showlast.show();
}

void Widget::show_last_step(int k)
{
    int s=(k-1)/playnumber;
    if(board->players[s]->LatestPath.empty())
    {
        QMessageBox::about(this, tr("客户端提示"), tr("该玩家未行动！"));
        return;
    }
    board->players[s]->show_last_step();
}
