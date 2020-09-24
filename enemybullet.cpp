#include "enemybullet.h"

Bullet *EnemyBullet::createBullet(MovingObject::Direction direction, int x, int y, int bulletID)
{
    return new Bullet(direction, x, y, bulletID);
}
