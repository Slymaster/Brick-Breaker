#ifndef ENTITY_HH
#define ENTITY_HH

// Les méthodes qui sont communes aux entités

class Entity : public AbstractEntity
{
public:
    // double GetX() const;
    // void SetX(double X);

    // double GetY() const;
    // void SetY(double Y);

    virtual ~Entity()=0;

    // override from abstract
    virtual void Update() override;
    virtual void Draw() override;

    // Observer?
}

#endif