#ifndef BADTANKFACTORY_H
#define BADTANKFACTORY_H

#include "badtank.h"
#include "enemysimple.h"
#include "enemyspeedy.h"
class BadTankFactory
{
public:
    virtual BadTank* createTank(MovingObject::Direction, int, int, int) = 0;
    virtual ~BadTankFactory() = default;

};

#endif // BADTANKFACTORY_H
