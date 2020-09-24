#include "mytank.h"

MyTank::MyTank(Direction direction, int x, int y):GoodTank (direction, x, y)
{
   ID=0;
}

void MyTank::keyMoving(QKeyEvent *event)
{
    switch(event->key()) {
       case Qt::Key_A:
            kLeft=1;
            break;
       case Qt::Key_D:
            kRight=1;
            break;
        case Qt::Key_W:
            kUp=1;
            break;
        case Qt::Key_S:
            kDown=1;
            break;
        case Qt::Key_E:
            kShoot=1;
            break;
    }
}

void MyTank::keyReleasing(QKeyEvent *event)
{
        switch(event->key()) {
           case Qt::Key_A:
                kLeft=0;
                break;
           case Qt::Key_D:
                kRight=0;
                break;
            case Qt::Key_W:
                kUp=0;
                break;
            case Qt::Key_S:
                kDown=0;
                break;
            case Qt::Key_E:
                kShoot=0;
                break;
    }
}

void MyTank::draw(QPainter* painter)
{
    switch(direction)
    {
       case Up:
            this->img = "://tank1U.png";
            break;
       case Down:
            this->img = "://tank1D.png";
            break;
        case Left:
            this->img = "://tank1L.png";
            break;
        case Right:
            this->img = "://tank1R.png";
            break;
    }
    QPixmap pixmap(img);
    painter->drawPixmap(x, y, width, height, pixmap);
}
