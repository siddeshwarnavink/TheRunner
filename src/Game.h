#include <SFML/Graphics.hpp>

#include "State/GameState.h"
#include "Actor/MainCharacter.h"
#include "Entity/Floor.h"
#include "Generator/BlockGenerator.h"
#include "Generator/SurikenGenerator.h"
#include "Static/SkyBackground.h"

class Game
{
private:
    static bool running;
    float movementVelocity;
    float currentFPS;
    sf::Font font;
    sf::RenderWindow window;
    Actor::MainCharacter player;
    Entity::Floor floor;
    State::GameState gameState;
    Static::SkyBackground background;
    // Generator::BlockGenerator blockGenerator;
    Generator::SurikenGenerator blockGenerator;
    sf::Clock fpsClock;
    sf::Clock speedBoostClock;
    sf::Time frameTime;
    sf::Time speedBoostTime;
    void loadAssets();
    void exitWindow();
    void fpsLock();
    void handleSpeedBoost();
    void playerPhysics();

public:
    Game();
    static bool isColliding;
    static float speedBoost;
    void run();
};