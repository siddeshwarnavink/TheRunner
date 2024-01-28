#include "entity/Entity.h"

namespace Entity {
    Block::Block(MainCharacter& mainCharacter) : BaseObstacle(mainCharacter) {
        obstacle.setSize(sf::Vector2f(50.0f,50.0f));
        obstacle.setPosition(300.0f,330.0f);
        obstacle.setFillColor(sf::Color::Red);
        obstacleList.push_back(obstacle);
    }
}