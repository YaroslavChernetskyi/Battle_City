#include "explosion.h"
#include "QDebug"

Explosion::Explosion(int x, int y,int width, int height, ExplosionAlgorithm* alg) : StaticObject (x,y),
    explosionAlgorithm(alg)
{
    this->width = width;
    this->height = height;
    this->x-=this->width/2;
    this->y-=this->height/2;
    destroyed = false;
}

void Explosion::draw(QPainter * painter)
{
    if(explosionAlgorithm->explosingImage().isEmpty())
    {
        destroyed = true;
    }
    else
    {
    QPixmap pixmap(explosionAlgorithm->explosingImage());
    painter->drawPixmap(x, y, width, height, pixmap);
    }
}

QRectF Explosion::boundRect()
{
    return QRectF(this->x,this->y,width, height);
}
