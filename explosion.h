#ifndef EXPLOSION_H
#define EXPLOSION_H
#include  "staticobject.h"
#include "movingobject.h"
#include "explosionalgorithm.h"


class Explosion : public StaticObject
{
    ExplosionAlgorithm * explosionAlgorithm;
public:
    Explosion(int, int,int, int, ExplosionAlgorithm* alg);
    void draw(QPainter*)override;
    QRectF boundRect()override;
};

#endif // EXPLOSION_H
