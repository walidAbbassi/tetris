#ifndef UNIT_H
#define UNIT_H
#include <QGraphicsScene>
class Unit
{
public:
    Unit(int x, int y);
    ~Unit();
    QGraphicsRectItem *draw(QGraphicsScene *scene);
private:
    int x;
    int y;
    int width = 10;
    int height = 10;
};

#endif // UNIT_H
