#include "Game.h"

Game* Game::s_pInstance = 0;

bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags)
{
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){

            std::cout << "SDL Initialized successfully" << std::endl;
            // init the sdl window
            m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

            // Woindow created
            if(m_pWindow != 0){

                    // init the sdl render
                    std::cout << "Window created!" << std::endl;
                    m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0); // why -1 and 0?

                    if(m_pRenderer != 0){

                        std::cout << "Renderer created!" << std::endl;
                        SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255); // renderer and RGBA

                        // Our instance of TextureManager class, loads the image.
                        if(!TextureManager::Instance() -> load("assets/man.png", "man", m_pRenderer)){
                            std::cout << "Can't load the texture." << std::endl;
                            return false;
                        }

                        // load the game objects.
                        m_gameobjects.push_back(new Enemy(new LoaderParams(0, 0, 104, 156, "man")));
                        m_gameobjects.push_back(new Player(new LoaderParams(100, 100, 104, 156, "man")));

                    }else{

                        std::cout << "Renderer init failed!" << std::endl;
                        return false;
                    }

            }else{
                std::cout << "Window init failed!" << std::endl;
                return false;
            }
    }else{
        std::cout << "SDL init failed!" << std::endl;
        return false;
    }

    std::cout << "Everything is just fine go on!" << std::endl;
    m_bRunnig = true; // start the main loop

    return true;

}

void Game::render()
{
    // Clear the screen.
    SDL_RenderClear(m_pRenderer);

    int size = m_gameobjects.size();
    for(int i = 0; i < size; i++){
        m_gameobjects[i] -> draw();
    }
    // Draw color to the screen.
    SDL_RenderPresent(m_pRenderer);

}

void Game::update()
{

        // in every 100 mili seconds change the frame.
        int size = m_gameobjects.size();
        for(int i = 0; i < size; i++){
            m_gameobjects[i] -> update();
        }

}

void Game::handleEvent()
{
    SDL_Event event;
    if(SDL_PollEvent(&event)){

        switch (event.type) {
            case SDL_QUIT:
                m_bRunnig = false;
                break;
            default:
                break;
        }
    }
}


void Game::clean()
{
    std::cout << "Cleaning the game!" << std::endl;
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}
