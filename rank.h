#ifndef RANK_H
#define RANK_H

#include <QWidget>
#include <QCloseEvent>
#include <QLabel>

namespace Ui {
class rank;
}

class rank : public QWidget
{
    Q_OBJECT

public:
    explicit rank(QWidget *parent = nullptr);
    ~rank();
    void setrank(int r,QString t);//设置排名
    QLabel *rank_names[7];
private:
    Ui::rank *ui;

protected:
     void closeEvent (QCloseEvent *event);//重写关闭窗口函数

};

#endif // RANK_H
