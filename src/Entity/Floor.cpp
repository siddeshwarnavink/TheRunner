#include <iostream>

#include "Entity/Floor.h"
#include "Entity/BaseEntity.h"
#include "Actor/MainCharacter.h"
#include "Game.h"

namespace Entity
{
    const int Floor::floorCount = 20;

    Floor::Floor(Actor::MainCharacter &player) : BaseEntity(player)
    {
        if (!tileTexture.loadFromFile("./assets/texture/background/floor.png"))
        {
            std::cout << "Error: Failed to load floor.png" << std::endl;
            exit(1);
        }
        initializeTiles();
    }

    Floor::~Floor()
    {
        for (FloorComponents::FloorTile *tilePtr : floorTiles)
        {
            delete tilePtr;
        }
        floorTiles.clear();
    }

    void Floor::initializeTiles()
    {
        float xPos = 0.0f, yPos = 380.0f;
        FloorComponents::FloorTile *prevTile = nullptr;
        sf::IntRect spriteRegion(3, 0, 45, 44);

        for (int i = floorCount - 1; i >= 0; i--)
        {
            sf::Sprite floorSprite;
            floorSprite.setTexture(tileTexture);
            floorSprite.setTextureRect(spriteRegion);
            floorSprite.setPosition(xPos, yPos);

            FloorComponents::FloorTile *newTile = new FloorComponents::FloorTile(floorSprite, FloorComponents::FLAT);
            if (newTile != nullptr)
            {
                floorTiles.push_back(newTile);
                xPos += floorSprite.getGlobalBounds().width - 5;
            }
        }
    }

    bool Floor::isColliding()
    {
        sf::FloatRect playerBounds = player.getGlobalBounds();

        for (FloorComponents::FloorTile *tilePtr : floorTiles)
        {
            if (playerBounds.intersects(tilePtr->getTileSprite().getGlobalBounds()))
            {
                return true;
            }
        }

        return false;
    }

    void Floor::display(sf::RenderWindow &window)
    {
        for (FloorComponents::FloorTile *tilePtr : floorTiles)
        {
            window.draw(tilePtr->getTileSprite());
        }
    }

    void Floor::loop()
    {
        // BaseEntity::loop();
        Game::isColliding = !Game::isColliding && isColliding();
    }

    void Floor::move(float x, float y) {}

    // TODO: Make this return actual sprite
    sf::Sprite Floor::get()
    {
        sf::Sprite floorSprite;

        floorSprite.setPosition(0.0f, 380.0f);
        return floorSprite;
    }

    namespace FloorComponents
    {
        FloorTile::FloorTile(sf::Sprite tileSprite, FloorVariant type) : tileSprite(tileSprite), type(type) {}

        sf::Sprite &FloorTile::getTileSprite()
        {
            return tileSprite;
        }
    }
}