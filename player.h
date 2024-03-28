#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsRectItem>
#include <QObject>
#include <QMediaPlayer>
#include <QAudioOutput>
class player:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    player (QGraphicsPixmapItem * parent =0);
    void keyPressEvent(QKeyEvent * event);
public slots:
    void spawn();
private:
    QMediaPlayer *bulletsound;
    QAudioOutput *mainthemeoutput = new QAudioOutput;
};

#endif // MYRECT_H

