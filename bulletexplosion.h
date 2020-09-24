#ifndef BULLETEXPLOSION_H
#define BULLETEXPLOSION_H

#include "explosionalgorithm.h"
class BulletExplosion : public ExplosionAlgorithm
{
    int explosionCounter{0};
public:
    QString explosingImage()override;
};

#endif // BULLETEXPLOSION_H
