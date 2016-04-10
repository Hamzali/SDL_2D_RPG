#ifndef __TEXTURE_MANAGER__
#define __TEXTURE_MANAGER__

#include <SDL2/SDL.h>
#include<SDL2/SDL_image.h>

#include <iostream>
#include <map>

// A singleton class.
class TextureManager{
    public:
        bool load(std::string fileName, std::string id, SDL_Renderer* pRenderer);

        void draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

        void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

        // check wheter is it constructor before than contructs.
        static TextureManager* Instance()
        {
            if(s_pInstance == 0)
            {
                s_pInstance = new TextureManager();
                return s_pInstance;
            }

            return s_pInstance;

        }



    private:
        // To secure the class for costructing somewhere else.
        TextureManager(){}

        // For making this class can be accessable without contructing.
        static TextureManager* s_pInstance;

        std::map<std::string, SDL_Texture*> m_TextureMap;
};
#endif
