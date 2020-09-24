#include "enemysimple.h"

EnemySimple::EnemySimple(Direction direction, int x, int y, int ID): BadTank(direction, x, y, ID)
{
    points = 100;
    this->numberID =ID;
    speed = (CELL/(CELL/1));
    typeID = 0;
}

void EnemySimple::draw(QPainter* painter)
{
    if(numberID==3||numberID==10||numberID==17)
    {
        switch(direction)
        {
           case Up:
                this->img = "://enemyTank1U_1.png";
                break;
           case Down:
                this->img = "://enemyTank1D_1.png";
                break;
            case Left:
                this->img = "://enemyTank1L_1.png";
                break;
            case Right:
                this->img = "://enemyTank1R_1.png";
                break;
        }
    }
    else
    {
        switch(direction)
        {
           case Up:
                this->img = "://enemyTank1U.png";
                break;
           case Down:
                this->img = "://enemyTank1D.png";
                break;
            case Left:
                this->img = "://enemyTank1L.png";
                break;
            case Right:
                this->img = "://enemyTank1R.png";
                break;
        }

    }
    QPixmap pixmap(img);
    painter->drawPixmap(x, y, width, height, pixmap);
}
