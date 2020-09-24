#include "tank.h"
#include"QDebug"
#include <cmath>

Tank::Tank(Direction direction, int x, int y): MovingObject (direction, x, y)
{
    width = CELL;
    height = CELL;
    canShoot= true;
}

QRectF Tank::boundRect()
{
    return QRectF(static_cast<int>(round(static_cast<double>(x)/(CELL/2))*(CELL/2)),
                  static_cast<int>(round(static_cast<double>(y)/(CELL/2))*(CELL/2)),width, height);
}

void Tank::setCanShoot(bool b)
{
    canShoot = b;
}

bool Tank::getCanShoot()
{
    return canShoot;
}

void Tank::rotate(Direction dir)
{
    if(this->direction != dir) {
        this->canMove = true;
        this->direction = dir;
        if(!(x%(CELL/2)==CELL/2))
        {
            this->x= static_cast<int>(round(static_cast<double>(x)/(CELL/2))*(CELL/2));
        }
        if(!(y%(CELL/2)==CELL/2))
        {
            this->y= static_cast<int>(round(static_cast<double>(y)/(CELL/2))*(CELL/2));
        }
    }
}

