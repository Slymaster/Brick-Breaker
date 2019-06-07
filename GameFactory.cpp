#include "GameFactory.hh"

Entity* GameFactory::Create(const std::string &invoke) 
{
    if(invoke=="BallEntity") {
        return new BallEntity();
    } else if (invoke=="GameEntity") {
        return new BallEntity();
    }
    return NULL;
}