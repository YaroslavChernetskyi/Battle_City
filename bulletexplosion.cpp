#include "bulletexplosion.h"


QString BulletExplosion::explosingImage()
{
    explosionCounter++;
    if(explosionCounter<2)
    {
        return "://smallBabah";
    }
    else if(explosionCounter<4)
    {
        return "://mediumBabah";
    }
    else if(explosionCounter<7)
    {
        return "://bigBabah";
    }
    else
    {
        explosionCounter = 0;
        return "";
    }
}
