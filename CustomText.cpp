#include "CustomText.hh"
#include <SFML/Graphics.hpp>

CustomText::CustomText(sf::Text& text, sf::Font& font)
{
    text.setCharacterSize( 32 );
    text.setFillColor( sf::Color::White );
    text.setStyle( sf::Text::Style::Bold);
    text.setOutlineColor( sf::Color::Yellow );
    text.setFont(font);
}