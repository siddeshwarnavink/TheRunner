#pragma once

#include <SFML/Graphics.hpp>

namespace Entity::Actor {
    class MainCharacter {
    private:
        sf::Texture texture;
        sf::Sprite charactersprite;
        bool isFalling;

    public:
        MainCharacter();
        void loop();
        void display(sf::RenderWindow& window);
        void move(float x, float y);
        sf::Vector2f getPosition();
        sf::FloatRect getGlobalBounds();
        void setJumping(bool isFalling);
        bool getJumping();
    };
}
