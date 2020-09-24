#include "lifes.h"
#include "QDebug"


void Lifes::draw(QPainter * painter, int num)
{
    switch (num) {
    case 0:
        img = "://0.png";
        break;
    case 1:
        img = "://1.png";
        break;
    case 2:
        img = "://2.png";
        break;
    case 3:
        img = "://3.png";
        break;
    case 4:
        img = "://4.png";
        break;
    }
    QPixmap pixmap(img);
    QPixmap life("://playerHP.png");
    painter->drawPixmap(13*CELL+CELL/2, 8*CELL, CELL, CELL, life);
    painter->drawPixmap(14*CELL, 8*CELL+CELL/2, CELL/2, CELL/2, pixmap);
}

