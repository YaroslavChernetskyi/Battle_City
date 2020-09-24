#ifndef ENEMYBULLET_H
#define ENEMYBULLET_H
#include"bulletfactory.h"

class EnemyBullet: public BulletFactory
{
public:
     Bullet * createBullet(MovingObject::Direction direction,  int x, int y, int ID) override final;
};

#endif // ENEMYBULLET_H
