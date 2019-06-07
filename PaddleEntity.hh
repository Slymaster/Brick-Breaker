#ifndef PADDLEENTITY_HH
#define PADDLEENTITY_HH

#include "Entity.hh"

class PaddleEntity : public Entity
{
public:
    PaddleEntity(); // constructeur

    void Update();
    void Draw();
};

#endif