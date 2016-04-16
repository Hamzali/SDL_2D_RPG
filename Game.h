#ifndef __Game__
#define __Game__

#include <SDL2/SDL.h>
#include<SDL2/SDL_image.h>

#include <iostream>
#include <map>
#include <vector>
#include <utility>

#include "TextureManager.h"
#include "Player.h"
#include "Enemy.h"

class Game{

public:


    // Member functions.
    void render();
    void update();
    void handleEvent();
    void clean();
    void quit();
    bool isRunnig() const {return m_bRunnig;}

    // Getters and Setters.
    bool init(const char* title, int xpos, int ypos, int height, int width, int flags);
    SDL_Renderer* getRenderer() const {return m_pRenderer;}

    // singleton structure.
    static Game* Instance()
    {
        if(s_pInstance == 0)
            s_pInstance = new Game();

        return s_pInstance;
    }

private:
    Game(){}
    ~Game();
    static Game* s_pInstance;

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

typedef Game TheGame;

#endif
