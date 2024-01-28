#include "Generator/Generator.h"

namespace Generator {
    class BlockGenerator : public Generator {
        public:
            BlockGenerator(sf::RenderWindow& window, Actor::MainCharacter& mainCharacter);
        
        protected: 
            Obstacle::BaseObstacle* generate(float xPos, float yPos) override;
    };
};