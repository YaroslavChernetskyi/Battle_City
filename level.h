#ifndef LEVEL_H
#define LEVEL_H

#include "QString"
#include "QPainter"
#include "staticobject.h"
class Level
{
    QString img;
    int level;
    int maxLevel;
public:
    Level();
    QString getMapFile();
    QString getTankFile();
    void draw(QPainter*);
};

#endif // LEVEL_H
