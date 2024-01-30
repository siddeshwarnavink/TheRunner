#pragma once

#include <memory>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "Actor/MainCharacter.h"
#include "Entity/Obstacle/BaseObstacle.h"
#include "Entity/Floor.h"

namespace Generator
{
    class Generator
    {
    private:
        sf::Clock clock;
        sf::Time elapsedTime;
        static sf::Time interval;
        void generateObstacle();

    protected:
        sf::RenderWindow &window;
        std::vector<Entity::Obstacle::BaseObstacle *> obstacleList;
        Actor::MainCharacter &mainCharacter;
        Entity::Floor &floor;
        virtual Entity::Obstacle::BaseObstacle *generate(float xPos, float yPos);

    public:
        Generator(sf::RenderWindow &window, Actor::MainCharacter &mainCharacter, Entity::Floor &floor);
        ~Generator();
        void loop();
        void display();
        void move(float x, float y);
    };
};