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
    handleInput();
    SDLGameObject::update();
}

void Player::handleInput(){
    //if(TheInputHandler::Instance()->getMouseButtonState(0))std::cout << "INPUT WORKED!" << std::endl;
    //std::cout << SDLK_UP << std::endl;
    if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))std::cout << "UP pressed!" << std::endl;
}

void Player::clean()
{

}
