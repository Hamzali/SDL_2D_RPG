#include "SDLGameObject.h"
#include "Game.h"

SDLGameObject::SDLGameObject(const LoaderParams* pParams) : GameObject(pParams) {

    m_Position.setX(pParams -> getX());
    m_Position.setY(pParams -> getY());

    m_width = pParams -> getWidth();
    m_height = pParams -> getHeight();

    m_textureID = pParams -> getTextureID();

    m_currentRow = 1;
    m_currentFrame = 1;
}

void SDLGameObject::draw()
{
    TextureManager::Instance() -> drawFrame(m_textureID, m_Position.getX(), m_Position.getY(), m_width, m_height,
        m_currentRow, m_currentFrame, Game::Instance() -> getRenderer());
}

void SDLGameObject::update()
{
    m_Position += m_Velocity;
    m_Velocity += m_Accel;

}

void SDLGameObject::clean()
{

}
