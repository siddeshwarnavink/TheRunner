#include "Generator/BlockGenerator.h"
#include "Generator/Generator.h"
#include "Entity/Obstacle/BaseObstacle.h"
#include "Entity/Obstacle/Block.h"

namespace Generator
{
    BlockGenerator::BlockGenerator(Actor::MainCharacter &player, Entity::Floor &floor, sf::RenderWindow &window) : Generator(player, floor, window)
    {
    }

    Entity::Obstacle::BaseObstacle *BlockGenerator::generate(float xPos, float yPos)
    {
        Entity::Obstacle::BaseObstacle *myBlock = new Entity::Obstacle::Block(player, floor, xPos, yPos);
        return myBlock;
    }
}