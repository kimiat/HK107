#ifndef ENEMY_UI_H
#define ENEMY_UI_H

#include "enemy.h"
#include <QObject>

enum ObjectType {SHIP_E = 1, HELICOPTER_E = 2, BALLOON_E = 3, JET_E = 4};

class e_ui: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
protected:
    Enemy *enemy;
    ObjectType type;
public:
    e_ui();
    e_ui(pair<int, int> position, ObjectType type);
    void checkLosing();
public slots:
    void changePos();
    void remove();
signals:
    void gameover();
};

class s_ui: public e_ui
{
public:
    s_ui(pair<int, int> position, ObjectType type);
};

class h_ui: public e_ui
{
public:
    h_ui(pair<int, int> position, ObjectType type);
};

class b_ui: public e_ui
{
public:
    b_ui(pair<int, int> position, ObjectType type);
};

class j_ui: public e_ui
{
public:
    j_ui(pair<int, int> position, ObjectType type);
};

#endif
