#pragma once

#include <SFML/Graphics.hpp>

namespace Entity::Actor {
    enum PlayerState {
        RUNNING,
        DEAD,
        JUMPING,
        FALLING
    };

    class MainCharacter {
        private:
            sf::Texture texture;
            sf::Sprite charactersprite;
            PlayerState state;
            float jumpHeight;

        public:
            MainCharacter();
            void loop();
            void display(sf::RenderWindow& window);
            void move(float x, float y);
            sf::Vector2f getPosition();
            sf::FloatRect getGlobalBounds();
            void setState(PlayerState state);
            PlayerState getState();
    };
}
