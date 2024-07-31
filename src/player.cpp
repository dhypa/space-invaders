#include "player.hpp"

Player::Player()
{
    speed = 10;
    shipSprite = LoadTexture("sprites/player.png");
    position.x = (GetScreenWidth() - shipSprite.width) / 2;
    position.y = GetScreenHeight() - shipSprite.height;

    timeSinceLastLaser = 0;
}

Player::~Player()
{
    UnloadTexture(shipSprite);
}

void Player::draw()
{
    DrawTextureV(shipSprite, position, WHITE);
}

void Player::moveRight()
{
    position.x += speed;
    if (position.x > GetScreenWidth() - shipSprite.width)
    {
        position.x = 0;
    }
}

void Player::moveLeft() {
    position.x -= speed;
    if (position.x <= 0)
    {
        position.x = GetScreenWidth() - shipSprite.width;
    }
}

void Player::shootLaser()
{
    if ((GetTime() - timeSinceLastLaser) > 0.4)
    {
        lasers.push_back(Laser({ position.x + (shipSprite.width / 2), position.y - 4 }, 6));
        timeSinceLastLaser = GetTime();
    }
};
