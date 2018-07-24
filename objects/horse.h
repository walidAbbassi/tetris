#ifndef HORSE_H
#define HORSE_H

#include "figure.h"

class Horse: public Figure
{
public:
    Horse(int x, int y, int ey = 10 , int erx = 20);
    void rotate();
};

#endif // HORSE_H
