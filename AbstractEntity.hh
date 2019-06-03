#ifndef ABSTRACTENTITY_HH
#define ABSTRACTENTITY_HH

class AbstractEntity 
{
public:
    virtual void update()=0;
    virtual void draw()=0;
    virtual ~AbstractEntity();
};

#endif