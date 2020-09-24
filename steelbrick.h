#ifndef STEELBRICK_H
#define STEELBRICK_H

#include "brick.h"

class SteelBrick : public Brick
{
public:
    SteelBrick(int, int);
    QRectF boundRect() override;
    void draw(QPainter *) override;
    void destroy() override;
    void getDamage(MovingObject::Direction)override;
};

#endif // STEELBRICK_H
