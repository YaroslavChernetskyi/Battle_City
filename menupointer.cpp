#include "menupointer.h"
#include "QDebug"

MenuPointer::MenuPointer(int x, int y): StaticObject (x, y)
{
    width = CELL/2;
    height = CELL/2;
    img = "://tankR.png";
}

QRectF MenuPointer::boundRect()
{
    return QRectF(this->x,this->y,width, height);
}

void MenuPointer::draw(QPainter * painter)
{
    QPixmap pixmap(img);
    painter->drawPixmap(x, y, width, height, pixmap);
}

void MenuPointer::setX(int x)
{
    this->x = x;
}

void MenuPointer::setY(int y)
{
    this->y = y;
}
