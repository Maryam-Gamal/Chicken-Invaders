#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QDebug>
#include "Game.h"

extern Game * game;

Enemy::Enemy(): QObject(), QGraphicsPixmapItem(){

    int random_number = rand() % 700;
    setPos(random_number,0);

    setPixmap(QPixmap(":/photos/chicken4.png"));



    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);


    }


void Enemy::move(){
    setPos(x(),y()+5);
    if (pos().y() > 600){
        game->score->decrease();
        game->Health->decrease();
        scene()->removeItem(this);
        delete this;
    }
}
