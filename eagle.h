#ifndef EAGLE_H
#define EAGLE_H

#include "staticobject.h"

class Eagle : public StaticObject
{
public:
    Eagle(int, int);
    QRectF boundRect() override;
    void draw(QPainter *) override;
};

#endif // EAGLE_H
