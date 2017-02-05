#ifndef MISSILE_H
#define MISSILE_H
#include <QTimer>
#include <QGraphicsRectItem>
#include <QObject>

class missile:public QObject,  public QGraphicsRectItem
{
    Q_OBJECT
private:
    int x;
    int y;
    int height;
    int width;
    QTimer* timer;
public:
    missile(int x, int y, int width, int height);
    int get_x();
    int get_y();
    ~missile();
    int get_height();
public slots:
    void move_up();
};

#endif

