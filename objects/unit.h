#ifndef UNIT_H
#define UNIT_H
#include <QGraphicsScene>
class Unit
{
public:
    const static int WIDTH = 10;
    const static int HEIGHT = 10;
    Unit(int offsetX, int offsetY, QBrush brush);
    ~Unit();
    void setXY(int x, int y);
    int getOffsetX();
    int getOffsetY();
    void setOffsetXY(int, int);


    int getX();
    int getY();
    void setX(int);
    void setY(int);

    QPen getPen();
    QBrush getBrush;
    QGraphicsRectItem *draw(QGraphicsScene *scene, int x = 0, int y = 0);
private:
    int offsetX;
    int offsetY;
    int x = NULL;
    int y = NULL;
    QBrush brush;
    QPen pen = QPen(Qt::black);

};
#endif // UNIT_H
