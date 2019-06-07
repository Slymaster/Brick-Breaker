#ifndef BALLENTITY_HH
#define BALLENTITY_HH

class BallEntity : public Entity
{
public:
    static const sf::Color color;
    static constexpr float radius{10.f};
    static constexpr float trajectory{2.0f};

    sf::CircleShape shape;
    sf::Vector2f trjVector{-trajectory, -trajectory};

    virtual void Update() override;
    virtual void Draw(sf::RenderWindow &window) override;

    virtual ~BallEntity()=0;
};

#endif