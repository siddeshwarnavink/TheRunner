#include "Generator/BlockGenerator.h"
#include "Generator/Generator.h"
#include "Entity/Obstacle/BaseObstacle.h"
#include "Entity/Obstacle/Block.h"

namespace Generator
{
    BlockGenerator::BlockGenerator(sf::RenderWindow &window, Actor::MainCharacter &mainCharacter) : Generator(window, mainCharacter)
    {
    }

    Entity::Obstacle::BaseObstacle *BlockGenerator::generate(float xPos, float yPos)
    {
        Entity::Obstacle::BaseObstacle *myBlock = new Entity::Obstacle::Block(mainCharacter, xPos, yPos);
        return myBlock;
    }
}