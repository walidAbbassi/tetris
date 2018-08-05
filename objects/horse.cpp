#include "horse.h"
#include "unit.h"
#include "figure.h"
#include "gamelogic.h"
Horse::Horse(int x, int y, int ey, int erx) : Figure(x, y, ey, erx)
{
    units.push_back(new Unit(0, 0, Qt::red));
    units.push_back(new Unit(Unit::WIDTH,0, Qt::red));
    units.push_back(new Unit(0, Unit::HEIGHT, Qt::red));
    units.push_back(new Unit(0, 2 * Unit::HEIGHT, Qt::red));
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
            if(x + 2 * Unit::WIDTH >= GameLogic::BOARD_WIDTH - Unit::WIDTH  || y + 3 * Unit::HEIGHT > GameLogic::BOARD_HEIGHT - 3 * Unit::HEIGHT) {
                break;
            }
            units[0]->setOffsetXY(0, 0);
            units[1]->setOffsetXY(Unit::WIDTH, 0);
            units[2]->setOffsetXY(0, Unit::HEIGHT);
            units[3]->setOffsetXY(0, 2 * Unit::WIDTH);
        break;
        case 1:
            if(x - 3 * Unit::WIDTH < 0) {
                break;
            }
            units[0]->setOffsetXY(0, 0);
            units[1]->setOffsetXY(0, Unit::HEIGHT);
            units[2]->setOffsetXY(-Unit::WIDTH, 0);
            units[3]->setOffsetXY(- 2 * Unit::WIDTH, 0);
            break;
        case 2:
            if(x - Unit::WIDTH < 0) {
                break;
            }
            units[0]->setOffsetXY(0, 0);
            units[1]->setOffsetXY(0, -Unit::HEIGHT);
            units[2]->setOffsetXY(0, - 2 * Unit::HEIGHT);
            units[3]->setOffsetXY(-Unit::WIDTH, 0);
        break;
        case 3:
            if(x + 3 * Unit::WIDTH >= GameLogic::BOARD_WIDTH - Unit::WIDTH) {
                break;
            }
            units[0]->setOffsetXY(0, 0);
            units[1]->setOffsetXY(0, -Unit::HEIGHT);
            units[2]->setOffsetXY(Unit::WIDTH, 0);
            units[3]->setOffsetXY(2 * Unit::WIDTH, 0);
        break;
    }
}
