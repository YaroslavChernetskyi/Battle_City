#ifndef EXPLOSIONALGORITHM_H
#define EXPLOSIONALGORITHM_H
#include "QString"

class ExplosionAlgorithm
{
public:
    virtual ~ExplosionAlgorithm() = default;
    virtual QString explosingImage() = 0;
};

#endif // EXPLOSIONALGORITHM_H
