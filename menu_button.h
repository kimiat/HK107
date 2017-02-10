#ifndef MENU_BUTTON_H
#define MENU_BUTTON_H

#include <QObject>
#include <QPixmap>
#include <iostream>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QGraphicsSceneMouseEvent>
#include <QLabel>

enum BtnType {PLAY = 1, HIGHSCORES = 2, CREDITS = 3, EXIT = 4, BACK = 5};

class menu_button: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    BtnType type;
    QTimer *timer;
    QTimer *b_timer;
public:
    menu_button();
    menu_button(int x, int y, BtnType type, qreal rotate);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
    ~menu_button();
public slots:
    void changeColour();
    void changeColourBack();
signals:
    void playclicked();
    void scoresclicked();
    void creditsclicked();
    void exitclicked();
    void backclicked();
};

#endif
