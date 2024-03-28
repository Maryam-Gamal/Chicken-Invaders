#include "laser.h"
#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QGraphicsPixmapItem>
#include <QDebug>
#include "Game.h"

extern Game * game;
laser::laser (): QObject(), QGraphicsPixmapItem(){
    mainthemeoutput = new QAudioOutput;
    mainthemeoutput->setVolume(50);
    enemysound = new QMediaPlayer;
    enemysound->setAudioOutput(mainthemeoutput);
    enemysound->setSource(QUrl("qrc:/sounds/Rooster-call-sound.mp3"));

    setPixmap(QPixmap(":/photos/arrow.png"));


    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}



void laser::move(){

    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Enemy)){

            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            enemysound->play();
            game->score->increase();

            delete colliding_items[i];
            delete this;
            return;
        }
    }
    // move bullet up
    setPos(x(),y()-10);
    if (pos().y() < 0){
        scene()->removeItem(this);
        delete this;
    }
}
