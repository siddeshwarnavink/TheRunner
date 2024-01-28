#include "Game.h"
#include "entity/Actor/MainCharacter.h"
#include "entity/Obstacle/Block.h"
#include "entity/Obstacle/Floor.h"

void Game::run() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Idk Something");
    if (!font.loadFromFile("./assets/font/Roboto-Black.ttf")) {   
        return;
    }

    Entity::Actor::MainCharacter player;
    Entity::Obstacle::Block block(player);
    Entity::Obstacle::Floor floor(player);

    float movementVelocity;
    bool isColliding = false;

    sf::Clock clock;
    float targetFPS = 2000.0f;
    sf::Time frameTime = sf::seconds(1.0f / targetFPS);

    // Game loop
    while (window.isOpen()) {
        sf::Time elapsed = clock.restart();
        if (elapsed < frameTime) {
            sf::sleep(frameTime - elapsed);
            elapsed = frameTime;
        }

        window.clear();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Movement logic
        movementVelocity = 0.0f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            movementVelocity = -0.2f;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            movementVelocity =  0.2f;
        }

        block.move(-movementVelocity, 0.0f);
        floor.move(-movementVelocity, 0.0f);

        block.loop();
        floor.loop();
        player.loop();

        isColliding = !isColliding && block.isColliding();
        isColliding = !isColliding && floor.isColliding();

        // Gravity
        if(isColliding) {
            player.setState(Entity::Actor::PlayerState::RUNNING);
            player.move(0.0f, 0.0f);
        } else if(player.getState() != Entity::Actor::PlayerState::JUMPING) {
            player.setState(Entity::Actor::PlayerState::FALLING);
            player.move(0.0f, 0.2f);
        }

        player.display(window);
        block.display(window);
        floor.display(window);
        window.display();
    }
}