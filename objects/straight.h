#ifndef STRAIGHT_H
#define STRAIGHT_H

#include "figure.h"

class Straight: public Figure
{
public:
    Straight(int x, int y, int ey = 10 , int erx = 40);
    void rotate() override;
};

#endif // STRAIGHT_H
