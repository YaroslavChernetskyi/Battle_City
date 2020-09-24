#include "enemysign.h"

EnemySign::EnemySign(int x, int y): StaticObject (x,y)
{
    this->img = "://enemySign.png";
    this->width = CELL/2;
    this->height = CELL/2;
}

void EnemySign::draw(QPainter * painter)
{
    QPixmap pixmap(img);
    painter->drawPixmap(x, y, width, height, pixmap);
}

QRectF EnemySign::boundRect()
{
    return QRectF(this->x,this->y,width, height);
}
