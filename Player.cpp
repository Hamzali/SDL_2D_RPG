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
    m_currentFrame = int ((SDL_GetTicks() / 100) % 6);

    SDLGameObject::update();
}

void Player::clean()
{

}
