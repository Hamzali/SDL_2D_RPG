#ifndef __Game__
#define __Game__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

#include <iostream>
#include <map>
#include <vector>
#include <utility>

class TextureManager;
class GameStateMachine;
class GameManager;

class Game{

public:
    // Member functions.
    void render();
    void update(int delta);
    void handleEvent();
    void clean();
    void quit();
    bool isRunning() const {return m_bRunning;}

    // Getters and Setters.
    bool init(const char* title, int xpos, int ypos, int height, int width, int flags);
    SDL_Renderer* getRenderer() const {return m_pRenderer;}

    bool assetLoader();
    bool loadTexture(std::string id, std::string ext);
    bool loadSound(std::string id);
    bool loadMusic(std::string id);

    // singleton structure.
    static Game* Instance()
    {
        if(s_pInstance == 0)
            s_pInstance = new Game();

        return s_pInstance;
    }

    GameStateMachine* m_pGameStateMachine;

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

    bool m_bRunning;
    int m_CurrentFrame;

    std::vector<std::string> m_Musics;
    std::vector<std::string> m_Sounds;
    std::vector<std::string> m_Textures;

};

typedef Game TheGame;

#endif
