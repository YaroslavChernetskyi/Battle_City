#ifndef ENEMYSIGN_H
#define ENEMYSIGN_H

#include "staticobject.h"

class EnemySign: public StaticObject
{
public:
    EnemySign(int, int);
    void draw(QPainter*)override;
    QRectF boundRect()override;
};

#endif // ENEMYSIGN_H
