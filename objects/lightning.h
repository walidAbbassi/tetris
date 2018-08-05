#ifndef LIGHTNING_H
#define LIGHTNING_H

#include "figure.h"

class Lightning: public Figure
{
public:
    Lightning(int x, int y, int ey = 20 , int erx = 30);
    void rotate() override;
};

#endif // LIGHTNING_H
