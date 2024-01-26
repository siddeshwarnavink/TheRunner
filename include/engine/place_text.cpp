#include <SFML/Graphics.hpp>
#include <string>

void place_text(sf::RenderWindow& window, const std::string& message, const sf::Font& font, unsigned int fontSize, const sf::Vector2f& position, const sf::Color& color) {
    sf::Text text;
    text.setFont(font);
    text.setString(message);
    text.setCharacterSize(fontSize);
    text.setPosition(position);
    text.setFillColor(color);

    window.draw(text);
}