#include <iostream>
#include <cmath>

#include "Entity/Floor.h"
#include "Entity/BaseEntity.h"
#include "Actor/MainCharacter.h"
#include "Game.h"

namespace Entity
{
    const int Floor::floorCount = 20;

    Floor::Floor(Actor::MainCharacter &player) : BaseEntity(player), xPos(0.0f), yPos(380.0f)
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

    bool Floor::assertProbability(float probability)
    {
        float randomValue = static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX);
        return randomValue < probability;
    }

    std::vector<FloorComponents::FloorVariant> Floor::generateTerrain(int size)
    {
        std::vector<FloorComponents::FloorVariant> myTerrain;
        FloorComponents::FloorVariant floorType;
        FloorComponents::FloorVariant prevFloorType = prevTile == nullptr ? FloorComponents::FLAT : prevTile->getFloorType();

        for (int i = size - 1; i >= 0; i--)
        {
            floorType = FloorComponents::FLAT;

            // Decline or Incline
            if (prevFloorType == FloorComponents::DECLINE)
            {
                floorType = FloorComponents::INCLINE;
            }
            else if (assertProbability(0.3f))
            {
                floorType = FloorComponents::DECLINE;
            }

            prevFloorType = floorType;
            myTerrain.push_back(floorType);
        }
        return myTerrain;
    }

    std::vector<FloorComponents::FloorVariant> Floor::generateTerrain()
    {
        return generateTerrain(floorCount);
    }

    void Floor::createFloorTile(FloorComponents::FloorVariant floorType)
    {
        sf::IntRect spriteRegion;

        switch (floorType)
        {
        case FloorComponents::DECLINE:
            spriteRegion = sf::IntRect(64, 32, 45, 44);
            break;
        case FloorComponents::INCLINE:
            spriteRegion = sf::IntRect(96, 32, 45, 44);
            break;
        default:
            spriteRegion = sf::IntRect(3, 0, 45, 44);
            break;
        }

        sf::Sprite floorSprite;
        floorSprite.setTexture(tileTexture);
        floorSprite.setPosition(xPos, yPos);
        floorSprite.setTextureRect(spriteRegion);

        FloorComponents::FloorTile *newTile = new FloorComponents::FloorTile(floorSprite, floorType);

        if (newTile != nullptr)
        {
            prevTile = newTile;
            floorTiles.push_back(newTile);
            xPos += floorSprite.getGlobalBounds().width - 5;
        }
    }

    void Floor::initializeTiles()
    {
        std::vector<FloorComponents::FloorVariant> myTerrain = generateTerrain();

        for (FloorComponents::FloorVariant floorType : myTerrain)
        {
            createFloorTile(floorType);
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

    void Floor::move(float x, float y)
    {
        if (floorTiles.empty() || floorTiles.size() != floorCount)
            return;

        if (timer.getElapsedTime().asSeconds() >= 0.05f)
        {
            timer.restart();

            delete floorTiles.front();
            floorTiles.erase(floorTiles.begin());

            xPos -= 40;
            for (FloorComponents::FloorTile *tilePtr : floorTiles)
            {
                tilePtr->getTileSprite().setPosition((tilePtr->getTileSprite().getPosition().x - 40), tilePtr->getTileSprite().getPosition().y);
            }

            std::vector<FloorComponents::FloorVariant> myTerrain = generateTerrain(1);
            if (!myTerrain.empty())
            {
                createFloorTile((FloorComponents::FloorVariant)myTerrain.front());
            }
        }
    }

    // TODO: Make this return actual sprite
    sf::Sprite Floor::get()
    {
        sf::Sprite floorSprite;

        floorSprite.setPosition(xPos, yPos);
        return floorSprite;
    }

    namespace FloorComponents
    {
        FloorTile::FloorTile(sf::Sprite tileSprite, FloorVariant type) : tileSprite(tileSprite), type(type) {}

        sf::Sprite &FloorTile::getTileSprite()
        {
            return tileSprite;
        }

        FloorVariant FloorTile::getFloorType()
        {
            return type;
        }
    }
}