#include "entity/Actor/MainCharacter.h"

namespace Entity::Actor {
    sf::Sprite charactersprite;

    MainCharacter::MainCharacter() : isFalling(true) {
        if (!texture.loadFromFile("./assets/Character/mc.png")) {
            return;
        }
        charactersprite.setTexture(texture);
        charactersprite.setPosition(40.0f, 200.0f);
    }

    void MainCharacter::display(sf::RenderWindow& window) {
        window.draw(charactersprite);
    }

    void MainCharacter::loop() {
        // Jump logic
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && isFalling == true) {
            for (int i = 0; i < 1000; i++) {
                charactersprite.move(0.0f, -0.1f);
            }
        }
        else {
            charactersprite.move(0.0f, 0.0f);
        }
    }

    void MainCharacter::move(float x, float y) {
        charactersprite.move(x, y);
    }

    sf::FloatRect MainCharacter::getGlobalBounds() {
        return charactersprite.getGlobalBounds();
    }

    sf::Vector2f MainCharacter::getPosition() {
        return charactersprite.getPosition();
    }

    void MainCharacter::setJumping(bool isFalling) {
        this->isFalling = isFalling;
    }

    bool MainCharacter::getJumping() {
        return this->isFalling;
    }
}
