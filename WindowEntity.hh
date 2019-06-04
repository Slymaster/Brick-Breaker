#ifndef WINDOWENTITY_HH
#define WINDOWENTITY_HH

class Window: public AbstractEntity
{
public:
  sf::RenderWindow window;
  
  //Constructor:
  Window(float pos_X, pos_Y, int width, height)
  {
    window.setPosition(sf::Vector2i(10, 20));
    window.setSize(sf::Vectore2u(644, 480));
  }
  
  virtual void update() override;
  virtual void draw(/*Entity to draw*/) override;
  virtual void ~Window() = 0;
};
#endif
