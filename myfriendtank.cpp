#include "myfriendtank.h"
#include "QDebug"

MyFriendTank::MyFriendTank(Direction direction, int x, int y): GoodTank(direction, x, y)
{
    ID = 1;
}

void MyFriendTank::keyMoving(QKeyEvent *event)
{
    switch(event->key()) {
       case Qt::Key_Left:
            kLeft=1;
            break;
       case Qt::Key_Right:
            kRight=1;
            break;
        case Qt::Key_Up:
            kUp=1;
            break;
        case Qt::Key_Down:
            kDown=1;
            break;
        case Qt::Key_Space:
            kShoot=1;
            break;
    }
}

void MyFriendTank::keyReleasing(QKeyEvent *event)
{
        switch(event->key()) {
           case Qt::Key_Left:
                kLeft=0;
                break;
           case Qt::Key_Right:
                kRight=0;
                break;
            case Qt::Key_Up:
                kUp=0;
                break;
            case Qt::Key_Down:
                kDown=0;
                break;
            case Qt::Key_Space:
                kShoot=0;
                break;
    }
}

void MyFriendTank::draw(QPainter* painter)
{
    switch(direction)
    {
       case Up:
            this->img = "://tank2U.png";
            break;
       case Down:
            this->img = "://tank2D.png";
            break;
        case Left:
            this->img = "://tank2L.png";
            break;
        case Right:
            this->img = "://tank2R.png";
            break;
    }
    QPixmap pixmap(img);
    painter->drawPixmap(x, y, width, height, pixmap);
}
