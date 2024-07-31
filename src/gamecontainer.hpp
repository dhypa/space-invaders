#pragma once
#include <raylib.h>
#include "player.hpp"
#include "obstable.hpp"
#include "invader.hpp"

class GameContainer
{
public:
    GameContainer();
    ~GameContainer();
    void draw();
    void update();
    void handleInput();
    void deleteInactiveLasers();

private:
    Player player;
    std::vector<Obstacle> createObstacles();
    std::vector<Obstacle> obstacles;
    std::vector<Invader> invaders;
    std::vector<Invader> createInvaders();
};
