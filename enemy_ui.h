#ifndef ENEMY_UI_H
#define ENEMY_UI_H

#include "enemy.h"
#include <QObject>
#include <QMediaPlayer>
#include <QTimer>
#include "player_ui.h"
using namespace std;

enum ObjectType {SHIP_E = 1, HELICOPTER_E = 2, BALLOON_E = 3, JET_E = 4};

class e_ui: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
protected:
    Enemy *enemy;
    ObjectType type;
    QTimer* check;
    QTimer* exp;
    Player* player;
    QMediaPlayer* sound;
    int shot_num;
    bool gameOver;
    bool isRemoved;
public:
    e_ui();
    e_ui(pair<int, int> position, Player* p);
    void checkLosing();
    Player* getPlayer();
    ~e_ui();
public slots:
    void changePos();
    void remove();
    void check_c();
    void explode();
    void stopMoving();
signals:
    void gameover();
};

class s_ui: public e_ui
{
public:
    s_ui(pair<int, int> position, Player* p);
};

class h_ui: public e_ui
{
public:
    h_ui(pair<int, int> position, Player* p);
};

class b_ui: public e_ui
{
public:
    b_ui(pair<int, int> position, Player* p);
};

class j_ui: public e_ui
{
public:
    j_ui(pair<int, int> position, Player* p);
};

#endif
