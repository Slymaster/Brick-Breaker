#include "Libs.hh"
#include "GameEntity.hh"

#ifndef OBSERVER_HH
#define OBSERVER_HH

/* Class Observer:
 * It notify that the daughter class must have an update method
 * Instance of this interface have to register themselves to subject
 * and also unregister.
 */

class Observer
{

protected:
    GameEntity *game;

public:
    Observer(GameEntity *subject);
    virtual void update()=0;

};

class TextObserver: public Observer
{
private :
    sf::Text text;
public:
    TextObserver(GameEntity *game, sf::Text scoreTxt);
    void update() override;
};
#endif
// NEED OBSERVABLE