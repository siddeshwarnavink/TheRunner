#include "Generator/BlockGenerator.h"
#include "Generator/Generator.h"
#include "Obstacle/BaseObstacle.h"
#include "Obstacle/Block.h"

namespace Generator {
    BlockGenerator::BlockGenerator(sf::RenderWindow& window, Actor::MainCharacter& mainCharacter) : Generator(window, mainCharacter) {
    }

    Obstacle::BaseObstacle* BlockGenerator::generate(float xPos, float yPos) {
        Obstacle::BaseObstacle* myBlock = new Obstacle::Block(mainCharacter, xPos, yPos);
        return myBlock;
    }
}