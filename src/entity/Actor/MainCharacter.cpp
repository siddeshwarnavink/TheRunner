#include "entity/Actor/MainCharacter.h"

namespace Entity::Actor {
    sf::Sprite charactersprite;

    MainCharacter::MainCharacter() : state(PlayerState::FALLING), jumpHeight(140.0f) {
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
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && state == PlayerState::RUNNING)
            || state == PlayerState::JUMPING) {
            
            if(charactersprite.getPosition().y >= jumpHeight) {
                state = PlayerState::JUMPING;
                charactersprite.move(0.0f, -0.15f);
            } else {
                state = PlayerState::FALLING;
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

    void MainCharacter::setState(PlayerState state) {
        this->state = state;
    }

    PlayerState MainCharacter::getState() {
        return this->state;
    }
}
