#ifndef __Game__
#define __Game__

#include <SDL2/SDL.h>
#include<SDL2/SDL_image.h>

#include <iostream>
#include <map>
#include <vector>

#include "TextureManager.h"
#include "Player.h"
#include "Enemy.h"

class Game{

public:

    bool init(const char* title, int xpos, int ypos, int height, int width, int flags);

    void render();
    void update();
    void handleEvent();
    void clean();
    bool isRunnig() const {return m_bRunnig;}
    SDL_Renderer* getRenderer() const {return m_pRenderer;}

    // singleton structure.
    static Game* Instance()
    {
        if(s_pInstance == 0){
            s_pInstance = new Game();
            return s_pInstance;
        }

        return s_pInstance;
    }

private:
    Game(){}
    static Game* s_pInstance;
    ~Game();

    SDL_Window* m_pWindow;
    SDL_Renderer* m_pRenderer;

    // Texture and image variables.
    SDL_Texture* m_pTexture;
    SDL_Rect src_Rect;
    SDL_Rect dest_Rect;

    bool m_bRunnig;
    int m_CurrentFrame;

    std::vector<GameObject*> m_gameobjects;
};

#endif
