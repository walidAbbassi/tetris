#ifndef HORSE_H
#define HORSE_H

#include "figure.h"

class Horse: public Figure
{
public:
    Horse(int x, int y, int ey = 30 , int erx = 20);
};

#endif // HORSE_H
