#include "Player.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams)
{

}

void Player::draw()
{
    SDLGameObject::draw(); // use the base draw function.
}

void Player::update()
{
    m_x -= 1;
    m_currentFrame = int ((SDL_GetTicks() / 100) % 6);
}

void Player::clean()
{

}
