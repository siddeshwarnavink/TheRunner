#include "entity/Entity.h"

namespace Entity {
    Floor::Floor(MainCharacter& mainCharacter) : BaseObstacle(mainCharacter) {
        obstacle.setSize(sf::Vector2f(1000.0f,10.0f));
        obstacle.setPosition(-500.0f,380.0f);
        obstacleList.push_back(obstacle);
    }
}