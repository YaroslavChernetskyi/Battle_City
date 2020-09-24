#ifndef BADTANK_H
#define BADTANK_H

#include "tank.h"
#include  "enemybullet.h"

class BadTank: public Tank
{
    EnemyBullet *enemyBulletFactory;
    int collisionTimer;
    int probabilityToShoot;
    int shootCounter;
protected:
    int points;
    int numberID;
    int typeID;
public:
    BadTank(Direction, int, int, int);
    void move() override;
    virtual Bullet* shoot() override;
    void draw(QPainter*) override = 0;
    void changeDirection();
    void reverseDirection(MovingObject::Direction direction);
    int getPoints();
    void setID(int);
    int getID();
    int getTypeID();
};

#endif // BADTANK_H
