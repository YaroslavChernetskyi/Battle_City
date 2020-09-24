#ifndef MYBULLET_H
#define MYBULLET_H
#include "bulletfactory.h"

class MyBullet: public BulletFactory
{
public:
     Bullet * createBullet(MovingObject::Direction direction,  int x, int y, int ID) override final;
};

#endif // MYBULLET_H
