#ifndef LAST_STEP_H
#define LAST_STEP_H

#include <QWidget>
#include <QPushButton>

namespace Ui {
class last_step;
}

class last_step : public QWidget
{
    Q_OBJECT

public:
    explicit last_step(QWidget *parent = nullptr);
    QPushButton *buttons[7];
    void in(int k);//将该玩家设置为游戏状态
    ~last_step();

private slots:
    void on_p1_clicked();
    void on_p2_clicked();
    void on_p3_clicked();
    void on_p4_clicked();
    void on_p5_clicked();
    void on_p6_clicked();//对应6个玩家的按钮点击

signals:
    void showlast(int k);//传递需要展示的玩家信息

private:
    Ui::last_step *ui;
};

#endif // LAST_STEP_H
