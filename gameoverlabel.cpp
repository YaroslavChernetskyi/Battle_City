#include "gameoverlabel.h"
#include "QDebug"

GameOverLabel::GameOverLabel(int x, int y): StaticObject (x,y)
{
    width = 2*CELL;
    height = CELL;
    img = ":/gameOver (2).png";
    destroyed = false;
}

QRectF GameOverLabel::boundRect()
{
    return QRectF(this->x,this->y,width, height);
}

void GameOverLabel::draw(QPainter * painter)
{   if(y>190)
    {
        y-=1;
    }
    else
    {
        destroy();
    }
    QPixmap pixmap(img);
    painter->drawPixmap(x, y, width, height, pixmap);
}

