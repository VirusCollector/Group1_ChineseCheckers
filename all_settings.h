#ifndef ALL_SETTINGS_H
#define ALL_SETTINGS_H

#include <QWidget>
#include "music.h"
#include <QSoundEffect>
#include <QDesktopServices>

namespace Ui {
class all_settings;
}

class all_settings : public QWidget
{
    Q_OBJECT

public:
    explicit all_settings(QWidget *parent = nullptr);
    ~all_settings();
    music b;

private slots:
    void on_volume_stateChanged(int arg1);//改变音效状态
    void on_back_stateChanged(int arg1);//改变背景音乐状态
    void on_pushButton_clicked();//打开游戏规则介绍网站

private:
    Ui::all_settings *ui;
};

#endif // ALL_SETTINGS_H
