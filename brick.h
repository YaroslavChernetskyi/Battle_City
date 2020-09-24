#ifndef BRICK_H
#define BRICK_H

#include "staticobject.h"
#include "movingobject.h"

class Brick: public StaticObject
{
    int state;
public:
    Brick(int,int);
    QRectF boundRect() override;
    void draw(QPainter *) override;
    virtual void getDamage(MovingObject::Direction);
};

#endif // BRICK_H
