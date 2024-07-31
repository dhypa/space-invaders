#include "laser.hpp"

Laser::Laser(Vector2 position, int speed)
{

    this->position = position;
    this->speed = speed;
    lasersprite = LoadTexture("sprites/laser.png");
    alive = true;
}

Laser::~Laser()
{
}

void Laser::draw()
{
    if (alive)
    {
        DrawTextureV(lasersprite, position, WHITE);
    }
}

void Laser::update()
{
    position.y -= speed;
    if (alive)
    {
        if (0 > position.y || position.y > GetScreenHeight())
        {
            alive = false;
        }
    }
}
