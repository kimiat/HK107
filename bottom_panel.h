#ifndef BOTTOM_PANEL
#define BOTTOM_PANEL
#include "fuel.h"
#include<QGraphicsPixmapItem>
#include<QGraphicsScene>
#include<QObject>
#include<QGraphicsProxyWidget>
#include<QLCDNumber>
#include<QtWidgets>
#include<QMediaPlayer>
#include "player.h"
class panel:public QObject,  public QGraphicsPixmapItem{
    Q_OBJECT
private:
//    QGraphicsPixmapItem* b_pannel;
    QGraphicsPixmapItem* gauge;
    QGraphicsPixmapItem* needle;
    QLCDNumber* score;
    QGraphicsProxyWidget* proxy;
    fuel* amount;
    QMediaPlayer* fuel_sound;
    QPalette lcd_palette;
    Player* player;
public:
    panel(Player* p);
    QGraphicsPixmapItem* getGauge();
    QGraphicsPixmapItem* getNeedle();
    QLCDNumber* getScore();
    bool over;
    void addScore();
    fuel* getFuel();
    ~panel();
signals:
    void gameover();
public slots:
    void set_posl();
    void set_posr();
    void play_sound();
    void stop_sound();
    void setScore();
    void stopMoving();
};

#endif // BOTTOM_PANEL

