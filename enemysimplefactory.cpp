#include "enemysimplefactory.h"


EnemySimple *EnemySimpleFactory::createTank(MovingObject::Direction direction, int x, int y,int id)
{
    return new EnemySimple(direction, x, y, id);
}
