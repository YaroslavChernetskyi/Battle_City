#ifndef STATICOBJECT_H
#define STATICOBJECT_H

#include <QString>
#include "drawable.h"
#include "positional.h"
#include "destroyable.h"

const int CELL = 32;
const int WIDTH = 13;
const int HEIGHT = 13;

class StaticObject: public Positional, public Drawable, public Destroyable
{

public:
    StaticObject(int, int);
    int getX() override final;
    int getY() override final;
    int getHeight() override final;
    int getWidth() override final;
    void draw(QPainter *) override = 0;
    QRectF boundRect() override = 0;
    void destroy() override;
    bool isDestroyed() override;

protected:
    int width, height;
    int x, y;
    QString img;
    bool destroyed;

};

#endif // STATICOBJECT_H
