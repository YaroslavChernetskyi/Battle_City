#ifndef BULLET_H
#define BULLET_H
#include "movingobject.h"
//#include "tank.h"
class Tank;
class Bullet: public MovingObject
{
    int bulletID;
    Tank* owner;
public:
    Bullet(Direction, int, int, int);
    Tank* getOwner();
    void setOwner(Tank*);
    void moveBullet(Direction) ;
    void move() override;
    QRectF boundRect() override;
    void draw(QPainter*) override;
    int getBulletID();
};

#endif // BULLET_H
