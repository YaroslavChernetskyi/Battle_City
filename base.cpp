#include "base.h"

Base::Base()
{
    m_protected = false;
}

bool Base::isProtected()
{
    return m_protected;
}

void Base::setProtection(bool prot)
{
    m_protected = prot;
}

std::array<std::array<int, 2>, 8> Base::getBasePositions()
{
    baseArray = {{{176,368},
                  {176,384},
                  {176,400},
                  {192,368},
                  {208,368},
                  {224,368},
                  {224,384},
                  {224,400}}};
    return baseArray;
}
