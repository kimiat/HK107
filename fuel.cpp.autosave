#include "fuel.h"
#include <iostream>
using namespace std;

fuel::fuel()
{
    dfuel_timer = new QTimer();
    fuel_amount = 500;
    connect(dfuel_timer, SIGNAL(timeout()), this, SLOT(dec_fuel()));
    dfuel_timer->start(300);
}

void fuel::inc_fuel()
{
    if(fuel_amount < 480)
    {
        fuel_amount += 20;
        emit fuelInc(fuel_amount);
    }
}

void fuel::dec_fuel()
{
    if(fuel_amount > 5)
    {
        fuel_amount -= 5;
        emit fuelDec(fuel_amount);
    }
}
