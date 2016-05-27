#include "TextureManager.h"
#include "AudioManager.h"
#include "GameStateMachine.h"
#include "GameManager.h"
#include "InputHandler.h"

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

                    if(!TheAudioManager::Instance() -> init()){
                        return false;
                    }

                    if(!assetLoader()){
                            std::cout << "Asset error!" << std::endl;
                            return false;
                    }

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
    m_bRunning = true; // start the main loop

    // -----YOUR GAME VARS
    m_pGameStateMachine = new GameStateMachine();
    //m_pGameStateMachine -> changeState(new MenuState());


    // ~~~~~
    return true;

}
void Game::render() {
    // Clear the screen.
    SDL_SetRenderDrawColor( getRenderer(), 11, 33, 77, 0xFF );
    SDL_RenderClear(m_pRenderer);

    m_pGameStateMachine -> render();

    // Draw color to the screen.
    SDL_RenderPresent(m_pRenderer);

}

void Game::update(int delta)
{
    // in every 100 mili seconds change the frame.
    m_pGameStateMachine -> update(delta);

}

void Game::handleEvent()
{
    TheInputHandler::Instance() -> update();
}

void Game::quit()
{
    m_bRunning = false;

    Mix_CloseAudio();
    Mix_Quit();
    SDL_Quit();
}


void Game::clean()
{

    std::cout << "Cleaning the game!" << std::endl;
    TheInputHandler::Instance() -> clean();

    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    for(int i = 0; i < (int)m_Musics.size(); i++){
        TheAudioManager::Instance() -> freeMusic(m_Musics[i]);
    }

    for(int i = 0; i < (int)m_Sounds.size(); i++){
        TheAudioManager::Instance() -> freeSound(m_Sounds[i]);
    }

}

bool Game::loadTexture(std::string id, std::string ext)
{
    m_Textures.push_back(id);
    // Our instance of TextureManager class, loads the image.
    if(!TextureManager::Instance() -> load("assets/textures/" + id + "." + ext, id, m_pRenderer)){
        std::cout << "Can't load the texture." << std::endl;
        return false;
    }
    return true;
}

bool Game::loadSound(std::string id)
{
    m_Sounds.push_back(id);
    if(!TheAudioManager::Instance() -> loadSoundEffect("assets/sounds/" + id + ".wav", id))
        return false;

    return true;
}

bool Game::loadMusic(std::string id)
{
    m_Musics.push_back(id);
    //Test music.
    if(!TheAudioManager::Instance() -> loadMusic("assets/musics/" + id + ".mp3", id)){
        std::cout << "Can't load the music." << std::endl;
        return false;
    }
    return true;
}

// Add your assets through this function.
bool Game::assetLoader(){
    return loadTexture("man", "png") //&&
    ;
}
