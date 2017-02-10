#ifndef PLAYER_UI
#define PLAYER_UI
#include "player.h"
#include "missile.h"
#include <QGraphicsPixmapItem>
#include<QObject>
#include<QKeyEvent>



class p_ui:  public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
private:
    Player* p;
public:
    p_ui();
    void keyPressEvent(QKeyEvent *direction);
    void keyReleaseEvent(QKeyEvent *direction);
    Player* get_p();
public slots:
    void changePos();
    void setPicLeft();
    void setPicRight();
//    void showMissile();
    void create_m();
//    void removeMissile();
    void setPicStraight();

};

#endif // PLAYER_UI

