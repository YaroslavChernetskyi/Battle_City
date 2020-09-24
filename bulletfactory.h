#ifndef BULLETFACTORY_H
#define BULLETFACTORY_H

#include <bullet.h>
#include "movingobject.h"

class BulletFactory {
public:
    virtual Bullet* createBullet(MovingObject::Direction, int,int, int) = 0;
    virtual ~BulletFactory() = default;
};
#endif // BULLETFACTORY_H
