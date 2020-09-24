#include "bullet.h"
#include "qdebug.h"


Bullet::Bullet(Direction direction, int x, int y, int bulletID): MovingObject (direction, x, y)
{
    width = CELL/4;
    height = CELL/4;
    this->x-=width/2;
    this->y-=height/2;
    destroyed = false;
    this->bulletID = bulletID;
    owner = nullptr;
}

Tank *Bullet::getOwner()
{
    return owner;
}
void Bullet::setOwner(Tank* obj)
{
    owner = obj;
}

void Bullet::draw(QPainter* painter)
{
        switch(direction)
        {
           case Up:
                this->img = "://bulletU.png";
                break;
           case Down:
                this->img = "://bulletD.png";
                break;
            case Left:
                this->img = "://bulletL.png";
                break;
            case Right:
                this->img = "://bulletR.png";
                break;
        }
        QPixmap pixmap(img);
        painter->drawPixmap(x, y, width, height, pixmap);
}

int Bullet::getBulletID()
{
    return bulletID;
}

QRectF Bullet::boundRect()
{
    return QRectF(this->x-3,this->y-3,width+6, height+6);
}

void Bullet::moveBullet(Direction direction)
{
    if(objectOutOfFrame()){
        destroyed = true;
    }
   else if(canMove){
        switch(direction)
        {
       case Up:
            y-=3;
            break;
       case Down:
            y+=3;
            break;
        case Left:
            x-=3;
            break;
        case Right:
            x+=3;
            break;
        }
    }
}

void Bullet::move()
{

}
