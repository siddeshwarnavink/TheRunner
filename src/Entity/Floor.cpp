#include "Entity/Floor.h"
#include "Entity/BaseEntity.h"
#include "Actor/MainCharacter.h"

namespace Entity
{
    Floor::Floor(Actor::MainCharacter &mainCharacter) : BaseEntity(mainCharacter)
    {
        texture.setSize(sf::Vector2f(5000.0f, 10.0f));
        texture.setPosition(-500.0f, 380.0f);
    }

    void Floor::loop()
    {
        BaseEntity::loop();
    }
}