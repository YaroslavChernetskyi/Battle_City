#ifndef TANKEXPLOSION_H
#define TANKEXPLOSION_H

#include "explosionalgorithm.h"

class TankExplosion : public ExplosionAlgorithm
{
    int explosionCounter{0};
public:
    QString explosingImage() override;
};

#endif // TANKEXPLOSION_H
