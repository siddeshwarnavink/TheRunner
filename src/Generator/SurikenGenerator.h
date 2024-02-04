#include "Generator/Generator.h"

namespace Generator
{
    class SurikenGenerator : public Generator
    {
    public:
        SurikenGenerator(Actor::MainCharacter &player, Entity::Floor &floor, sf::RenderWindow &window);

    protected:
        Entity::Obstacle::BaseObstacle *generate(float xPos, float yPos) override;
    };
};