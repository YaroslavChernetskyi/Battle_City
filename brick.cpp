#include "brick.h"
#include "QDebug"

Brick::Brick(int x, int y):StaticObject (x,y)
{
    width = CELL/2;
    height = CELL/2;
    img = "://brick.png";
destroyed = false;
state = 0;
}

QRectF Brick::boundRect()
{
    return QRectF(this->x,this->y,width, height);
}

void Brick::draw(QPainter * painter)
{
    QPixmap pixmap(img);
    painter->drawPixmap(x, y, width, height, pixmap);
}

void Brick::getDamage(MovingObject::Direction dir)
{
    switch (state)
    {
    case 0:
        switch (dir)
        {
        case MovingObject::Right:
            img = "://brickRUD";
            state=1;
            break;
        case MovingObject::Left:
            img = "://brickLUD";
            state=2;
            break;
        case MovingObject::Down:
            img = "://brickDLR";
            state=3;
            break;
        case MovingObject::Up:
            img = "://brickULR";
            state=4;
            break;
        }
        break;
     case 1:
            switch (dir)
            {
            case MovingObject::Right:
                destroy();
                break;
            case MovingObject::Left:
                destroy();
                break;
            case MovingObject::Down:
                img = "://brickRD";
                state=5;
                break;
            case MovingObject::Up:
                img = "://brickRU";
                state=5;
                break;
            }
            break;
         case 2:
                switch (dir)
                {
                case MovingObject::Right:
                    destroy();
                    break;
                case MovingObject::Left:
                    destroy();
                    break;
                case MovingObject::Down:
                    img = "://brickLD";
                    state=5;
                    break;
                case MovingObject::Up:
                    img = "://brickLU";
                    state=5;
                    break;
                }
                break;
            case 3:
                    switch (dir)
                    {
                    case MovingObject::Right:
                        img = "://brickRD";
                        state=5;
                        break;
                    case MovingObject::Left:
                        img = "://brickLD";
                        state=5;
                        break;
                    case MovingObject::Down:
                        destroy();
                        break;
                    case MovingObject::Up:
                        destroy();
                        break;
                   }
                   break;
            case 4:
                    switch (dir)
                    {
                    case MovingObject::Right:
                        img = "://brickRU";
                        state=5;
                        break;
                    case MovingObject::Left:
                        img = "://brickLU";
                        state=5;
                        break;
                    case MovingObject::Down:
                        destroy();
                        break;
                    case MovingObject::Up:
                        destroy();
                        break;
                    }
                    break;
            case 5:
                    destroy();
                     break;


    }
}

