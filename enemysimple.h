#ifndef ENEMYSIMPLE_H
#define ENEMYSIMPLE_H

#include "badtank.h"

class EnemySimple : public BadTank
{
public:
    EnemySimple(Direction, int, int,int);
    void draw(QPainter*) override;
};

#endif // ENEMYSIMPLE_H
