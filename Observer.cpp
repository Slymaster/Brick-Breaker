#include "Observer.hh"

Observer::Observer(GameEntity *subject)
{
   game = subject;
}

TextObserver::TextObserver(GameEntity *game, sf::Text scoreTxt)
    : Observer(game), text(scoreTxt)
{
}

void TextObserver::update()
{
   int score = game->getScore();

   std::string scoreStr =  std::to_string(score);

   text.setString(scoreStr);
}
