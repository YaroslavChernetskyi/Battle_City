#include "staticobject.h"

StaticObject::StaticObject(int x, int y):
    x(x),
    y(y)
{
 destroyed = false;
}

int StaticObject::getX()
{
    return x;
}

int StaticObject::getY()
{
    return y;
}

int StaticObject::getHeight()
{
    return height;
}

int StaticObject::getWidth()
{
    return width;
}

bool StaticObject::isDestroyed()
{
    return destroyed;
}

void StaticObject:: destroy(){
    this->destroyed = true;
}
