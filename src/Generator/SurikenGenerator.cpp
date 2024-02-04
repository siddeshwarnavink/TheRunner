#include "Generator/SurikenGenerator.h"
#include "Generator/Generator.h"
#include "Entity/Obstacle/BaseObstacle.h"
#include "Entity/Obstacle/Suriken.h"

namespace Generator
{
    SurikenGenerator::SurikenGenerator(Actor::MainCharacter &player, Entity::Floor &floor, sf::RenderWindow &window) : Generator(player, floor, window)
    {
        setSpawningProbability(0.5f);
    }

    Entity::Obstacle::BaseObstacle *SurikenGenerator::generate(float xPos, float yPos)
    {
        Entity::Obstacle::BaseObstacle *mySuriken = new Entity::Obstacle::Suriken(player, floor, xPos, yPos);
        return mySuriken;
    }
}