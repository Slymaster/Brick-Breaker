#include "BallEntity.hh"

//contructor:
Ball(float posX, float posY)
{
    ball.setPosition(posX, posY);
    ball.setRadius(20);
    ball.setFillColor(color);
    ball.setOrigin(radius, radius);
}

void Ball::update()
{
    ball.move(trjVector);
}

void Ball::draw(sf::RenderWindow &window)
{
    window.draw(ball);
}

void Ball::~Ball() 
{
}

};
