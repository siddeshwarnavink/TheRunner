#include "Generator/BlockGenerator.h"
#include "Generator/Generator.h"
#include "Entity/Obstacle/BaseObstacle.h"
#include "Entity/Obstacle/Block.h"

namespace Generator
{
    BlockGenerator::BlockGenerator(sf::RenderWindow &window, Actor::MainCharacter &mainCharacter, Entity::Floor &floor) : Generator(window, mainCharacter, floor)
    {
    }

    Entity::Obstacle::BaseObstacle *BlockGenerator::generate(float xPos, float yPos)
    {
        Entity::Obstacle::BaseObstacle *myBlock = new Entity::Obstacle::Block(mainCharacter, floor, xPos, yPos);
        return myBlock;
    }
}