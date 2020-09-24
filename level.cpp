#include "level.h"
#include "QDebug"

Level::Level()
{
    level = 0;
    maxLevel = 1;
}

QString Level::getMapFile()
{
    if(level>maxLevel)
    {
        level = 0;
    }
    level++;
    QString valueAsString = QString::number(level);
    return "://map" +valueAsString + ".txt";
}

QString Level::getTankFile()
{
    QString valueAsString = QString::number(level);
    return "://tankLevel" +valueAsString + ".txt";
}

void Level::draw(QPainter * painter)
{
    switch (level) {
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
    QPixmap life("://flag.png");
    painter->drawPixmap(13*CELL+CELL/2, 11*CELL, CELL, CELL, life);
    painter->drawPixmap(14*CELL, 11*CELL+CELL/2, CELL/2, CELL/2, pixmap);
}
