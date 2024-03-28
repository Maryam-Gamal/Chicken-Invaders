#include"health.h"
#include <QFont>
#include <QMessageBox>
#include "Game.h"
#include <QGraphicsScene>
#include <QGraphicsScene>
#include <QProcess>
extern Game * game;

health::health(QGraphicsItem *parent): QGraphicsTextItem(parent){

    Health = 3;


    setPlainText(QString("Health: ") + QString::number(Health)); // Health: 3
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}


void health::decrease(){

    if(Health == 0){
        scene()->clear();
        QMessageBox* msg = new QMessageBox;
        msg->setWindowTitle("Game Over");
        msg->setText(QString("Game Over! Your score: ") + QString::number(game->score->get()+1));
        msg->exec();
        show();
    }

    Health--;
    setPlainText(QString("Health: ") + QString::number(Health));
    setDefaultTextColor(Qt::red); // Change text color to red

}



