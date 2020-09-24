#ifndef BONUS_H
#define BONUS_H

#include "staticobject.h"
class Bonus : public StaticObject
{
public:
    enum Type {Life, Bomb};
    Bonus(int, int);
    Type getType();
    void draw(QPainter *) override ;
    QRectF boundRect() override ;

private:
    Type type;
};

#endif // BONUS_H
