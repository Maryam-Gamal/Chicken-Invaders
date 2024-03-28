#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Player.h"
#include "Score.h"
#include "health.h"

class Game: public QGraphicsView{
public:
    Game(QWidget * parent=0);

    QGraphicsScene * scene;
    player * Player;
    Score * score;
    health * Health;
    QMediaPlayer *sound;
    QAudioOutput *mainthemeoutput = new QAudioOutput;

};

#endif // GAME_H
