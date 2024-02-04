#pragma once

#include <SFML/Graphics.hpp>

#include "Entity/BaseEntity.h"

namespace Entity
{
    namespace FloorComponents
    {
        enum FloorVariant
        {
            FLAT,
            DECLINE,
            INCLINE
        };

        class FloorTile
        {
        private:
            sf::Sprite tileSprite;
            FloorVariant type;

        public:
            FloorTile(sf::Sprite tileSprite, FloorVariant type);
            sf::Sprite &getTileSprite();
            FloorVariant getFloorType();
        };

    }

    class Floor : public BaseEntity
    {
    private:
        float xPos, yPos;
        static const int floorCount;
        sf::Clock timer;
        sf::Texture tileTexture;
        FloorComponents::FloorTile *prevTile;
        std::vector<FloorComponents::FloorTile *> floorTiles;
        bool assertProbability(float probability);
        std::vector<FloorComponents::FloorVariant> generateTerrain(int size);
        std::vector<FloorComponents::FloorVariant> generateTerrain();
        void createFloorTile(FloorComponents::FloorVariant floorType);
        void initializeTiles();

    protected:
        bool isColliding();

    public:
        Floor(Actor::MainCharacter &player);
        ~Floor();
        void loop();
        void display(sf::RenderWindow &window);
        void move(float x, float y);
        sf::Sprite get();
    };
}