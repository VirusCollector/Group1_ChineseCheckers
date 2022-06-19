#ifndef SETTINGS_H
#define SETTINGS_H
#include<utility>
#include<QString>
#include<QPoint>
#include<QRect>
#include<QStringList>

const double unit=41.83;//boardposition下一个单位对应的像素点距离(相邻格子的像素点距离)
const QPoint origin(353,330);//棋盘中心点的像素坐标
const int halflen=30;//棋子的half像素边长
const int half_hintlen=15;//hint_btn的half像素边长
const QString color[8]={"hint",":images/pictures/orange.png",":images/pictures/green.png",":images/pictures/purple.png",":images/pictures/blue.png",":images/pictures/red.png",":images/pictures/yellow.png","highlighted"};
//区域i对应的棋子图片路径,0可以hint图片的路径(还没素材)
const int matrix[6][2][2]={{{1,0},{0,1}},{{1,-1},{1,0}},{{0,-1},{1,-1}},{{-1,0},{0,-1}},{{-1,1},{-1,0}},{{0,1},{-1,1}}};
//基变换矩阵
const QPoint next[6]={QPoint(1,0),QPoint(0,1),QPoint(-1,1),QPoint(-1,0),QPoint(0,-1),QPoint(1,-1)};
//相邻点坐标基(从右下开始顺时针到右上,顺序是DEBUG时改的）

template <typename T>
void myswap(T& t1,T&t2)
{
    T tmp=t1;
    t1=t2;
    t2=tmp;
}
//一些坐标变换函数
QPoint BoardToPixel(QPoint boardposition);
QPoint pixelToBoard(QPoint pixelposition);
QPoint BaseTransformation(int from,int to,QPoint Point_in);
//pixelposition生成对应的长方形,setgeometry用的
QRect pixelToRect(QPoint pixelposition,int _halflen);

QString PathToData2(std::vector<QPoint>&_path,int OldRegionIdx);
void Data2ToPath(std::vector<QPoint>&_path,QString data2,int OldRegionIdx);
bool isinboard(QPoint p);//是否在棋盘内
void setstate(int **arr,QPoint p,int va);//将arr的点p值设为va
int  getstate(int **arr,QPoint p);//读取arr的点p值

#endif // SETTINGS_H
