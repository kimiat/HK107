//
#ifndef BUTTON_H
#define BUTTON_H

#include <QObject>
#include <QPixmap>
#include <iostream>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QGraphicsSceneMouseEvent>
#include <QLabel>

class Button: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    QLabel *label;
    QTimer *timer;
    QTimer *b_timer;
public:
    Button();
    Button(int x, int y, QString text, QGraphicsScene *scene);
    ~Button();
//    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
//    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
public slots:
    void changeColour();
    void changeColourBack();
signals:
    void clicked();
};

#endif // BUTTON_H
