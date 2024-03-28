#include "player.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include "Game.h"
#include "laser.h"
#include "Enemy.h"
#include <QDebug>



extern Game * game;
player::player(QGraphicsPixmapItem *parent)
{
    mainthemeoutput = new QAudioOutput;
    mainthemeoutput->setVolume(50);
    bulletsound = new QMediaPlayer;
    bulletsound->setAudioOutput(mainthemeoutput);
    bulletsound->setSource(QUrl("qrc:/sounds/blaster-2-81267.mp3"));


}

void player::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0)
            setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right){
        if (pos().x() + 100 < 800)
            setPos(x()+10,y());
    }
    else if (event->key() == Qt::Key_Space){
        laser * Laser = new laser();
        Laser->setPos(x()+40,y());
        scene()->addItem(Laser);
        if(bulletsound->playbackState() == QMediaPlayer::PlayingState)
            bulletsound->setPosition(0);
        else if(bulletsound->playbackState() == QMediaPlayer::StoppedState)
            bulletsound->play();
}

}

void player::spawn(){



    Enemy * enemy = new Enemy();

    scene()->addItem(enemy);


}
