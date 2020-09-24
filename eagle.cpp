#include "eagle.h"

Eagle::Eagle(int x, int y): StaticObject(x,y)
{
    width = CELL;
    height = CELL;
    destroyed = false;
}

QRectF Eagle::boundRect()
{
    return QRectF(this->x,this->y,width, height);
}

void Eagle::draw(QPainter * painter)
{
    img = destroyed?"://eagleDie.png":"://eagle.png";
    QPixmap pixmap(img);
    painter->drawPixmap(x, y, width, height, pixmap);
}
