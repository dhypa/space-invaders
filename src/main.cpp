#include <raylib.h>
#include "invader.hpp"
#include "player.hpp"
#include "gamecontainer.hpp"
#include "laser.hpp"

int main()
{
    const int screenWidth = 700;
    const int screenHeight = 600;

    Color bgColour = {0, 0, 0, 255}; // black

    InitWindow(screenWidth, screenHeight, "Space Invaders");
    SetTargetFPS(20);
    GameContainer game;
    Invader invader(1, 2);
    Vector2 pos = {300, 200};

    Laser *laser = new Laser(pos, 4);

    do
    {
        (*laser).update();
        game.update();
        game.handleInput();

        BeginDrawing();

        ClearBackground(bgColour);
        game.draw();
        invader.draw();
        (*laser).draw();

        EndDrawing();

    } while (!0);
    CloseWindow();
}