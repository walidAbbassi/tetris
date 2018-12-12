#ifndef SQUARE_H
#define SQUARE_H

#include "figure.h"

class Square: public Figure
{
public:
    Square(int x, int y, int ey = 20 , int erx = 20);
};

#endif // SQUARE_H
