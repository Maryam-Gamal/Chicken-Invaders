#include "Score.h"
#include <QFont>


Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){
    score = 0;

    setPlainText(QString("Score: ") + QString::number(score)); // Score: 0
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}

void Score::increase()
{
    score++;
    setPlainText(QString("Score: ") + QString::number(score));
}

int Score::get()
{
    return score;
}


void Score::decrease(){

    score--;
    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::blue);

}




