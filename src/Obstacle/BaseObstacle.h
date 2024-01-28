#pragma once

#include <SFML/Graphics.hpp>

#include "Actor/MainCharacter.h"

namespace Obstacle {
    class BaseObstacle {
        protected:
            sf::RectangleShape obstacle;
            Actor::MainCharacter& mainCharacter;
            bool isColliding();

        public:
            BaseObstacle(Actor::MainCharacter& mainCharacter);
            void loop();
            void move(float x, float y);
            void display(sf::RenderWindow& window);
        };
}
