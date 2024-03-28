#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QImage>
Game::Game(QWidget *parent){
    mainthemeoutput = new QAudioOutput;
    mainthemeoutput->setVolume(50);
    sound = new QMediaPlayer;
    sound->setAudioOutput(mainthemeoutput);
    sound->setSource(QUrl("qrc:/sounds/CHICKEN INVADERS [ SMS Music! ] (256  kbps) (ss.shabakngy.com).mp3"));
    sound->play();

    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setBackgroundBrush(QBrush(QImage(":/photos/stars_space_galaxy_.jpg.png")));

    setScene(scene);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    QPixmap pixmap1(":/photos/rocket2.png");
    pixmap1 = pixmap1.scaledToHeight(80);
    pixmap1 = pixmap1.scaledToWidth(80);
    Player = new player();
    Player->setPixmap(pixmap1);
    Player->setPos(400,500);
    Player->setFlag(QGraphicsItem::ItemIsFocusable);
    Player->setFocus();
    scene->addItem(Player);




    score = new Score();
    scene->addItem(score);

    Health = new health();
    Health->setPos(Health->x(),Health->y()+25);
    scene->addItem(Health);

    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),Player,SLOT(spawn()));
    timer->start(2000);


    show();
}
