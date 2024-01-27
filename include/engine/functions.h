// functions.h

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <SFML/Graphics.hpp>
#include <string>

void place_text(sf::RenderWindow& window, const std::string& message, const sf::Font& font, unsigned int fontSize, const sf::Vector2f& position, const sf::Color& color);

float Move_Logic();
void Jump_Logic(sf::Sprite& character,bool& IsJumping);
void Collision_Logic(sf::RectangleShape platform[],sf::Sprite& character,int ArrSize,bool& IsJumping);
#endif
