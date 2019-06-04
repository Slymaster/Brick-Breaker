#include "WindowEntity.hh"

Window::draw(/*Entity to draw*/)
{
  window.draw();
}

Window::update()
{

}

Window::Window(float pos_X, float pos_Y, int width, int height)
{
  window.setPosition(sf::Vector2i(10, 20));
  window.setSize(sf::Vector2u(644, 480));
}
