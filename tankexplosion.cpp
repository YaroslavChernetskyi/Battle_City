#include "tankexplosion.h"
#include "QDebug"
#include "enemysimple.h"

QString TankExplosion::explosingImage()
{
    explosionCounter++;
    if(explosionCounter<2)
    {
        return "://smallBabah";
    }
    else if(explosionCounter<6)
    {
        return "://mediumBabah";
    }
    else if(explosionCounter<10)
    {
        return "://bigBabah";
    }
    else if(explosionCounter<25)
    {
        return "://babah";
    }
    else if(explosionCounter<41)
    {
        return "://babah2";
    }
    else if(explosionCounter<61)
    {
        return "://babah";
    }
    else
    {
        explosionCounter = 0;
        return "";
    }
}
