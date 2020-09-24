#include "goodtank.h"
#include "QDebug"
#include "memory"

GoodTank::GoodTank(Direction direction, int x, int y):Tank(direction, x, y)
{
    myBulletFactory = new MyBullet();
    kUp=0;kDown=0;kLeft=0;kRight=0;kShoot=0;
    speed = (CELL/(CELL/2));
    HP=2;
}

void GoodTank::move()
{
    if(objectOutOfFrame() == true){
        fieldEndReaction();
    }
    if(!objectOutOfFrame()) {
    if(kUp)
    {
        if(direction == Up)
        {
            y-=speed;
        }
    }
    else if(kDown)
    {
        if(direction==Down)
        {
        y+=speed;
        }
    }
    else if(kLeft)
    {
        if(direction==Left)
        {
        x-=speed;
        }
    }
    else if(kRight)
    {
        if(direction ==Right)
        {
        x+=speed;
        }
    }
    }
}

void GoodTank::rotation()
{
    if(objectOutOfFrame() == true){
        fieldEndReaction();
    }
    if(!objectOutOfFrame()) {
    if(kUp)
    {
        rotate(Up);
    }
    else if(kDown)
    {
            rotate(Down);
    }
    else if(kLeft)
    {
            rotate(Left);
    }
    else if(kRight)
    {
            rotate(Right);
    }
    }
}

Bullet *GoodTank::shoot()
{
    if(getCanShoot()&&kShoot){
        bullet = myBulletFactory->createBullet(direction, x+CELL/2, y+CELL/2, 0);
        return bullet;
    }
    else return nullptr;
}

int GoodTank::getID()
{
    return ID;
}

int GoodTank::getHP()
{
    return HP;
}

void GoodTank::setHP(int hp)
{
    HP =hp;
}

void GoodTank::setX(int newX)
{
    x = newX;
}

void GoodTank::setY(int newY)
{
    y = newY;
}
