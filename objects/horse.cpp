#include "horse.h"
#include "unit.h"

Horse::Horse(int x, int y): x(x), y(y)
{
    units.push_back(new Unit(x, y));
    units.push_back(new Unit(x+10, y));
    units.push_back(new Unit(x, y+10));
    units.push_back(new Unit(x, y+20));
}

void Horse::drawUnits(QGraphicsScene *scene)
{
    scene->addItem(this);
    for (int i = 0; i < units.size(); i++) {
        this->addToGroup(units[i]->draw(scene));
    }

}
