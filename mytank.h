#ifndef MYTANK_H
#define MYTANK_H

#include "goodtank.h"

const int MYTANK_X = 4*CELL;
const int MYTANK_Y = 12*CELL;
class MyTank: public GoodTank
{
public:
    MyTank(Direction, int, int);
    virtual void keyMoving(QKeyEvent *event) override;
    virtual void keyReleasing(QKeyEvent *event) override;
    void draw(QPainter*) override;
};

#endif // MYTANK_H
