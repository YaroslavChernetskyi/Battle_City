#include "enemyspeedy.h"

EnemySpeedy::EnemySpeedy(Direction direction, int x, int y, int ID): BadTank(direction, x, y, ID)
{
    points = 200;
    this->numberID =ID;
    speed = 2;
    typeID = 1;
}

void EnemySpeedy::draw(QPainter* painter)
{
    if(numberID==3||numberID==10||numberID==17)
    {
        switch(direction)
        {
           case Up:
                this->img = "://enemyTank2U_1.png";
                break;
           case Down:
                this->img = "://enemyTank2D_1.png";
                break;
            case Left:
                this->img = "://enemyTank2L_1.png";
                break;
            case Right:
                this->img = "://enemyTank2R_1.png";
                break;
        }
    }
    else
    {
        switch(direction)
        {
           case Up:
                this->img = "://enemyTank2U.png";
                break;
           case Down:
                this->img = "://enemyTank2D.png";
                break;
            case Left:
                this->img = "://enemyTank2L.png";
                break;
            case Right:
                this->img = "://enemyTank2R.png";
                break;
        }

    }
    QPixmap pixmap(img);
    painter->drawPixmap(x, y, width, height, pixmap);
}
