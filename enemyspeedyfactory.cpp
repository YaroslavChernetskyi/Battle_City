#include "enemyspeedyfactory.h"

EnemySpeedy *EnemySpeedyFactory::createTank(MovingObject::Direction direction, int x, int y,int id)
{
    return new EnemySpeedy(direction, x, y, id);
}
