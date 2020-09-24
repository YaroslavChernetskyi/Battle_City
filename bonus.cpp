#include "bonus.h"
#include "widget.h"
#include "QDebug"
//#include "QRandomGenerator"
#include <cstdlib>

Bonus::Bonus(int x, int y) : StaticObject(x, y)
{
    width = CELL;
    height = CELL;
    img = "://bomb.png";
    int i = rand()%2;
    switch(i) {
       case 0:
           this->type = Life;
           break;
       case 1:
           this->type = Bomb;
           break;
    }
    switch(type) {
       case Life:
            this->img = "://shovel.png";
            break;
       case Bomb:
            this->img = "://bomb.png";
            break;
    }
    destroyed = false;
}

Bonus::Type Bonus::getType()
{
    return type;
}


QRectF Bonus::boundRect()
{
    return QRectF(this->x,this->y,width, height);
}

void Bonus::draw(QPainter * painter)
{
    QPixmap pixmap(img);
    painter->drawPixmap(x, y, width, height, pixmap);
}

