#include "Generator/Generator.h"

namespace Generator
{
    class BlockGenerator : public Generator
    {
    public:
        BlockGenerator(Actor::MainCharacter &player, Entity::Floor &floor, sf::RenderWindow &window);

    protected:
        Entity::Obstacle::BaseObstacle *generate(float xPos, float yPos) override;
    };
};