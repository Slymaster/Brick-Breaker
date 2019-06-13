#include "Libs.hh"
#include "CustomText.hh"
#include "GameEntity.hh"
#include <memory>

int main()
{
    //game instance:
    std::unique_ptr<GameEntity> game(new GameEntity());

    sf::Texture t1;

    t1.loadFromFile("asset/images/paddle.png");

    sf::Sprite paddle(t1);

    //paddle props:
    float stepx = 10;
    float x_old, x_new, x_start, y_start;
    sf::Vector2f actualPos;

    //ball props:
    float x_ini, y_ini;

    //Text game state:

    sf::RenderTexture texture;

    //clock
    sf::Clock clock;

    // Text
    sf::Text main_text, score_text;
    sf::Font font;

    // Chargement du fichier .ttf
    if(!font.loadFromFile("./asset/font/arial.ttf"))
    {
        std::cerr << "error loading font " << std::endl;
        return -1;
    }

    CustomText main(main_text,font);
    CustomText score(score_text,font);

    main_text.setPosition(20,5);
    score_text.setPosition(20,40);
    std::string scoreStr;


    //Create window
    sf::RenderWindow window(sf::VideoMode (644,480), "Brick breaker");

    window.setPosition(sf::Vector2i(120,50));

    //Create entity (brick, ball, paddle)
    sf::RectangleShape bricks[500];
    sf::CircleShape ball(10);

    //sf::RectangleShape paddle(sf::Vector2f(60, 10));

    //paddle.setFillColor(sf::Color::Blue);
    ball.setFillColor(sf::Color::Red);

    //Set start position of paddle and ball
    x_ini = paddle.getPosition().x;
    y_ini = paddle.getPosition().y - 30;
    // x_start = (window.getSize().x / 2) - (window.getSize().x / 2);
    // y_start = window.getSize().y - (30 + window.getSize().y);

    x_start = (window.getSize().x / 2);
    y_start = (window.getSize().y / 2);

    paddle.setPosition(x_start, y_start);
    ball.setPosition(x_ini, y_ini);

    sf::Vector2f ballSpeed(-2.0f,-2.0f);

    //border of the game field
    sf::RectangleShape borderTop;
    sf::RectangleShape borderBottom;
    sf::RectangleShape borderLeft;
    sf::RectangleShape borderRight;

    //highlight the border of the game stage
    borderLeft.setSize(sf::Vector2f(5, 640));
    borderLeft.setFillColor(sf::Color::Green);
    borderLeft.setPosition(sf::Vector2f(0,0));

    borderRight.setSize(sf::Vector2f(5, 640));
    borderRight.setFillColor(sf::Color::Green);
    borderRight.setPosition(sf::Vector2f(640,0));

    borderBottom.setSize(sf::Vector2f(640, 5));
    borderBottom.setFillColor(sf::Color::Red);
    borderBottom.setPosition(sf::Vector2f(0,479));

    borderTop.setSize(sf::Vector2f(640, 0.1));
    borderTop.setFillColor(sf::Color::White);
    borderTop.setPosition(sf::Vector2f(0,0));


    //fill the field with bricks
    for (unsigned i = 0; i < 500; i++)
    {
        bricks[i].setFillColor(sf::Color::Blue);
        bricks[i].setSize(sf::Vector2f(32, 12));
        bricks[i].setOutlineColor(sf::Color::Black);
        bricks[i].setOutlineThickness(1.f);

        if (i == 0)
        {
            bricks[i].setPosition(0, 0);
        }
        else if (i < 50)
        {
            bricks[i].setPosition(bricks[i-1].getPosition().x + bricks[i].getSize().x, 0);
        }
        else if (i==50)
        {
            bricks[i].setPosition(0, 0+bricks[i].getSize().y);
        }
        else if (i > 50 && i < 100)
        {
            bricks[i].setPosition(bricks[i-1].getPosition().x + bricks[i].getSize().x, bricks[i-1].getPosition().y);
        }
        else if (i==100)
        {
            bricks[i].setPosition(0, 12+bricks[i].getSize().y);
        }
        else if (i > 100 && i < 150)
        {
            bricks[i].setPosition(bricks[i-1].getPosition().x + bricks[i].getSize().x, bricks[i-1].getPosition().y);
        }
        else if (i==150)
        {
            bricks[i].setPosition(0, 24+bricks[i].getSize().y);
        }
        else if (i > 150 && i < 200)
        {
            bricks[i].setPosition(bricks[i-1].getPosition().x + bricks[i].getSize().x, bricks[i-1].getPosition().y);
        }

        else if (i==200)
        {
            bricks[i].setPosition(0, 36+bricks[i].getSize().y);
        }
        else if (i > 200 && i < 250)
        {
            bricks[i].setPosition(bricks[i-1].getPosition().x + bricks[i].getSize().x, bricks[i-1].getPosition().y);
        }
        else if (i==250)
        {
            bricks[i].setPosition(0, 48+bricks[i].getSize().y);
        }
        else if (i > 250 && i < 300)
        {
            bricks[i].setPosition(bricks[i-1].getPosition().x + bricks[i].getSize().x, bricks[i-1].getPosition().y);
        }
        else if (i==300)
        {
            bricks[i].setPosition(0, 60+bricks[i].getSize().y);
        }
        else if (i > 300 && i < 350)
        {
            bricks[i].setPosition(bricks[i-1].getPosition().x + bricks[i].getSize().x, bricks[i-1].getPosition().y);
        }
        else if (i==350)
        {
            bricks[i].setPosition(0, 72+bricks[i].getSize().y);
        }
        else if (i > 350 && i < 400)
        {
            bricks[i].setPosition(bricks[i-1].getPosition().x + bricks[i].getSize().x, bricks[i-1].getPosition().y);
        }
        else if (i==400)
        {
            bricks[i].setPosition(0, 84+bricks[i].getSize().y);
        }
        else if (i > 400 && i < 450)
        {
            bricks[i].setPosition(bricks[i-1].getPosition().x + bricks[i].getSize().x, bricks[i-1].getPosition().y);
        }
        else if (i==450)
        {
            bricks[i].setPosition(0, 96+bricks[i].getSize().y);
        }
        else if (i > 450 && i < 500)
        {
            bricks[i].setPosition(bricks[i-1].getPosition().x + bricks[i].getSize().x, bricks[i-1].getPosition().y);
        }

    }

    ball.setPosition(paddle.getPosition());

    //game loop:
    while(window.isOpen())
    {
        sf::Event Event;
        while(window.pollEvent(Event))
        {
            switch (Event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::KeyPressed:
                    switch(Event.key.code)
                    {
                        case sf::Keyboard::Right:
                            paddle.move(30,0);
                            /*actualPos = paddle.getPosition();
                            x_old = actualPos.x;
                            x_new = x_old + stepx;
                            paddle.setPosition(x_new,window.getSize().y - (30 + paddle.getSize().y));*/
                            break;

                        case sf::Keyboard::Left:
                            paddle.move(-30,0);
                            /*actualPos = paddle.getPosition();
                            x_old = actualPos.x;
                            x_new = x_old - stepx;
                            paddle.setPosition(x_new,window.getSize().y - (30 + paddle.getSize().y));*/
                            break;

                    }
                    break;
            }
        }

        //FPS frame per second (Le nombre d'images par seconde)
        sf::Time time = clock.getElapsedTime();
        float fps = 1.0f / time.asSeconds();

        main_text.setString( "FPS: "+std::to_string(fps) );

        clock.restart().asSeconds();

        window.clear();
        //Detect ball and brick collision
        for (int i = 0; i < 500; i++)
        {
            if(bricks[i].getGlobalBounds().intersects(ball.getGlobalBounds()))
            {
                ballSpeed.y = -ballSpeed.y; 

                bricks[i].setSize(sf::Vector2f(0,0)); 
                i = 499;
                game->setScore(5);
                scoreStr = std::to_string(game->getScore());
            }
        }

        //Detect collision between ball  the game field border
        if(borderTop.getGlobalBounds().intersects(ball.getGlobalBounds()))
            ballSpeed.y = - ballSpeed.y;

        if(borderBottom.getGlobalBounds().intersects(ball.getGlobalBounds()))
        {
            ballSpeed.y = - ballSpeed.y;
            ball.setPosition(paddle.getPosition());

            game->setScore(-game->getScore());//RAZ of score substract of the actual score
            scoreStr = std::to_string(game->getScore());

            while(!sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                main_text.setString("Game over !\nPress space to continue");
                /*text.setCharacterSize(30);
                text.setStyle(sf::Text::Bold);
                text.setFillColor(sf::Color::Magenta);
                text.setPosition(120, 100);*/
                window.draw(main_text);
                window.display();
            }
        }

        if(borderLeft.getGlobalBounds().intersects(ball.getGlobalBounds()))
            ballSpeed.x = - ballSpeed.x;

        if(borderRight.getGlobalBounds().intersects(ball.getGlobalBounds()))
            ballSpeed.x = - ballSpeed.x;


        /*
            Detect collision between ball and the paddle
        */
        if(paddle.getGlobalBounds().intersects(ball.getGlobalBounds()))
            ballSpeed.y = -ballSpeed.y;

        ball.move(ballSpeed.x, ballSpeed.y);

        window.clear();


        for (int i = 0; i < 500; i++)
            window.draw(bricks[i]);

        score_text.setString("Score: "+scoreStr);

        window.draw(borderTop);
        window.draw(borderBottom);
        window.draw(borderLeft);
        window.draw(borderRight);

        window.draw(paddle);
        window.draw(ball);
        window.draw(main_text);
        window.draw(score_text);

        window.display();
    }
}
