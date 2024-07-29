#include <raylib.h>
#include "player.hpp"
#include "gamecontainer.hpp"
#include <iostream>

GameContainer::GameContainer()
{
}
GameContainer::~GameContainer()
{
}
void GameContainer::draw()
{
    player.draw();
    for (Laser laser : player.lasers)
    {
        laser.draw();
    };
}

void GameContainer::handleInput()
{
    if (IsKeyDown(KEY_SPACE))
    {
        player.shootLaser();
    }
    else if (IsKeyDown(KEY_LEFT))
    {
        player.moveLeft();
    }
    else if (IsKeyDown(KEY_RIGHT))
    {
        player.moveRight();
    }
}

void GameContainer::deleteInactiveLasers()
{
    for (auto it = player.lasers.begin(); it != player.lasers.end();)
    {
        if (!it->alive)
        {
            it = player.lasers.erase(it);
        }
        else
        {
            ++it;
        }
    };
}

void GameContainer::update()
{
    for (Laser &laser : player.lasers)
    {
        laser.update();
    };
    deleteInactiveLasers();
    std::cout << "Vector Size:" << player.lasers.size() << std::endl;
}
