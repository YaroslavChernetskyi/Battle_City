#ifndef MOVINGOBJECT_H
#define MOVINGOBJECT_H

#include "staticobject.h"
#include "moveable.h"
#include <QKeyEvent>


class MovingObject: public StaticObject, public Moveable
{
public:
    enum Direction {Right = 1, Left, Up, Down};
    MovingObject(Direction d, int x, int y);
    void move() override = 0;
    void collisionReaction() override;
    void fieldEndReaction();
    bool objectOutOfFrame();
    Direction getDirection();
    int getSpeed();
    bool getCanMove();
    void setCanMove(bool);

protected:
    Direction direction;
    int speed;
    bool canMove;
};

#endif // MOVINGOBJECT_H
