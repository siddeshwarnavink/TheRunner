#include "Generator/Generator.h"

namespace Generator
{
    class BlockGenerator : public Generator
    {
    public:
        BlockGenerator(sf::RenderWindow &window, Actor::MainCharacter &mainCharacter, Entity::Floor &floor);

    protected:
        Entity::Obstacle::BaseObstacle *generate(float xPos, float yPos) override;
    };
};