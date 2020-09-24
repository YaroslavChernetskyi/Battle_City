#ifndef GAMEOVERLABEL_H
#define GAMEOVERLABEL_H

#include "staticobject.h"

class GameOverLabel: public StaticObject
{
    int gameOverCounter{0};
public:
    GameOverLabel(int,int);
    QRectF boundRect() override;
    void draw(QPainter *) override;
};

#endif // GAMEOVERLABEL_H

