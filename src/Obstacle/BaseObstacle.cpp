#include <iostream>

#include "Obstacle/BaseObstacle.h"
#include "Actor/MainCharacter.h"
#include "Game.h"

namespace Obstacle {
    sf::RectangleShape obstacle;

    BaseObstacle::BaseObstacle(Actor::MainCharacter& mainCharacter) : mainCharacter(mainCharacter)  {
    }

    bool BaseObstacle::isColliding() {
        sf::FloatRect mainCharacterBounds = mainCharacter.getGlobalBounds();
        sf::FloatRect obstacleBounds = obstacle.getGlobalBounds();
        return mainCharacterBounds.intersects(obstacleBounds);
    }

    void BaseObstacle::loop() {
        // Collision
        Game::isColliding = !Game::isColliding && isColliding();
    }


    void BaseObstacle::display(sf::RenderWindow& window) {
        window.draw(obstacle);
    }

    void BaseObstacle::move(float x, float y) {
        obstacle.move(x, y);
    }
}
