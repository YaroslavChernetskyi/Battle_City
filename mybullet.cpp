#include "mybullet.h"

Bullet *MyBullet::createBullet(MovingObject::Direction direction, int x, int y, int bulletID)
{
    return new Bullet(direction, x, y,bulletID);
}
