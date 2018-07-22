#ifndef UNIT_H
#define UNIT_H
#include <QGraphicsScene>
class Unit
{
public:
    Unit(int offsetX, int offsetY);
    ~Unit();
    QGraphicsRectItem *draw(QGraphicsScene *scene, int x, int y);
private:
    int offsetX;
    int offsetY;
    int width = 10;
    int height = 10;
};

#endif // UNIT_H
