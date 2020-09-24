#ifndef MYFRIENDTANK_H
#define MYFRIENDTANK_H

#include "goodtank.h"

const int MYFRIENDTANK_X = 15*CELL/2;
const int MYFRIENDTANK_Y = 12*CELL;
class MyFriendTank: public GoodTank
{
public:
    MyFriendTank(Direction, int, int);
    virtual void keyMoving(QKeyEvent *event) override;
    virtual void keyReleasing(QKeyEvent *event) override;
    void draw(QPainter*) override;
};

#endif // MYFRIENDTANK_H
