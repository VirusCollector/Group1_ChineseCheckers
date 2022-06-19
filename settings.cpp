#include"settings.h"
#include<QPoint>
#include<QDebug>
//将boardposition转化为像素坐标
QPoint BoardToPixel(QPoint boardposition)
{
    QPoint ret;
    myswap(boardposition.rx(),boardposition.ry());
    ret.rx()=qRound(unit/2*(boardposition.x()-boardposition.y()));
    ret.ry()=qRound(unit*0.866*(boardposition.x()+boardposition.y()));
    ret+=origin;
    return ret;
}

QPoint pixelToBoard(QPoint pixelposition)
{
    QPoint ret;
    pixelposition-=origin;
    ret.rx()=qRound((1.732*pixelposition.x()+pixelposition.y())/1.732/unit);
    ret.ry()=qRound((-1.732*pixelposition.x()+pixelposition.y())/1.732/unit);
    myswap(ret.rx(),ret.ry());
    return ret;//
}

QPoint BaseTransformation(int from,int to,QPoint Point_in)
{
    int idx=from>=to?from-to:from+6-to;
    QPoint Point_out;
    myswap(Point_in.rx(),Point_in.ry());
    Point_out.rx()=Point_in.x()*matrix[idx][0][0]+Point_in.y()*matrix[idx][1][0];
    Point_out.ry()=Point_in.x()*matrix[idx][0][1]+Point_in.y()*matrix[idx][1][1];
    myswap(Point_out.rx(),Point_out.ry());
    return Point_out;
}

bool isinboard(QPoint p)
{
    return (p.x()<=4&&p.y()<=4&&p.x()+p.y()>=-4)||(p.x()>=-4&&p.y()>=-4&&p.x()+p.y()<=4);
}


void setstate(int **arr, QPoint p, int va)
{
arr[p.x()][p.y()]=va;
}

int getstate(int **arr, QPoint p)
{
return arr[p.x()][p.y()];
}
//将像素坐标转换为和棋子大小匹配的QRect
QRect pixelToRect(QPoint pixelposition,int _halflen)
{
QRect ret(pixelposition.x()-_halflen,pixelposition.y()-_halflen,2*_halflen,2*_halflen);
return ret;
}

QString PathToData2(std::vector<QPoint>& _path,int OldRegionIdx)
{
    QString data2;
    for(QPoint point:_path)
    {
        point=BaseTransformation(OldRegionIdx,3,point);
        data2=QString::number(point.x(), 10)+" "+QString::number(point.y(), 10)+" "+data2;
    }
    data2=data2.left(data2.size()-1);
    return data2;
}

void Data2ToPath(std::vector<QPoint>& _path, QString data2,int OldRegionIdx)
{
    QStringList pathlist=data2.split(" ");
    pathlist.removeAll("");
    pathlist.removeAll(" ");
    int i;
    for(i=0;i<pathlist.size();i+=2)
    {
        QPoint point(pathlist[i].toInt(),pathlist[i+1].toInt());
        point=BaseTransformation(3,OldRegionIdx,point);
        _path.insert(_path.begin(),point);
    }
}
