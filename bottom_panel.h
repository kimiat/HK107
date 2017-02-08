#ifndef BOTTOM_PANEL
#define BOTTOM_PANEL
#include "fuel.h"
#include<QGraphicsPixmapItem>
#include<QObject>
class panel:public QObject,  public QGraphicsPixmapItem{
    Q_OBJECT
private:
//    QGraphicsPixmapItem* b_pannel;
    QGraphicsPixmapItem* gauge;
    QGraphicsPixmapItem* needle;
    fuel* amount;
public:
    panel();
    QGraphicsPixmapItem* getGauge();
    QGraphicsPixmapItem* getNeedle();
public slots:
    void set_pos();
};

#endif // BOTTOM_PANEL

