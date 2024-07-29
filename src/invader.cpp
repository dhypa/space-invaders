#include "invader.hpp"

Invader::Invader(int x, int y)
{
    shipSprite = LoadTexture("sprites/invader.png");
    position.x = 100;
    position.y = 100;
}

Invader::~Invader()
{
    UnloadTexture(shipSprite);
}

void Invader::draw()
{
    DrawTextureV(shipSprite, position, GREEN);
}
