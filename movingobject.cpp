#include "movingobject.h"
#include "QDebug"
#include <cmath>

MovingObject::MovingObject(Direction direction, int x, int y):StaticObject(x,y)
{
    this->direction = direction;
    canMove = true;
}
bool MovingObject::objectOutOfFrame()
{
    if((direction == Up && y < 0) ||
            (direction == Down && y > HEIGHT*CELL - height)||
      (direction == Left && x < 0) ||
            (direction == Right && x >HEIGHT*CELL - width)) {
         canMove = false;
         return true;
    }
    else {
        return false;
    }
}

void  MovingObject::collisionReaction()
{
    if(x!=static_cast<int>(round(static_cast<double>(x)/(CELL/2))*(CELL/2)))
        move();

    if(y!=static_cast<int>(round(static_cast<double>(y)/(CELL/2))*(CELL/2)))
        move();
}

void MovingObject::fieldEndReaction()
{
      canMove = false;
      switch(direction) {
          case Up:
               this->y += 1;
               break;
           case Down:
                this->y -= 1;
                break;
           case Left:
                this->x += 1;
                break;
           case Right:
                this->x -= 1;
                break;
      }
}

void MovingObject::setCanMove(bool b)
{
    canMove = b;
}

bool MovingObject::getCanMove()
{
    return canMove;
}

MovingObject::Direction MovingObject::getDirection()
{
    return direction;
}

int MovingObject::getSpeed()
{
   return speed;
}
