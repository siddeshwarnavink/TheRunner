#include <SFML/Graphics.hpp>
#include <engine/functions.h>
#include <cmath>
#include <iostream>

int main() {

    //Basic Initialization
    sf::RenderWindow window(sf::VideoMode(800, 600), "Idk Something");
    sf::Texture texture ;
    sf::Font font;
    sf::RectangleShape Block(sf::Vector2f(50.0f,50.0f));
    sf::RectangleShape Floor(sf::Vector2f(1000.0f,10.0f));

    sf::RectangleShape obstacles[2];
    
    //Loading Error handles
    if (!font.loadFromFile("./assets/font/Roboto-Black.ttf")) {
        
        return -1;
    }
    
    if(!texture.loadFromFile("./assets/Character/mc.png")){
        return -1;
    }



    //Entities placement
    sf::Sprite charactersprite(texture);
    charactersprite.setPosition(40.0f,200.0f);
    Block.setPosition(300.0f,330.0f);
    Block.setFillColor(sf::Color::Red);
    Floor.setPosition(-500.0f,380.0f);

    

    std::cout<< charactersprite.getPosition().x+charactersprite.getGlobalBounds().width;
    //Initial Testing Assumptions
    float MovementVelocity = 0.0f;
    float JumpVelocity = 0.0f;
    bool IsFalling = true;

    // Game loop
    while (window.isOpen()) {
  
        
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        
        
       // JumpVelocity = Collision_Logic(obstacles,charactersprite,2);
        Collision_Logic(obstacles,charactersprite,2,IsFalling);
       // JumpVelocity=Jump_Logic();
       Jump_Logic(charactersprite,IsFalling);
        MovementVelocity = Move_Logic();
        
        
        charactersprite.move(0.0f,JumpVelocity);
        Floor.move(-MovementVelocity,0.0f);
        Block.move(-MovementVelocity,0.0f);
        obstacles[0] =Floor;
        obstacles[1] = Block;
        window.clear();
        window.draw(charactersprite);

        place_text(window,std::to_string(IsFalling),font,24,sf::Vector2f(100.0f, 100.0f),sf::Color::Green);
        place_text(window,std::to_string(obstacles[0].getPosition().y-(charactersprite.getPosition().y+charactersprite.getGlobalBounds().height)),font,24,sf::Vector2f(500.0f, 100.0f),sf::Color::Red);

        window.draw(Block);
        window.draw(Floor);
        window.display();
    }

    return 0;
}
     













