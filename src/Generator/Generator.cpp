#include <random>
#include <stack>

#include "Generator/Generator.h"

namespace Generator
{
    sf::Time Generator::interval = sf::seconds(1.0f);

    Generator::Generator(Actor::MainCharacter &player, Entity::Floor &floor, sf::RenderWindow &window) : player(player),
                                                                                                         floor(floor),
                                                                                                         window(window),
                                                                                                         spawningProbability(1.0f)
    {
    }

    Generator::~Generator()
    {
        for (Entity::Obstacle::BaseObstacle *obstaclePtr : obstacleList)
        {
            delete obstaclePtr;
        }
        obstacleList.clear();
    }

    Entity::Obstacle::BaseObstacle *Generator::generate(float xPos, float yPos)
    {
        return nullptr;
    }

    void Generator::generateObstacle()
    {
        float minX = player.getPosition().x + 500.0f;
        float maxX = minX + 100.0f;

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<float> Xdist(minX, maxX);

        float randomX = Xdist(gen);

        Entity::Obstacle::BaseObstacle *obstacle = generate(randomX, player.initialPosition.y + player.getGlobalBounds().height - 30.0f);
        if (obstacle)
        {
            obstacleList.push_back(obstacle);
        }
    }

    void Generator::loop()
    {
        std::stack<int> entityToRemove;

        for (size_t i = 0; i < obstacleList.size(); ++i)
        {
            Entity::Obstacle::BaseObstacle *obstaclePtr = obstacleList[i];

            if (obstaclePtr && abs(obstaclePtr->getSprite().getPosition().x - player.getPosition().x) > 666)
            {
                entityToRemove.push(i);
            }

            else if (obstaclePtr)
            {
                obstaclePtr->loop();
            }
        }

        while (!entityToRemove.empty())
        {
            delete obstacleList[entityToRemove.top()];
            obstacleList.erase(obstacleList.begin() + entityToRemove.top());

            entityToRemove.pop();
        }

        elapsedTime = clock.getElapsedTime();
        if (elapsedTime >= interval)
        {
            if (player.getState() != Actor::DEAD)
            {
                float randomValue = static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX);
                if (randomValue < spawningProbability)
                {
                    generateObstacle();
                }
            }
            clock.restart();
        }
    }

    void Generator::display()
    {
        for (Entity::Obstacle::BaseObstacle *obstaclePtr : obstacleList)
        {
            obstaclePtr->display(window);
        }
    }

    void Generator::move(float x, float y)
    {
        for (Entity::Obstacle::BaseObstacle *obstaclePtr : obstacleList)
        {
            obstaclePtr->move(x, y);
        }
    }

    void Generator::setSpawningProbability(float probability)
    {
        spawningProbability = probability;
    }
}