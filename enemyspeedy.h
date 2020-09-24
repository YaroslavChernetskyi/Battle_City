#ifndef ENEMYSPEEDY_H
#define ENEMYSPEEDY_H


#include "badtank.h"

class EnemySpeedy : public BadTank
{
public:
    EnemySpeedy(Direction, int, int,int);
    void draw(QPainter*) override;
};

#endif // ENEMYSPEEDY_H
