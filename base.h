#ifndef BASE_H
#define BASE_H
#include "brick.h"

class Base
{
    bool m_protected;
    std::array<std::array<int,2>,8> baseArray;
public:
    Base();
    void setProtection(bool);
    bool isProtected();
    std::array<std::array<int,2>,8> getBasePositions();
};

#endif // BASE_H
