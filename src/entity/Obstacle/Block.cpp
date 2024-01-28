#include "entity/Obstacle/Block.h"
#include "entity/Obstacle/BaseObstacle.h"
#include "entity/Actor/MainCharacter.h"

namespace Entity::Obstacle {
    Block::Block(Actor::MainCharacter& mainCharacter) : BaseObstacle(mainCharacter) {
        obstacle.setSize(sf::Vector2f(50.0f, 50.0f));
        obstacle.setPosition(300.0f, 330.0f);
        obstacle.setFillColor(sf::Color::Red);
        obstacleList.push_back(obstacle);
    }

    void Block::loop() {
        BaseObstacle::loop();
        if (isColliding()) {
            mainCharacter.setState(Entity::Actor::PlayerState::DEAD);
        }
    }
}