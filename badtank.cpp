#include "badtank.h"
//#include <QRandomGenerator>
#include "QDebug"
#include <cstdlib>

BadTank::BadTank(Direction direction, int x, int y,int):Tank (direction, x, y)
{
    shootCounter = 0;
    enemyBulletFactory = new EnemyBullet();
    collisionTimer=0;
    canMove = true;
}

Bullet* BadTank::shoot() {

    probabilityToShoot = rand()%31;;
    if(getCanShoot()&&probabilityToShoot==17){
        Bullet* bullet = enemyBulletFactory->createBullet(direction, x+CELL/2, y+CELL/2, 1);
        return bullet;
    }
    else return nullptr;
}

void BadTank::move()
{
    if(!objectOutOfFrame()) {

        if(direction == Up){
                y-=speed;
        }
        else if(direction == Down) {
                y+=speed;
        }
        else if(direction == Left) {
                x-=speed;
        }
        else if(direction == Right){
               x+=speed;
        }

    }
}

void BadTank::changeDirection()
{
if(!canMove){
    int i = rand()%4;;
    switch(i) {
       case 0:
           rotate(Right);
           break;
       case 1:
            rotate(Left);
            break;
       case 2:
            rotate(Up);
            break;
        case 3:
            rotate(Down);
            break;
    }
}
}

void BadTank::reverseDirection(MovingObject::Direction direction)
{
    switch(direction) {
    case Up:
         rotate(Down);
         y+=speed;
         break;
    case Down:
         rotate(Up);
         y-=speed;
         break;
     case Left:
         rotate(Right);
         x+=speed;
         break;
     case Right:
         rotate(Left);
         x-=speed;
         break;
    }
}

int BadTank::getPoints()
{
    return points;
}

void BadTank::setID(int id)
{
    numberID = id;
}

int BadTank::getID()
{
    return numberID;
}

int BadTank::getTypeID()
{
    return typeID;
}

