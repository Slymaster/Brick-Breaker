#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>


// taille de la fenêtre
const int WIDTH     = 1600;
const int HEIGHT    = 800;

// position initiale sur axe x du paddle
const int x_initial = 700;


//Paddle movement:
/*int moveRight(sf::RectangleShape paddle, int step)
{
    std::cout << "In the function move\n";
    int x_old, x_new;
    sf::Vector2f actualPos;

    actualPos = paddle.getPosition();
    
    x_old = actualPos.x;

    x_new = x_old + step;
    paddle.setPosition(x_new,600);

    return 0;


}*/

int main()
{
    int step = 40;
    int x_old = x_initial;
    int x_new;


    //Create window
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Brick_breaker");

    //Creat ball (make a file with name like "ballManager")
    sf::CircleShape ball(25);//ball with radius of 25
    ball.setFillColor(sf::Color::Green);
    ball.setPosition(x_initial, 520);

    //Create the paddle(make "paddleManager")
    sf::RectangleShape paddle(sf::Vector2f(100, 10));
    paddle.setFillColor(sf::Color::Red);
    paddle.setPosition(x_initial, 600);

    sf::Vector2f actualPos;//create 2D vector with x,y
    //ball.setRadius(40);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){

                actualPos = paddle.getPosition();
                x_old = actualPos.x;
                x_new = x_old + step;
                paddle.setPosition(x_new,600);

               // moveRight(paddle, step);

            }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
                actualPos = paddle.getPosition();
                x_old = actualPos.x;
                x_new = x_old - step;
                paddle.setPosition(x_new,600);
            }
            
        }

        window.clear();
        window.draw(ball);
        window.draw(paddle);
        window.display();
    }

    return 0;
}

