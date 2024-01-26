#include "engine/functions.h"

void place_text(sf::RenderWindow& window, const std::string& message, const sf::Font& font, unsigned int fontSize, const sf::Vector2f& position, const sf::Color& color) {
    sf::Text text;
    text.setFont(font);
    text.setString(message);
    text.setCharacterSize(fontSize);
    text.setPosition(position);
    text.setFillColor(color);

    window.draw(text);
}


float Move_Logic(){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        return -0.2f;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        return 0.2f;
    }

    return 0.0f;
}