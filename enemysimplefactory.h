#ifndef ENEMYSIMPLEFACTORY_H
#define ENEMYSIMPLEFACTORY_H

#include "badtankfactory.h"

class EnemySimpleFactory: public BadTankFactory
{
public:
    EnemySimple * createTank(MovingObject::Direction direction , int x, int y,int id) override;
};

#endif // ENEMYSIMPLEFACTORY_H
