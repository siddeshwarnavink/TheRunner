#include "Game.h"
#include "entity/Entity.h"

void Game::run() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Idk Something");
    if (!font.loadFromFile("./assets/font/Roboto-Black.ttf")) {   
        return;
    }

    Entity::Actor::MainCharacter mc;
    Entity::Obstacle::Block block(mc);
    Entity::Obstacle::Floor floor(mc);

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
        mc.loop();

        isColliding = !isColliding && block.isColliding();
        isColliding = !isColliding && floor.isColliding();

        // Gravity
        if(isColliding) {
            mc.setJumping(false);
            mc.move(0.0f, 0.0f);
        } else {
            mc.setJumping(true);
            mc.move(0.0f, 0.2f);
        }

        mc.display(window);
        block.display(window);
        floor.display(window);
        window.display();
    }
}