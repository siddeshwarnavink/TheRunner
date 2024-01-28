#pragma once

#include <SFML/Graphics.hpp>

#include "entity/Actor/MainCharacter.h"

namespace Entity::Obstacle {
    class BaseObstacle {
        protected:
            static std::vector<sf::RectangleShape> obstacleList;
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
