#pragma once

#include <SFML/Graphics.hpp>

namespace Actor {
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
            sf::Vector2f initialPosition;
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
