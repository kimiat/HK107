//
#ifndef MISSILE_H
#define MISSILE_H
#include <QTimer>
#include <QGraphicsRectItem>
#include <QObject>

class Player;

class missile:public QObject,  public QGraphicsRectItem
{
    Q_OBJECT
private:
    int x;
    int y;
//    static int num;
    QTimer* timer;
    Player *player;
public:
    missile(int x, int y);
    int get_x();
//    int get_num();
    int get_y();
    ~missile();
    int get_height();
    void stopTimer();
signals:
    void m_removed();
    void m_moved();
public slots:
    void move_up();
};

#endif

