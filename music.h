#ifndef MUSIC_H
#define MUSIC_H

#include <QWidget>
#include <QSoundEffect>
#include <QtDebug>

class music : public QWidget
{
    Q_OBJECT
public:
    explicit music(QWidget *parent = nullptr);
    void backmusic();
    void offbackmusic();
    void movemusic();
    void offmovemusic();//4个函数用来开关音效音乐
    QSoundEffect* background=new QSoundEffect;
    QSoundEffect* finalmove=new QSoundEffect;
signals:

};

#endif // MUSIC_H
