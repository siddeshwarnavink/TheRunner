#include <SFML/Graphics.hpp>
#include <engine/functions.h>
#include <cmath>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Idk Something");
    sf::Texture texture ;
    sf::Font font;
    sf::RectangleShape Block(sf::Vector2f(50.0f,50.0f));
    sf::RectangleShape Floor(sf::Vector2f(10000000.0f,10.0f));
    
    if (!font.loadFromFile("../assets/font/Roboto-Black.ttf")) {
        // Handle font loading error
        return -1;
    }
    
    if(!texture.loadFromFile("../assets/Character/mc.png")){
        return -1;
    }


    sf::Sprite charactersprite(texture);
    charactersprite.setPosition(40.0f,250.0f);
    Block.setPosition(300.0f,330.0f);
    Block.setFillColor(sf::Color::Red);
    Floor.setPosition(-1000.0f,380.0f);

    // Game loop
    while (window.isOpen()) {
  
        
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
    
        
        window.clear();
        window.draw(charactersprite);
        place_text(window,"Hi!!!",font,24,sf::Vector2f(100.0f, 100.0f),sf::Color::Red);
        place_text(window,"Hello there",font,24,sf::Vector2f(500.0f, 100.0f),sf::Color::Red);
        window.draw(Block);
        window.draw(Floor);
        window.display();
    }

    return 0;
}
     













