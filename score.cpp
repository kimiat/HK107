//
#include <iostream>
#include "score.h"

using namespace std;

Score::Score() { value = 0; }

unsigned int Score::getScore() { return value; }

void Score::addScore(Object destroyed){
    value += destroyed;
    cout << "value is " <<destroyed << endl;
}
