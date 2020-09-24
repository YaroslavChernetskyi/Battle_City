#ifndef ENEMYSPEEDYFACTORY_H
#define ENEMYSPEEDYFACTORY_H


#include "badtankfactory.h"

class EnemySpeedyFactory: public BadTankFactory
{
public:
    EnemySpeedy * createTank(MovingObject::Direction direction , int x, int y,int id) override;
};


#endif // ENEMYSPEEDYFACTORY_H
