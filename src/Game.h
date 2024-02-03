#include <SFML/Graphics.hpp>

#include "State/GameState.h"
#include "Actor/MainCharacter.h"
#include "Entity/Floor.h"
#include "Generator/BlockGenerator.h"
#include "Static/SkyBackground.h"

class Game
{
private:
    static bool running;
    float movementVelocity;
    sf::Font font;
    sf::RenderWindow window;
    Actor::MainCharacter player;
    Entity::Floor floor;
    State::GameState gameState;
    Static::SkyBackground background;
    Generator::BlockGenerator blockGenerator;
    sf::Clock fpsClock;
    sf::Time frameTime;
    void loadAssets();
    void exitWindow();
    void fpsLock();
    void playerPhysics();

public:
    Game();
    static bool isColliding;
    void run();
};