#ifndef MOVEABLE_H
#define MOVEABLE_H
#include"staticobject.h"

class Moveable
{
public:
    virtual ~Moveable() = default;
    virtual void move() = 0;
    virtual void collisionReaction() = 0;

};
#endif // MOVEABLE_H
