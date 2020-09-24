#ifndef DESTROYABLE_H
#define DESTROYABLE_H

class Destroyable
{
public:
    virtual void destroy() = 0;
    virtual bool isDestroyed() = 0;
    virtual ~Destroyable() = default;
};

#endif // DESTROYABLE_H
