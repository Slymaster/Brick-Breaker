#ifndef GAMEFACTORY_HH
#define GAMEFACTORY_HH

#include "Libs.hh"

class GameFactory
{
public:
    Entity* create(const std::string& invoke);
};

#endif