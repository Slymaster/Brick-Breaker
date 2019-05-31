class Ball
{
public:
    static const sf::Color color;
    static constexpr float radius{10.f};
    static constexpr float trajectory{2.0f};

    sf::CircleShape shape;

    sf::Vector2f trjVector{-trajectory, -trajectory};

    //contructor:
    Ball(float posX, float posY)
    {
        ball.setPosition(posX, posY);
        ball.setRadius(20);
        ball.setFillColor(color);
        ball.setOrigin(radius, radius);
    }

    void update()
    {
        ball.move(trjVector);
    }

    void draw(sf::RenderWindow &window)
    {
        window.draw(ball);
    }

};
