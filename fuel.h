#ifndef FUEL
#define FUEL

<<<<<<< HEAD
#include<QTimer>
#include<QObject>
#include<QGraphicsRectItem>
class fuel:public QObject, public QGraphicsRectItem{
    Q_OBJECT
    private:
        int fuel_amount;
        QTimer* ifuel_timer;
        QTimer* dfuel_timer;
    signals:
        void fuelChanged(int changed_amount);
    public:
        fuel();
    public slots:
        void inc_fuel();
        void dec_fuel();
//        void move_down();
=======
class fuel
{
private:
    int x;
    int y;
    int height;
    int width;
public:
    fuel(int X, int Y, int Width, int Height);
    void move_down();
>>>>>>> 96ec5d452d3ca53c20011281e22326d84337b887
};

#endif

