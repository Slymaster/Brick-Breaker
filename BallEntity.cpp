#include "BallEntity.hh"

//contructor:
BallEntity::BallEntity(float posX, float posY)
{
    ball.setPosition(posX, posY);
    ball.setRadius(20);
    ball.setFillColor(color);
    ball.setOrigin(radius, radius);
}

void BallEntity::Update()
{
    ball.move(trjVector);
}

void BallEntity::Draw(sf::RenderWindow &window)
{
    window.draw(ball);
}

void BallEntity::~BallEntity() 
{
}
