#ifndef PADDLEENTITY_HH
#define PADDLEENTITY_HH

#include "Entity.hh"

class Paddle : public Entity
{
public:
    Paddle(); // constructeur

    void Update();
    void Draw();
};

#endif