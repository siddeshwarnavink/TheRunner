#include "Entity/Obstacle/Block.h"
#include "Entity/Obstacle/BaseObstacle.h"
#include "Actor/MainCharacter.h"

namespace Entity::Obstacle
{
    Block::Block(Actor::MainCharacter &mainCharacter, float posX, float posY) : BaseObstacle(mainCharacter)
    {
        texture.setSize(sf::Vector2f(50.0f, 50.0f));
        texture.setPosition(posX, posY);
        texture.setFillColor(sf::Color::Red);
    }

    void Block::loop()
    {
        BaseObstacle::loop();
    }
}