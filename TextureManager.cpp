#include "TextureManager.h"

// Makes the class singleton which means it can only have one instance.
TextureManager* TextureManager::s_pInstance = 0;

bool TextureManager::load(std::string fileName, std::string id, SDL_Renderer* pRenderer)
{
    SDL_Surface* pTempSurface = IMG_Load(fileName.c_str());

    if(pTempSurface == NULL)
    {
        std::cout << "Can't load the image." << std::endl;
        return false;
    }

    SDL_Texture* pTexture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
    SDL_FreeSurface(pTempSurface);

    // Save the loaded image in to map.
    if(pTexture != NULL){
        m_TextureMap[id] = pTexture;
        std::cout << "Image loaded!" << std::endl;
        return true;
    }

    std::cout << "Something is wrong!" << std::endl;
    return false;
}

void TextureManager::draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
    SDL_Rect srcRect;
    SDL_Rect destRect;

    srcRect.x = 0;
    srcRect.y = 0;

    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;

    destRect.x = x;
    destRect.y = y;

    SDL_RenderCopyEx(pRenderer, m_TextureMap[id], &srcRect, &destRect, 0, 0, flip);

}

void TextureManager::draw(std::string id, int sx, int sy, int sw, int sh, int dx, int dy, int dw, int dh, SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
    SDL_Rect srcRect;
    SDL_Rect destRect;

    srcRect.x = sx;
    srcRect.y = sy;

    srcRect.w = sw;
    destRect.w = dw;
    srcRect.h = sh;
    destRect.h = dh;

    destRect.x = dx;
    destRect.y = dy;

    SDL_RenderCopyEx(pRenderer, m_TextureMap[id], &srcRect, &destRect, 0, 0, flip);

}

void TextureManager::drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
    SDL_Rect srcRect;
    SDL_Rect destRect;

    srcRect.x = currentFrame * width;
    srcRect.y = (currentRow - 1) * height;

    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;

    destRect.x = x;
    destRect.y = y;

    SDL_RenderCopyEx(pRenderer, m_TextureMap[id], &srcRect, &destRect, 0, 0, flip);
}


void TextureManager::drawFrame(std::string id, int sx, int sy, int sw, int sh, int dx, int dy, int dw, int dh, double angle, int currentRow, int currentFrame, int cx, int cy, SDL_Renderer* pRenderer, SDL_RendererFlip flip) {
    SDL_Rect srcRect;
    SDL_Rect destRect;
    SDL_Point center;
    center.x = cx;
    center.y = cy;

    srcRect.x = sx+currentFrame * sw;
    srcRect.y = sy+(currentRow - 1) * sh;

    srcRect.w = sw;
    destRect.w = dw;
    srcRect.h = sh;
    destRect.h = dh;

    destRect.x = dx;
    destRect.y = dy;

    SDL_RenderCopyEx(pRenderer, m_TextureMap[id], &srcRect, &destRect, angle, (cx == -1) ? 0 : &center, flip);
}
