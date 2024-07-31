#include <raylib.h>
#include "invader.hpp"
#include "player.hpp"
#include "gamecontainer.hpp"
#include "laser.hpp"

int main() {
    const int screenWidth = 700;
    const int screenHeight = 600;


    InitWindow(screenWidth, screenHeight, "Space Invaders");
    SetTargetFPS(60);

    GameContainer game;



    while (true) {
        game.update();
        game.handleInput();
        BeginDrawing();
        ClearBackground(BLACK);
        game.draw();
        EndDrawing();


    }
    CloseWindow();
}
