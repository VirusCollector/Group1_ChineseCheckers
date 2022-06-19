#include "music.h"
//bool
music::music(QWidget *parent)
    : QWidget{parent}
{
    background->setSource(QUrl::fromLocalFile(":/music/background.wav"));
    finalmove->setSource(QUrl::fromLocalFile(":/music/finalmove.wav"));
    background->setLoopCount(QSoundEffect::Infinite);
    background->setVolume(100);
}
void music::backmusic()
{
    background->play();
}

void music::offbackmusic()
{
    background->stop();
}

void music::movemusic()
{
    finalmove->play();
}

void music::offmovemusic()
{
    finalmove->stop();
}
