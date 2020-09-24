#ifndef TANK_H
#define TANK_H
#include "movingobject.h"
#include "bullet.h"
#include "mybullet.h"

class Tank: public MovingObject
{
    bool canShoot;
public:
    Tank(Direction, int, int);
    void move() override = 0;
    QRectF boundRect() override;
    virtual Bullet* shoot() = 0;
    void draw(QPainter*) override = 0;
    void setCanShoot(bool);
    bool getCanShoot();
    void rotate(Direction);
};

#endif // TANK_H
