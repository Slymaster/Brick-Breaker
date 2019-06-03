#ifndef BALLENTITY_HH
#define BALLENTITY_HH

class Ball : public AbstractEntity
{
public:
    static const sf::Color color;
    static constexpr float radius{10.f};
    static constexpr float trajectory{2.0f};

    sf::CircleShape shape;
    sf::Vector2f trjVector{-trajectory, -trajectory};

    virtual void update() override;
    virtual void draw(sf::RenderWindow &window) override;

    virtual ~Ball()=0;
};

#endif