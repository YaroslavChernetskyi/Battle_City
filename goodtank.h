#ifndef GOODTANK_H
#define GOODTANK_H

#include "mybullet.h"
#include <QKeyEvent>
#include "tank.h"

class GoodTank: public Tank
{
protected:
    Bullet* bullet;
    bool kUp, kRight, kDown, kLeft, kShoot;
    int ID;
    int HP;
public:
    GoodTank(Direction, int, int);
    MyBullet *myBulletFactory;
    virtual void keyMoving(QKeyEvent *event) = 0;
    virtual void keyReleasing(QKeyEvent *event) = 0;
    void move() override;
    void rotation();
    void draw(QPainter*) override = 0;
    Bullet* shoot()override;
    int getID();
    int getHP();
    void setHP(int);
    void setX(int);
    void setY(int);
};

#endif // GOODTANK_H
