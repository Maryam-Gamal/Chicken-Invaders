#ifndef LASER_H
#define LASER_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QMediaPlayer>
#include <QAudioOutput>

class laser: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    laser();

public slots:
    void move();
private:
    QMediaPlayer *enemysound;
    QAudioOutput *mainthemeoutput = new QAudioOutput;


};

#endif // BULLET_H
