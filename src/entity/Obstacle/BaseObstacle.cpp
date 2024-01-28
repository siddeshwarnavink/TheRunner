#include "entity/Entity.h"

namespace Entity {
    sf::RectangleShape obstacle;
    std::vector<sf::RectangleShape> BaseObstacle::obstacleList;

    BaseObstacle::BaseObstacle(MainCharacter& mainCharacter) : mainCharacter(mainCharacter)  {
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
        // ...
    }


    void BaseObstacle::display(sf::RenderWindow& window) {
        window.draw(obstacle);
    }

    void BaseObstacle::move(float x, float y) {
        obstacle.move(x, y);
    }
}
