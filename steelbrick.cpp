#include "steelbrick.h"

SteelBrick::SteelBrick(int x, int y): Brick (x,y)
{
    width = CELL/2;
    height = CELL/2;
    img = "://steel.png";
    destroyed = false;
}

void SteelBrick::destroy(){}

void SteelBrick::getDamage(MovingObject::Direction){}

QRectF SteelBrick::boundRect()
{
    return QRectF(this->x,this->y,width, height);
}

void SteelBrick::draw(QPainter * painter)
{
    QPixmap pixmap(img);
    painter->drawPixmap(x, y, width, height, pixmap);
}
