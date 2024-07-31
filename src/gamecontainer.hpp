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


private:
    Player player;
    std::vector<Obstacle> createObstacles();
    std::vector<Obstacle> obstacles;
    std::vector<Invader> invaders;
    std::vector<Invader> createInvaders();
    void deleteInactiveLasers();
    void moveInvaders();
    void moveDownInvaders(int displacement);
    int invaderDirection;
    std::vector<Laser> invaderLasers;
    void fireInvaderLaser();
    constexpr static float invaderFireLaserInterval = 0.15;
    float timeSinceLastInvaderFired;
};
