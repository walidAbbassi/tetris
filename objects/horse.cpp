#include "horse.h"
#include "unit.h"
#include "figure.h"

Horse::Horse(int x, int y, int ey, int erx) : Figure(x, y, ey, erx)
{
    units.push_back(new Unit(0, 0, Qt::red));
    units.push_back(new Unit(10,0, Qt::red));
    units.push_back(new Unit(0, 10, Qt::red));
    units.push_back(new Unit(0, 20, Qt::red));
}

void Horse::rotate()
{
    if(rotatePosition == 3) {
        rotatePosition = 0;
    } else {
        rotatePosition++;
    }

    switch(rotatePosition) {
        case 0:
            if(x + 20 >= 190 || y + 30 > 270) {
                break;
            }
            units[0]->setOffsetXY(0, 0);
            units[1]->setOffsetXY(10, 0);
            units[2]->setOffsetXY(0, 10);
            units[3]->setOffsetXY(0, 20);
        break;
        case 1:
            if(x - 30 < 0) {
                break;
            }
            units[0]->setOffsetXY(0, 0);
            units[1]->setOffsetXY(0, 10);
            units[2]->setOffsetXY(-10, 0);
            units[3]->setOffsetXY(-20, 0);
            break;
        case 2:
            if(x - 10 < 0) {
                break;
            }
            units[0]->setOffsetXY(0, 0);
            units[1]->setOffsetXY(0, -10);
            units[2]->setOffsetXY(0, -20);
            units[3]->setOffsetXY(-10, 0);
        break;
        case 3:
            if(x + 30 >= 190) {
                break;
            }
            units[0]->setOffsetXY(0, 0);
            units[1]->setOffsetXY(0, -10);
            units[2]->setOffsetXY(10, 0);
            units[3]->setOffsetXY(20, 0);
        break;
    }
}
