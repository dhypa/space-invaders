#pragma once
#include <raylib.h>
#include "player.hpp"

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
};