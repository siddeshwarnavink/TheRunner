#include "Obstacle/BaseObstacle.h"
#include "Actor/MainCharacter.h"
#include "Game.h"

namespace Obstacle {
    sf::RectangleShape obstacle;

    BaseObstacle::BaseObstacle(Actor::MainCharacter& mainCharacter) : mainCharacter(mainCharacter)  {
    }

    bool BaseObstacle::isColliding() {
        if (mainCharacter.getPosition().x >= obstacle.getPosition().x && mainCharacter.getPosition().x <= (obstacle.getPosition().x + obstacle.getGlobalBounds().width)) {
            if (obstacle.getPosition().y - (mainCharacter.getPosition().y + mainCharacter.getGlobalBounds().height) <= 1.0f) {
                return true;
            }
        }
        return false;
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
