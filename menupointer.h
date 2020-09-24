#ifndef MENUPOINTER_H
#define MENUPOINTER_H

#include "staticobject.h"

class MenuPointer: public StaticObject
{
public:
    MenuPointer(int,int);
    QRectF boundRect() override;
    void draw(QPainter *) override;
    void setX(int);
    void setY(int);

};

#endif // MENUPOINTER_H
